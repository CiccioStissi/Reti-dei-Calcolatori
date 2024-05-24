#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>     //gestire processi in C
#include <arna/inet.h>
#include <errno.h>


int main(int argc, char **argv)
{
    int sockfd, n;
    struct sockaddr_in local_addr, dest_addr;
    char sendline[1000];
    char reciveline[1000];

    if(argc != 3)
    {
        printf("Errore! Inserisci IP e Port\n");
        return -1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0)
    {
        printf("Errore nell'apertura del Socket\n");
        return -1;
    }

    memset(&dest_addr,0, sizeof(dest_addr));
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_addr.s_addr = inet_addr(argv[1]);
    dest_addr.sin_port = htons(atoi(argv[2]));


    connect(sockfd, (struct sockaddr*)&dest_addr, sizeof(dest_addr));

    while(fgets(sendline, 999, stdin) != NULL)  //PARTE DA MODIFICARE ALL'ESAME
    {
        send(sockfd, sendline, strlen(sendline), 0);
        n = recv(sockfd, reciveline, 999, 0);       //n è il numero di byte eseguiti
        reciveline[n] = 0;
         printf("IP->%s, P->%d, MSG->%s",inet_ntoa(dest_addr.sin_addr), nhtons(dest_addr.sin_port),reciveline);
    }

    close(sockfd);
    return 0;
}