#include <stdio.h>
void stampacountdown(int N)
{
    if(N==0)
    {
        printf("%d ",N);
        return;
    }

    printf("%d ",N);
    stampacountdown(N-1);
}
int main()
{
    stampacountdown(10);
}