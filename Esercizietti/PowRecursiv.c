#include <stdio.h>
int Pow(int b,int e)
{
    if(e==0)
    {
        return 1;
    }
    return b*Pow(b,e-1);
}
int main(void)
{
    int b=10;
    int e=3;
    printf("%d",Pow(b,e));
}