int PermutazioniSemplici(int n, int pos, int cnt, int *val, int *sol, int *mark)  //disposizioni dove k=n
{
    if(pos>=n)
    {
        //EVENTUALE CONTROLLO SU SOL PRIMA DI STAMPARLA
        for(int j=0;j<n;j++)
        {
            printf("%d", sol[j]);
        }
        return cnt+1;
    }
    for(int i=0;i<n;i++)
    {
        if(mark[i]==0)
        {
            mark[i]=1;
            sol[pos]= val[i];
            cnt = PermutazioniSemplici(n,pos+1,cnt,val,sol,mark);
            mark[i] = 0;
        }
    }
    return cnt;
}