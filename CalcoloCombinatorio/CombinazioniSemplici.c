int CombinazioniSemplici(int n,int k, int pos, int start, int cnt, int *val, int *sol)
{
    if(pos>=k)
    {
        //EVENTUALE IF DI CONTROLLO
        for(int j=0;j<k;j++)
        {
            printf("%d ",sol[j]);
        }
        return cnt +1;
    }
    for(int i=start;i<n;i++)
    {
        sol[pos]= val[i];
        cnt = CombinazioniSemplici(n,k,pos+1,i+1,cnt,val,sol);
    }
    return cnt;
}