#include <stdio.h>
void StampaBinario(int n)
{
    if(n==0)
    {
        return;
    }
    StampaBinario(n/2);
    printf("%d",n%2);
}
int main(void)
{
    StampaBinario(9);
}
