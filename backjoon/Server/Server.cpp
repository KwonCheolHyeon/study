#include <iostream>
#include <WinSock2.h>
#include <ws2tcpip.h>
#include <vector>
#include <thread>

#pragma comment(lib, "ws2_32.lib")

// Function to handle each client connection
void ClientHandler(SOCKET clientSocket)
{
    char buf[4096];

    while (true)
    {
        ZeroMemory(buf, 4096);

        // Wait for client to send data
        int bytesReceived = recv(clientSocket, buf, 4096, 0);
        if (bytesReceived == SOCKET_ERROR)
        {
            std::cerr << "Error in recv(). Quitting" << std::endl;
            break;
        }

        if (bytesReceived == 0)
        {
            std::cout << "Client disconnected" << std::endl;
            break;
        }

        // Display received message from the client
        std::cout << "Client> " << buf << std::endl;

        // Send response back to the client
        int sendResult = send(clientSocket, buf, bytesReceived, 0);
        if (sendResult == SOCKET_ERROR)
        {
            std::cerr << "Error in send(). Quitting" << std::endl;
            break;
        }
    }

    // Close the socket
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

    // Create a socket
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

    std::vector<std::thread> clientThreads;

    // Wait for client connections
    while (true)
    {
        // Accept a new client connection
        sockaddr_in client;
        int clientSize = sizeof(client);
        SOCKET clientSocket = accept(listening, (sockaddr*)&client, &clientSize);

        char host[NI_MAXHOST];      // Client's remote name
        char service[NI_MAXSERV];   // Service (i.e., port) the client is connected on

        ZeroMemory(host, NI_MAXHOST);
        ZeroMemory(service, NI_MAXSERV);

        if (getnameinfo((sockaddr*)&client, sizeof(client), host, NI_MAXHOST, service, NI_MAXSERV, 0) == 0)
        {
            std::cout << "Connected to client: " << host << " on port " << service << std::endl;
        }
        else
        {
            inet_ntop(AF_INET, &(client.sin_addr), host, NI_MAXHOST);
            std::cout << "Connected to client: " << host << " on port " << ntohs(client.sin_port) << std::endl;
        }

        // Create a thread to handle the client
        std::thread thread(ClientHandler, clientSocket);

        // Detach the thread (allow it to run independently)
        thread.detach();

        // Store the thread in a vector
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
