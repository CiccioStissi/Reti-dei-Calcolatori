#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char username[15];
    char password[15];
}credenziali;

void scrivi()
{
    FILE* fp;
    credenziali cred;
    fp= fopen("autenticazioni.txt" ,"a+");
    scanf("%s %s",cred.username,cred.password);

    //printf("%s %s",cred.username,cred.password);
    
    fprintf(fp,"%s %s\n",cred.username,cred.password);

    fclose(fp);

}

void autenticazione()
{
    FILE* fp;
    credenziali cred;
    char aut_username[15];
    char aut_password[15];

    fp= fopen("autenticazioni.txt", "r");
    printf("Verifica le seguenti credenziali:\n");
    scanf("%s\t%s\n",aut_username, aut_password);

    if(aut_username == cred.username && aut_password == cred.password)
    {
        printf("Autenticazione avvenuta con successo\n");
    }
    else
    {
        printf("Credenziali errate\n");
    }
    fclose(fp);
}


void start()
{
    FILE* fp;
    int numero;
    printf("Inserire il numero dell'operazione da eseguire\n");
    scanf("%d",&numero);

    if(numero < 1 || numero > 2)
    {
        printf("Errato, inserire il numero 1 o 2\n");
        exit(-1);
    }
    
    if(numero == 1)
    {
        printf("Inserisci le tue credenziali:\n");
        scrivi(fp);
    }
    else if(numero == 2)
    {
        printf("Prosegui con l'autenticazioni delle credenziali:\n");
        autenticazione(fp);
    }
    fclose(fp);
}


int main(int argc , char** argv)
{

    /*if(argc != 3)
    {
        fprintf(stderr,"Errore, numero argomenti errato\n");
        exit(-1);
    }

    if(strlen(argv) < 8 || strlen(argv) > 15)
    {
        fprintf(stderr,"Errore, inserire una password di almeno 8 caratteri e non superiore a 15\n");
        exit(-1);
    }

    if(!fp)
    {
        fprintf(stderr,"Errore nell'apertura del file\n");
        exit(-1);
    }*/

    start();
}
