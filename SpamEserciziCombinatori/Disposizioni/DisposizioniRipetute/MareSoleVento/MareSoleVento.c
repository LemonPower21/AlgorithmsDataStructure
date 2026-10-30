#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 10

int DisposizioniRipetute(int n, int k, int cnt, int pos, char sol[][MAXLEN], char val[][MAXLEN])
{
    if(pos>=k)
    {
        for(int i=0;i<k;i++)
        {
            printf("%s",sol[i]);
        }
        printf("\n");
        return cnt+1;
    }
    for(int j=0;j<n;j++)
    {
        strcpy(sol[pos],val[j]);
        cnt = DisposizioniRipetute(n,k,cnt,pos+1,sol,val);
    }
    return cnt;
}
int main(void)
{
    int k=2;
    char sol[k][MAXLEN];
    char val[][MAXLEN]= {"sole","mare","vento"};
    int n=3;
    int cnt=0;
    cnt = DisposizioniRipetute(n,k,cnt,0,sol,val);
}