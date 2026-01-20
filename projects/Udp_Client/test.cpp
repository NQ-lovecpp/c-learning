#include <iostream>  
#include <string>  
#include <cstring>  
#include <winsock2.h>  
#include <ws2tcpip.h>

#pragma comment(lib, "ws2_32.lib")  

void Usage(const char* process)
{
    std::cout << "Usage : \n\t" << process << "server_ip local_port\n"
        << std::endl;
}

int main(int argc, char* argv[])
{
    WSADATA wsaData;
    int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (result != 0) {
        std::cerr << "WSAStartup failed with error: " << result << std::endl;
        return 1;
    }

    std::string serverip = "139.196.238.17";
    uint16_t serverport = 9999;

    // 1. 创建socket  
    SOCKET sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (sock == INVALID_SOCKET)
    {
        std::cerr << "socket error: " << WSAGetLastError() << std::endl;
        WSACleanup();
        return 2;
    }

    // 2. 填充一下server信息  
    sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(serverport);
    if (inet_pton(AF_INET, serverip.c_str(), &server.sin_addr) <= 0)
    {
        std::cerr << "Invalid address/ Address not supported" << std::endl;
        closesocket(sock);
        WSACleanup();
        return 3;
    }

    char buffer[1024];
    sockaddr_in from;
    int fromlen = sizeof(from);

    while (true)
    {
        // 我们要发的数据  
        std::cout << "Please Enter# ";
        std::cin.getline(buffer, sizeof(buffer));

        // 发给谁？server  
        int n = sendto(sock, buffer, strlen(buffer), 0, (sockaddr*)&server, sizeof(server));
        if (n < 0)
        {
            std::cerr << "sendto failed with error: " << WSAGetLastError() << std::endl;
            break;
        }

        // 收消息  
        int m = recvfrom(sock, buffer, sizeof(buffer) - 1, 0, (sockaddr*)&from, &fromlen);
        if (m > 0)
        {
            buffer[m] = '\0';
            std::cout << "server echo# " << buffer << std::endl;
        }
        else
        {
            std::cerr << "recvfrom failed with error: " << WSAGetLastError() << std::endl;
            break;
        }
    }

    closesocket(sock);
    WSACleanup();
    return 0;
}


//#include <iostream>
//using namespace std;
//
//void func(int a = 2, int b = 3);
//
//void func(int i)
//{
//	cout << i << endl;
//}
//
//int main()
//{
//	func();
//	return 0;
//}

