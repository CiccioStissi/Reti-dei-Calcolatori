#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <unistd.h> //gestisce le funzioni per la gestione dei processi es. fork()

//Canale che gestisce ricezione

//Chat() P IP1 IP2


int main(int argc, char** argv)
{
    int sockfd, n;  //n= byte resituiti recivfrom
    struct sockaddr_in local_addr, remote_addr;
    socklen_t len = sizeof(struct sockaddr_in);
    char msg[1000];

    if(argc < 4)
    {
        pritnf("Errore! Inserisci IP, IP1, IP2\n");
        return -1;
    }

    if(fork())
    {
        if(sockfd = socket(AF_INET, SOCK_DGRAM, 0) < 0)
        {
            pritnf("Errorenell'apertura Socket\n");
            return -1;
        }

        memset(&local_addr, 0, len);
        local_addr.sin_family = AF_INET;
        local_addr.sin_port = htons(atoi(argv[3]));

        if(bind(sockfd, (struct sockaddr*), &local_addr, len) < 0)
        {
            pritnf("Errore nella Bind\n");
            return -1;
        }

        for(;;)
        {
            recvfrom(sockfd, msg, 999, 0,(struct sockaddr*)&remote_addr, &len);
            msg[n] = 0;
            
            printf("IP %s, P %d, msg %s", inet_ntoa(remote_addr.sin_addr),ntohs(remote_addr.sin_port), msg);

        }
    }
    else
    {
        if(sockfd = socket(AF_INET, SOCK_DGRAM, 0) < 0)
        {
            printf("Errore nell'apertura del Socket\n");
            return -1;
        }

        memset(remote_addr, 0, len);        //remote anzichè local
        remote_addr.sin_family = AF_INET;
        inet_pton(AF_INET, argv[1], &(remote_addr.sin_addr));       //argv[1] è l'indirizzo IP dell'altra macchina
        remote_addr.sin_port = htons(atoi(argv[2]))

        while(fgets(msg, 1000, stdin) != NULL)
        {
            sendto(sockfd, msg, strlen(msg), 0, (struct sockaddr*)&remote_addr, len);
        }

        /*if(strcmp(msg, "basta\n"))
        {
            break;
        }*/
    }

    return 0;
}
