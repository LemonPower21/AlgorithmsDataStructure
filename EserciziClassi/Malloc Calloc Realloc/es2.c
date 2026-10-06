#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int nd;
    printf("Inserire numero di dati da inserire");
    scanf("%d",&nd);
    int *v  =(int *)calloc(nd, sizeof(int));  //Come argomenti calloc chiede dimensione vettore e sizeof(tipo)
    if(v==NULL)
    {
        printf("Errore di allocazione spazio");
    }
    for(int i=0;i<nd;i++)
    {
        printf("%d ",v[i]);
    }
    for(int i=0;i<nd;i++)
    {
        printf("\n\nInserire nuovo dato: \n");
        scanf("%d",&v[i]);
    }
    for(int i=0;i<nd;i++)
    {
        printf("%d ",v[i]);
    }


    printf("Inserire altri 3 punteggi");

    int *p = (int *)realloc(v, sizeof(int)*(nd+3)); //Realloc chiede nuovo puntatore , il vettore di partenza e la sizeof del vettore 
    if(p==NULL)
    {
        printf("Errore di allocazione spazio");
    }
    for(int i=5;i<(nd+3);i++)
    {
        printf("\n\nInserire nuovo dato: \n");
        scanf("%d",&p[i]);     
    }
    for(int i=0;i<(nd+3);i++)
    {
        printf("%d ",p[i]);
    }
}