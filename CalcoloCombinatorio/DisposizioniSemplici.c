int DisposizioniSemplici(int n, int k, int pos, int cnt, int *mark, int *val, int *sol)
{
    if(pos>=k)
    {
        //EVENTUALE CONDIZIONE
        for(int j=0;j<k;j++)
        {
            printf("%d ",sol[j]);
        }
        return cnt+1;
    }
    for(int i=0;i<n;i++)  //ITERO SULLE SCELTE
    {
        //VETTORE MARK DI DIMENSIONE N CHE CONTROLLA RIPETIZIONI
        if(mark[i]==0)   
        {
            mark[i] = 1;
            sol[pos] = val[i];
            cnt = DisposizioniSemplici(n,k,pos+1,cnt,mark,val,sol);
            mark[i] = 0;
        }
    }
}
