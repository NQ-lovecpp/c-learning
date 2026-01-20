//#include <iostream>
//#include <string>
//#include <WS2tcpip.h> // Winsock library
//#include <thread>
//
//#pragma comment(lib, "ws2_32.lib")
//
//void ReceiverRoutine(SOCKET sockfd)
//{
//    while (true)
//    {
//        char buffer[4096];
//        sockaddr_in serverAddr;
//        int serverAddrLen = sizeof(serverAddr);
//        int bytesReceived = recvfrom(sockfd, buffer, sizeof(buffer), 0, (sockaddr*)&serverAddr, &serverAddrLen);
//        if (bytesReceived == SOCKET_ERROR)
//        {
//            std::cerr << "recvfrom() failed: " << WSAGetLastError() << std::endl;
//            break;
//        }
//        buffer[bytesReceived] = '\0';
//        std::cout << "Server: " << buffer << std::endl;
//    }
//}
//
//void SenderRoutine(SOCKET sockfd, const sockaddr_in& serverAddr)
//{
//    while (true)
//    {
//        std::string input;
//        std::getline(std::cin, input);
//
//        int bytesSent = sendto(sockfd, input.c_str(), input.size(), 0, (const sockaddr*)&serverAddr, sizeof(serverAddr));
//        if (bytesSent == SOCKET_ERROR)
//        {
//            std::cerr << "sendto() failed: " << WSAGetLastError() << std::endl;
//            break;
//        }
//    }
//}
//
//int main(int argc, char* argv[])
//{
//    std::string serverIP = "139.196.238.17";
//    int serverPort = 8888;
//
//    // Initialize Winsock
//    WSADATA wsData;
//    WORD ver = MAKEWORD(2, 2);
//    int wsOK = WSAStartup(ver, &wsData);
//    if (wsOK != 0)
//    {
//        std::cerr << "Can't initialize Winsock! Quitting" << std::endl;
//        return 1;
//    }
//
//    // Create a socket
//    SOCKET sockfd = socket(AF_INET, SOCK_DGRAM, 0);
//    if (sockfd == INVALID_SOCKET)
//    {
//        std::cerr << "Can't create socket! Quitting" << std::endl;
//        WSACleanup();
//        return 1;
//    }
//
//    // Fill in the server address structure
//    sockaddr_in serverAddr;
//    serverAddr.sin_family = AF_INET;
//    serverAddr.sin_port = htons(serverPort);
//    inet_pton(AF_INET, serverIP.c_str(), &serverAddr.sin_addr);
//
//    std::thread receiverThread(ReceiverRoutine, sockfd);
//    std::thread senderThread(SenderRoutine, sockfd, std::ref(serverAddr));
//
//    receiverThread.join();
//    senderThread.join();
//
//    // Cleanup Winsock
//    closesocket(sockfd);
//    WSACleanup();
//
//    return 0;
//}


#include <iostream>
#include <string>
#include <WS2tcpip.h> // Winsock library
#include <thread>
#include <mutex>
#include <deque>

#pragma comment(lib, "ws2_32.lib")

void ReceiverRoutine(SOCKET sockfd, std::deque<std::string>& messageQueue, std::mutex& mtx)
{
    while (true)
    {
        char buffer[4096];
        sockaddr_in serverAddr;
        int serverAddrLen = sizeof(serverAddr);
        int bytesReceived = recvfrom(sockfd, buffer, sizeof(buffer), 0, (sockaddr*)&serverAddr, &serverAddrLen);
        if (bytesReceived == SOCKET_ERROR)
        {
            std::cerr << "recvfrom() failed: " << WSAGetLastError() << std::endl;
            break;
        }
        buffer[bytesReceived] = '\0';

        std::string receivedMessage = buffer;

        // Lock the mutex before modifying the message queue
        std::lock_guard<std::mutex> lock(mtx);
        messageQueue.push_back(receivedMessage);
    }
}

void DisplayMessages(std::deque<std::string>& messageQueue, std::mutex& mtx)
{
    while (true)
    {
        // Lock the mutex before accessing the message queue
        std::lock_guard<std::mutex> lock(mtx);

        // Display all messages in the queue
        while (!messageQueue.empty())
        {
            std::cout << "Server: " << messageQueue.front() << std::endl;
            messageQueue.pop_front();
        }
    }
}

void SenderRoutine(SOCKET sockfd, const sockaddr_in& serverAddr)
{
    while (true)
    {
        std::string input;
        std::getline(std::cin, input);

        int bytesSent = sendto(sockfd, input.c_str(), input.size(), 0, (const sockaddr*)&serverAddr, sizeof(serverAddr));
        if (bytesSent == SOCKET_ERROR)
        {
            std::cerr << "sendto() failed: " << WSAGetLastError() << std::endl;
            break;
        }
    }
}

int main(int argc, char* argv[])
{
    std::string serverIP = "139.196.238.17";
    int serverPort = 8888;

    // Initialize Winsock
    WSADATA wsData;
    WORD ver = MAKEWORD(2, 2);
    int wsOK = WSAStartup(ver, &wsData);
    if (wsOK != 0)
    {
        std::cerr << "Can't initialize Winsock! Quitting" << std::endl;
        return 1;
    }

    // Create a socket
    SOCKET sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == INVALID_SOCKET)
    {
        std::cerr << "Can't create socket! Quitting" << std::endl;
        WSACleanup();
        return 1;
    }

    // Fill in the server address structure
    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(serverPort);
    inet_pton(AF_INET, serverIP.c_str(), &serverAddr.sin_addr);

    // Start receiver thread
    std::deque<std::string> messageQueue;
    std::mutex messageQueueMutex;
    std::thread receiverThread(ReceiverRoutine, sockfd, std::ref(messageQueue), std::ref(messageQueueMutex));

    // Start display thread
    std::thread displayThread(DisplayMessages, std::ref(messageQueue), std::ref(messageQueueMutex));

    // Start sender routine
    SenderRoutine(sockfd, serverAddr);

    // Join threads
    receiverThread.join();
    displayThread.join();

    // Cleanup Winsock
    closesocket(sockfd);
    WSACleanup();

    return 0;
}
