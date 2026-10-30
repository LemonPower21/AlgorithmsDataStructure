#include <stdio.h>
#include <stdlib.h>


int CheckSol(int *sol, int *val,int target,int n)
{
    int temptarget=0;
    for(int i=0;i<n;i++)
    {
        if(sol[i]==1)
        {
            temptarget += val[i];
        }
    }
    if(temptarget==target)
    {
        return 1;
    }
    return 0;
}
int Powerset(int n,int cnt, int pos, int *sol, int *val,int target)
{
    if(pos>=n)
    {
        if(CheckSol(sol,val,target,n))
        {
            printf("{");
            for(int i=0;i<n;i++)
            {
                if(sol[i]==1)
                {
                    printf("%d ",val[i]);
                }
            }
            printf("}");
            return cnt+1;
        }
        return cnt;
    }
    sol[pos]=0;
    cnt = Powerset(n,cnt,pos+1,sol,val,target);
    sol[pos]=1;
    cnt = Powerset(n,cnt,pos+1,sol,val,target);
    return cnt;
}
int main(void)
{
    int vettore[4] = {2,1,6,4};
    int n=4;
    int target = 7;
    int *sol = malloc(sizeof(int)*n);
    int cnt =0;
    cnt = Powerset(n,cnt,0,sol,vettore,target);
    return 0;
}