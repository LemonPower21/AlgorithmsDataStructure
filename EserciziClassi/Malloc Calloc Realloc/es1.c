#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int nd;
    printf("Inserire numero di dati da inserire");
    scanf("%d",&nd);

    int *v = (int *)malloc(sizeof(int)*nd);
    if(v==NULL)
    {
        printf("Errore di allocazione spazio");
    }
    for(int i=0;i<nd;i++)
    {
        printf("\nInserisci dato:");
        scanf("%d",&v[i]);
    }
    for(int i=0;i<nd;i++)
    {
        printf("%d ",v[i]);
    }
    free(v);
    return 0;
}