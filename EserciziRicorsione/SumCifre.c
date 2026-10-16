#include <stdio.h>
int SumCifre(int n)
{
    int newnum;
    if(n<10)
    {
        return n;
    }
    newnum=n;
    //256  = 256%10 + f(25)
    while(newnum%10!=0)
    {
        newnum--;
    }
    return n%10 + SumCifre(newnum/10);
}
int main(void)
{
    printf("%d",SumCifre(157));
}
