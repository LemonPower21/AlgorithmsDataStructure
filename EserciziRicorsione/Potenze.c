#include <stdio.h>

int PotenzaRicorsiva(int b,int e)
{
    if(e==0)
    {
        return 1;
    }
    return b*PotenzaRicorsiva(b,e-1);
}
int main(void)
{
    int b;
    int e;
    printf("Inserire BASE e ESPONENTE");
    scanf("%d%d",&b,&e);
    int r = PotenzaRicorsiva(b,e);
    printf("Il risultato è %d",r);

}