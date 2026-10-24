int CombinazioniRipetute(int n, int k, int pos, int cnt, int start,int *val, int *sol)
{
    if(pos>=k)
    {
        //EVENTUALE IF DI CONTROLLO SU SOL
        for(int i=0;i<k;i++)
        {
            printf("%d ",sol[i]);
        }
        return cnt+1;
    }
    for(int i=start; i<n;i++)
    {
        sol[pos]  = val[i];
        cnt = CombinazioniRipetute(n,k,pos+1,cnt,start,val,sol);
        start++;
    }
    return cnt;
}