#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validar.h"

int menu(char men[])
{
    int opc;

    printf(men);
    fflush(stdin);
    scanf("%d",&opc);

    return opc;
}

void getString(char men[], char info[])
{
    printf(men);
    fflush(stdin);
    gets(info);
}

void getSoloLetras(char men[], char palabra[])
{
    int i;
    char aux[50];
    int letra = 0;

    do
    {
        getString(men,aux);

        for(i=0;aux[i]!='\0';i++)
        {
            if((aux[i]<'a'||aux[i]>'z')&&(aux[i]<'A'||aux[i]>'Z')&&(aux[i]!=' '))
            {
                break;
            }
        }

        if(aux[i]=='\0')
        {
            strcpy(palabra,aux);
            letra=1;
        }

    }
    while(letra==0);
}

int getSoloEnteros(char men[])
{
    int i;
    char num[10];
    int numEntero;
    int esnum = 0;

    do
    {
        getString(men, num);

        for(i=0; num[i] != '\0'; i++)
        {
            if(num[i]<'0'||num[i]>'9')
            {
                break;
            }
        }

        if(num[i]=='\0')
        {
            numEntero=atoi(num);
            esnum=1;
        }

    } while(esnum==0);

    return numEntero;
}

float getSoloFlotantes(char men[])
{
    int i;
    char num[10];
    float numFlotante;
    int flotante = 0;

    do
    {
        getString(men, num);

        for(i=0;num[i]!='\0';i++)
        {
            if((num[i]<'0'||num[i]>'9')&&(num[i]!='.'))
            {
                break;
            }
        }
        if(num[i]=='\0')
        {
            numFlotante=atof(num);
            flotante=1;
        }
    }
     while(flotante==0);
     return numFlotante;
}

