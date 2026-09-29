//ESEMPIO DI ALLOCAZIONE DINAMICA IN CUI N NON E' NOTO
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    float *v, num;
    int i=0,N=1;
    printf("Inserire il numero: ");
    v = (float *)malloc(N*sizeof(float));
    while(scanf("%f",&num)>0)
    {
        printf("Inserire il numero: ");
        if(i==N)
        {
            N +=1; //PER PASSARE DA O(N2)  A O(NlogN) CONVIENE FARE N=N*k dato che LA REALLOC COSTA O(N)
            v = realloc(v,N*sizeof(float));
        }
        v[i++]=num;  //ASSEGNO E INCREMENTO SEMPRE
    }

    //STAMPO INVERSO
    for(i=N-1;i>=0;i--)
    {
        printf("%f ",v[i]);
    }

    free(v);
    return 0;
}