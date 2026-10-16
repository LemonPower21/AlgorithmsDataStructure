#include <stdio.h>
int sommanat(int N)
{
    if(N==0)
    {
        return 0;
    }
    return N+sommanat(N-1);
}
int main()
{
    printf("%d", sommanat(4));
}