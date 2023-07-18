#include <iostream>
#include <vector>
#include <WinSock2.h>
#include <ws2tcpip.h>
#include <thread>
#include <mutex>

#pragma comment(lib, "ws2_32.lib")

struct Vector3
{
    float x;
    float y;
    float z;
};

struct ClientData
{
    SOCKET socket;
    Vector3 location;
};

std::vector<ClientData> clients;
std::mutex clientsMutex;

void ClientHandler(SOCKET clientSocket)
{
    Vector3 initialLocation{ 0.0f, 0.0f, 0.0f };

    ClientData clientData;
    clientData.socket = clientSocket;
    clientData.location = initialLocation;

    std::lock_guard<std::mutex> lock(clientsMutex);
    clients.push_back(clientData);

    while (true)
    {
        // Receive movement input from the client
        Vector3 newLocation;
        int bytesReceived = recv(clientSocket, reinterpret_cast<char*>(&newLocation), sizeof(Vector3), 0);
        if (bytesReceived == SOCKET_ERROR || bytesReceived == 0)
        {
            // Client disconnected
            std::lock_guard<std::mutex> lock(clientsMutex);
            auto it = std::find_if(clients.begin(), clients.end(), [&](const ClientData& client) {
                return client.socket == clientSocket;
                });
            if (it != clients.end())
            {
                clients.erase(it);
            }
            break;
        }

        // Update the client's location in the server's game state
        std::lock_guard<std::mutex> lock(clientsMutex);
        auto it = std::find_if(clients.begin(), clients.end(), [&](const ClientData& client) 
            {
            return client.socket == clientSocket;
            });
        if (it != clients.end())
        {
            it->location = newLocation;
        }

        // Broadcast the updated player locations to all connected clients
        std::lock_guard<std::mutex> lock(clientsMutex);
        for (const ClientData& client : clients)
        {
            if (client.socket != clientSocket)
            {
                send(client.socket, reinterpret_cast<char*>(&clientData), sizeof(ClientData), 0);
            }
        }
    }

    closesocket(clientSocket);
}

int main()
{
    // Initialize Winsock
    WSADATA wsData;
    WORD ver = MAKEWORD(2, 2);
    int wsResult = WSAStartup(ver, &wsData);
    if (wsResult != 0)
    {
        std::cerr << "Can't initialize Winsock!" << std::endl;
        return -1;
    }

    // Create a socket for listening
    SOCKET listening = socket(AF_INET, SOCK_STREAM, 0);
    if (listening == INVALID_SOCKET)
    {
        std::cerr << "Can't create a socket!" << std::endl;
        WSACleanup();
        return -1;
    }

    // Bind the socket to an IP address and port
    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(54000);
    hint.sin_addr.S_un.S_addr = INADDR_ANY;
    bind(listening, (sockaddr*)&hint, sizeof(hint));

    // Tell Winsock the socket is for listening
    listen(listening, SOMAXCONN);

    // Accept client connections in separate threads
    std::vector<std::thread> clientThreads;

    while (true)
    {
        // Accept a new client connection
        sockaddr_in client;
        int clientSize = sizeof(client);
        SOCKET clientSocket = accept(listening, (sockaddr*)&client, &clientSize);

        // Start a new thread to handle the client
        std::thread thread(ClientHandler, clientSocket);
        clientThreads.push_back(std::move(thread));
    }

    // Close the listening socket
    closesocket(listening);

    // Wait for all client threads to finish
    for (auto& thread : clientThreads)
    {
        if (thread.joinable())
            thread.join();
    }

    // Cleanup Winsock
    WSACleanup();

    return 0;
}