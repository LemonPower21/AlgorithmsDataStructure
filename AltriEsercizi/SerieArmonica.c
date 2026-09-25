#include <stdio.h>
float recursiveArmonica(int n)
{
    if(n==1)
        return 1;
    return (float)1/n + recursiveArmonica(n-1);   //APPLICO CASTING
}
int main(void)
{
    int a = 2;
    printf("La somma armonica fin %d e' %f",a,recursiveArmonica(a));
}