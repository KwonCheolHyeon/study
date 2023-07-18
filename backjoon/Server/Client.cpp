#include <iostream>
#include <WS2tcpip.h>
#include <string>

#pragma comment(lib, "ws2_32.lib")

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
    SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == INVALID_SOCKET)
    {
        std::cerr << "Can't create a socket!" << std::endl;
        WSACleanup();
        return -1;
    }

    // Connect to the server
    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(54000);// 호스트의 포트번와 같아야한다.
    inet_pton(AF_INET, "127.0.0.1", &(hint.sin_addr)); // Replace with the server's IP address

    int connResult = connect(sock, (sockaddr*)&hint, sizeof(hint));
    if (connResult == SOCKET_ERROR)
    {
        std::cerr << "Can't connect to the server!" << std::endl;
        closesocket(sock);
        WSACleanup();
        return -1;
    }

    // Do-while loop to send and receive data
    char buf[4096];
    std::string userInput;

    do
    {
        // Prompt the user for some text
        std::cout << "> ";
        std::getline(std::cin, userInput);

        // Send the text
        if (userInput.size() > 0) // Make sure the user has typed something
        {
            int sendResult = send(sock, userInput.c_str(), userInput.size() + 1, 0);
            if (sendResult != SOCKET_ERROR)
            {
                // Wait for response
                ZeroMemory(buf, 4096);
                int bytesReceived = recv(sock, buf, 4096, 0);
                if (bytesReceived > 0)
                {
                    // Echo response to console
                    std::cout << "SERVER> " << std::string(buf, 0, bytesReceived) << std::endl;
                }
            }
        }
    } while (userInput.size() > 0);

    // Gracefully close down everything
    closesocket(sock);
    WSACleanup();

    return 0;
}