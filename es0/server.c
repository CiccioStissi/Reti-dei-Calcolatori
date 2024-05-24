#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char username[15];
    char password[15];
}credenziali;


void autenticazione()
{
    FILE* fp;
    FILE* fr;
    credenziali cred;
    char aut_username[15];
    char aut_password[15];
    int lunghezza = 15;

    fp= fopen("autenticazioni.txt", "r");
    fr= fopen("registrati.txt","r");

    if(fp == NULL || fr == NULL)
    {
        printf("Errore nell'apertura del file\n");
    }

    /*printf("Verifica le seguenti credenziali:\n");
    scanf("%s\t%s",aut_username, aut_password);

    if(!feof(fp) && feof(fr))
    {
        if(fgets(aut_username, lunghezza,fp) == fgets(cred.username, lunghezza, fr))
        {
            if(fgets(aut_password, lunghezza, fp) == fgets(cred.username, lunghezza, fr))

            printf("Autenticazione avvenuta con successo\n");
        }
        else
        {
            printf("Credenziali errate\n");
        }
    }*/

    printf("Inserire le credenziali:\n");
    scanf("%s %s",aut_username,aut_password);

    while(fscanf(fr,"%s %s",cred.username,cred.password) != EOF)
    {
        if(strcmp(aut_username, cred.username) == 0 && strcmp(aut_password, cred.password) == 0)
        {
            printf("Autenticazione avvenuta con successo!\n");
        }
    }

    fclose(fp);
    fclose(fr);
}


int main(int argc , char** argv)
{
    autenticazione();
}