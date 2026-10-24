int DisposizioniRipetute(int n, int k, int cnt, int pos, int *val, int *sol)
{
    if(pos>=k)
    {
        //EVENTUALE CONDIZIONE
        for(int i=0;i<k;i++)
        {
            printf("%d ",sol[i]);
        }
        return cnt+1;
    }
    for(int i=0;i<n;i++)
    {
        sol[pos] = val[i];
        cnt = DisposizioniRipetute(n,k,cnt,pos+1,val,sol);
    }
    return cnt;
}