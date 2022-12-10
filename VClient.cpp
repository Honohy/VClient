#pragma comment(lib, "ws2_32.lib")
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <WinSock2.h>
#include <iostream>

int main(int argc, char* argv[])
{

    WSADATA wsaData;
    WORD DlLLVerstion = MAKEWORD(2,1);
    if (WSAStartup(DlLLVerstion,&wsaData)!= 0)
    {
        std::cout << "Error lib loading" << std::endl;
        exit(1);
    }
    
    SOCKADDR_IN addr;
    int sizeofaddr = sizeof addr;
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    addr.sin_port = htons(1111);
    addr.sin_family = AF_INET;
    
    SOCKET Connection = socket(AF_INET,SOCK_STREAM,NULL);
    if (connect(Connection, (SOCKADDR*)&addr, sizeof addr) !=0)
    {
        std::cout << "Error failed connection" << std::endl;
        return 1;
    }
    
    std::cout << "Connection succes! \n";

    char ReceivedMessage[256];
    recv(Connection,ReceivedMessage,sizeof(ReceivedMessage),NULL);
    std::cout << (std::string) ReceivedMessage << std::endl;
    
    return 0;
}