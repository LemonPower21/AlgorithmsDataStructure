#include <stdio.h>

int fibonacci(int n)
{
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    return(fibonacci(n-2)+fibonacci(n-1));
    
}
int main(void)
{
    int v1 = 12;
    printf("La serie di fibonacci all'ordine n %d si ferma a %d",v1,fibonacci(v1));
}