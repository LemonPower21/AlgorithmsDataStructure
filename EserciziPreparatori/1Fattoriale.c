#include <stdio.h>

int factorial(int n)
{
    if((n==0)||(n==1))
        return 1;
    return n*factorial(n-1);
    
}
int main(void)
{
    int v1 = 5;
    int r = factorial(v1);
    printf("Il fattoriale di %d e' %d",v1,r);
}