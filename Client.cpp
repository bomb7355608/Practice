    #include <stdio.h>
    #include <stdlib.h>
    #include <WinSock2.h>
    #pragma comment(lib, "ws2_32.lib")  //╪сть ws2_32.dll
    int main(){
        WORD sockVersion = MAKEWORD(2,2);
    WSADATA data; 
    if(WSAStartup(sockVersion, &data) != 0)
    {
        return 0;
    }

    SOCKET sclient = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(sclient == INVALID_SOCKET)
    {
        printf("invalid socket !");
        return 0;
    }

    sockaddr_in serAddr;
    serAddr.sin_family = AF_INET;
    serAddr.sin_port = htons(8888);
    serAddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1"); 
    if (connect(sclient, (sockaddr *)&serAddr, sizeof(serAddr)) == SOCKET_ERROR)
    {
        printf("connect error !");
        closesocket(sclient);
        return 0;
    }
    printf("Connect to 127.0.0.1\n");
    char sendData[20];
    gets(sendData);
    send(sclient, sendData, strlen(sendData), 0);

    char recData[255];
    int ret = recv(sclient, recData, 255, 0); 
    if(ret > 0)
    {
        recData[ret] = 0x00;
        printf("Server: %s",recData);
    }
    closesocket(sclient);
    WSACleanup();
    getchar();
    return 0;
    }
