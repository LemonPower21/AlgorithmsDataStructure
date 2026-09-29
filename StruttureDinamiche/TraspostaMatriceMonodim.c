//STAMPA DI TRASPOSTA DI MATRICE USANDO "VETTORIZZAZIONE" E ALLOCAZIONE DINAMICA MONODIMENSIONALE
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    float *vectorized;
    int nr, nc,i,j;
    printf("Inserire NR e NC: ");
    scanf("%d %d",&nr,&nc);
    vectorized = (float *)malloc(nc*nr*sizeof(float));
    for (i=0;i<nr;i++)
    {
        printf("Inserire la riga: ");
        for(j=0;j<nc;j++)
        {
            //MATRICE DI i RIGHE E j COLONNE LA SI PUO' VEDERE COME nc*i+j
            scanf("%f",&vectorized[nc*i + j]);
        }
    }

    //STAMPO LA TRASPOSTA INVERTENDO j ED i

    for(j=0;j<nc;j++)
    {
        for(i=0;i<nr;i++)
        {
            printf("%.2f ",vectorized[nc*i+j]);
        }
        printf("\n");
    }
}