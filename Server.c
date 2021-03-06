#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#define MAXSIZE 1024
int main()
{
        int sockfd;
        int n;
        socklen_t len;
        char msg[1024];
        struct sockaddr_in servaddr,cliaddr;
        sockfd=socket(AF_INET,SOCK_DGRAM,0);
        bzero(&servaddr,sizeof(servaddr));
        servaddr.sin_family=AF_INET;
        servaddr.sin_addr.s_addr=INADDR_ANY;
        servaddr.sin_port=htons(9002);
        printf("\n");
        bind(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr));
        for(;;)
        {
                //printf("\n ");
                len=sizeof(cliaddr);
                n=recvfrom(sockfd,msg,MAXSIZE,0,(struct sockaddr*)&cliaddr,&len);
                printf("Client's Message : %s\n",msg);                    
                if(n<6)
                        perror("send error");
                sendto(sockfd,msg,n,0,(struct sockaddr*)&cliaddr,len);
        }
        return 0;
}
