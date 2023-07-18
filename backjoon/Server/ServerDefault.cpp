#include <iostream>
#include <WinSock2.h>
#include <ws2tcpip.h>

#pragma comment(lib, "ws2_32.lib")

int main()
{
    // Initialize Winsock
    WSADATA wsData;
    WORD ver = MAKEWORD(2, 2);
    int wsResult = WSAStartup(ver, &wsData);//초기화
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
    listen(listening, SOMAXCONN);//들어오면 자동으로 정렬해놓음

    ///여기 까지가 서버가 준비해야할 것들 

    //밑에 부터 클라이언트 접속시 발생하는 일들

        // Wait for a connection
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

    // Close listening socket
    closesocket(listening);//

    // Chat loop: receive and send messages
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

        // Prompt server for a response
        std::cout << "Server> ";
        std::cin.getline(buf, 4096);

        // Send response back to the client
        int sendResult = send(clientSocket, buf, strlen(buf), 0);
        if (sendResult == SOCKET_ERROR)
        {
            std::cerr << "Error in send(). Quitting" << std::endl;
            break;
        }
    }

    // Close the socket
    closesocket(clientSocket);

    // Cleanup Winsock
    WSACleanup();

    return 0;
}
