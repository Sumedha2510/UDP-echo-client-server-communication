#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include <string.h>
#include <unistd.h>
#define MAXSIZE 1024
int main()
{
        int sockfd;
        int n;
        socklen_t len;
        char sendline[1024],recvline[1024];
        struct sockaddr_in servaddr;
        strcpy(sendline,"");
        printf("\n Enter the message : ");
        scanf("%s",sendline);
        sockfd=socket(AF_INET,SOCK_DGRAM,0);
        bzero(&servaddr,sizeof(servaddr));
        servaddr.sin_family=AF_INET;
        servaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
        servaddr.sin_port=htons(9002);
        connect(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr));
        len=sizeof(servaddr);
        sendto(sockfd,sendline,MAXSIZE,0,(struct sockaddr*)&servaddr,len);
        n=recvfrom(sockfd,recvline,MAXSIZE,0,NULL,NULL);
        recvline[n]=0;
        printf("\n Server's Echo : %s\n\n",recvline);
        return 0;
}
