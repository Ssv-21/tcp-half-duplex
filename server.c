#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 4404

void main(){

        int sockfd;
        struct sockaddr_in serverAddr;
        char g1[100],g2[100];
        int newSocket;
        struct sockaddr_in newAddr;

        socklen_t addr_size;
        char buffer[1024];

        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        printf("..Server Socket Created Sucessfully.\n");
        memset(&serverAddr, '\0', sizeof(serverAddr));

        serverAddr.sin_family = AF_INET;
        serverAddr.sin_port = htons(PORT);
        serverAddr.sin_addr.s_addr = inet_addr("127.0.0.3");

        bind(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
        printf("Bind to Port number: %d.\n", 4405);

        listen(sockfd, 5);
        printf("...Listening...\n");

        newSocket = accept(sockfd, NULL, NULL);
        while(1)
        {
         recv(newSocket,&g2,sizeof(g2),0);
         printf("client message is: %s \n",g2);
         printf("enter message to client..:");
         scanf("%s",g1);
         send(newSocket, &g1, sizeof(g1), 0);
        }
        printf("...Closing the connection...\n");


}
