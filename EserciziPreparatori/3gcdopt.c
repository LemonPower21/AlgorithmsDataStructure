#include <stdio.h>

int gcd(int x,int y)
{
    if(y==0)
        return x;
    //INVERSIONE E SCAMBIO DEI MODULI
    return gcd(y,x%y);
}
int main(void)
{
    int x = 36;
    int y = 72;
    printf("Il GCD tra  %d e %d vale %d",x,y,gcd(x,y));

}