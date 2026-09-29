//PROGRAMMA PER STAMPARE VETTORE AL CONTRARIO USANDO ALLOCAZIONE DINAMICA
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    float *v;
    int N,i;
    printf("Inserire il numero N (lunghezza vettore): ");
    scanf("%d",&N);
    v = (float *)malloc(N*sizeof(float));
    for(i=0;i<N;i++)
    {
        printf("Inserire valore float: ");
        scanf("%f",&v[i]);
    }

    for(i=N-1;i>=0;i--)
    {
        printf("%.2f ",v[i]);
    }
    free(v);
    return 0;
}