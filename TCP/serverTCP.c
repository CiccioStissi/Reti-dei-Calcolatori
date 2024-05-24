#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arna/inet.h>
#include <errno.h>


int main(int argc, char** argv)
{
    int sockfd, newsockfd, n;
    struct sockaddr_in local_addr, remote_addr;
    socklen_t len = sizeof(struct sockaddr_in);
    char msg[1000];

    if(argc < 2)
    {
        printf("Errore, inserisci numero porta!\n");
        return -1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0)
    {
        printf("Errore nell'apertura del socket\n");
        return -1;
    } 

    memset(&local_addr, 0, len);
    local_addr.sin_family = AF_INET;
    local_addr.sin_addr.s_addr = htonl(INADDR_ANY);     //Prende automaticamente l'indirizzo della macchina
    local_addr.sin_port = htons(atoi(argv[1]));

    if(bind(AF_INET, (struct sockaddr*)&local_addr, sizeof(local_addr)) < 0)
    {
        printf("Errore nella bind\n", errno);
        return -1;
    }

    listen(sockfd, 5);

    for(;;)
    {
        len= sizeof(remote_addr);
        newsockfd = accept(sockfd, (struct sockaddr*)&remote_addr, &len);
    }

    if(fork() == 0)     //uguale a 0 è il processo del figlio, utile solamente in TCP
    {
        close(sockfd);

        for(;;)     //PARTE DA MODIFICARE ALL'ESAME
        {
            n = recv(newsockfd, msg, 999, 0);
            msg[n] = 0;
            printf("IP %s, P %d, MSG %s",inet_ntoa(remote_addr.sin_addr), nhtons(remote_addr.sin_port),msg);
            send(newsockfd, msg, n, 0);
        }
        close(newsockfd);
        return 0;
    }
    else        //processo del padre
    {
        close(newsockfd);       //chiude il processo del figlio e torna in ascolto ad accept()
        return 0;
    }

    close(sockfd);
    return 0; 
}