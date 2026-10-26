int PermutazioniRipetute(int pos, int n, int ndist, int cnt, int *sol, int *val, int *distval,int *mark)
{
    if(pos>=n)
    {
        //EVENTUALE CONTROLLI LOGICI SU SOL
        for(int j=0;j<n;j++)
        {
            printf("%d ",sol[i]);
        }
        return cnt+1;
    }
    for(int i=0;i<ndist,i++)
    {
        if(mark[i]>0)
        {
            mark[i]--;
            sol[pos] = distval[i];
            cnt = PermutazioniRipetute(pos+1,n,ndist,cnt,sol,val,distval,mark);
            mark[i]++;
        }
    }
    return cnt;
}