#include <stdio.h>
#include <stdlib.h>
int DisposizioniRipetute(int n, int k, int pos, int cnt, int *val, int *sol)
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
        sol[pos]=val[i];
        cnt = DisposizioniRipetute(n,k,pos+1,cnt,val,sol);
    }
    return cnt;
}
int main(void)
{
    int cnt=0;
    int val[6] = {2,3,4,5,6,7};
    int k = 4;
    int *sol = malloc(sizeof(int)*k);
    cnt = DisposizioniRipetute(6,k,0,cnt,val,sol);
    return 0;
}