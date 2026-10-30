#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int DisposizioniRipetute(int n,int k, int cnt, int pos, int *sol, int *val)
{
    if(pos>=k)
    {
        for(int j=0;j<k;j++)
        {
            printf("%d",sol[j]);
        }
        printf("\n");
        return cnt+1;
    }
    for(int i=0;i<n;i++)
    {
        sol[pos] = val[i];
        cnt = DisposizioniRipetute(n,k,cnt,pos+1,sol,val);
    }
    return cnt;
}
int main(void)
{
    int val[3] = {1,2,3};
    int k=3; //In questo caso n=k
    int *sol = malloc(sizeof(int)*k);
    int cnt=0;
    cnt = DisposizioniRipetute(3,k,cnt,0,sol,val);
    return 0;
}