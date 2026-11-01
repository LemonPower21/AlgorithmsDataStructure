#include <stdio.h>
#include <stdlib.h>

int TrovaMassimoRec(int *v,int n)
{
    if(n==1)
    {
        return v[0];
    }
    int max = TrovaMassimoRec(v+1,n-1);
    if(v[0]>max)
    {
        return v[0];
    }
    else
    {
        return max;
    }
}
int main(void)
{
    int vettore[10] ={3,4,55,6-8,-99,1,0,7,88};
    int m = TrovaMassimoRec(vettore,10);
    printf("%d",m);
}