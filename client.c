#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 4404

void main(int argc,char* argv[]){

        int clientSocket;
        struct sockaddr_in serverAddr;
        char buffer[1024],g2[100];

        clientSocket = socket(AF_INET, SOCK_STREAM, 0);
        printf("Client Socket Created Sucessfully...\n");

        memset(&serverAddr, '\0', sizeof(serverAddr));
        serverAddr.sin_family = AF_INET;
        serverAddr.sin_port = htons(PORT);
        serverAddr.sin_addr.s_addr = inet_addr(argv[1]);

        connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
        printf("...Connected to Server.\n");
    while(1)
    {
        printf("enter message to server:");
        scanf("%s",g2);
        send(clientSocket,g2,sizeof(g2),0);
        recv(clientSocket, &buffer, 1024, 0);
        printf("Recieved Data..: %s\n", buffer);
    }
        printf("...Closing the connection...\n");

}

