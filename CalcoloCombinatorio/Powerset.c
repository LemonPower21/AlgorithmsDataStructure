int Powerset(int n,int cnt, int pos, int *val, int *sol)
{
    if(pos>=n)
    {
        //QUI VA CONDIZIONE DI STAMPA
        for(int j=0;j<n;j++)
        {
            if(sol[j]!=0)
            {
                printf("%d ",val[j]);
            }
        }
        return cnt+1;
    }
    //AVANZAMENTO
    sol[pos] = 0;
    cnt = Powerset(n,cnt,pos+1,val,sol);
    //BACKTRACK
    sol[pos] = 1;
    cnt = Powerset(n,cnt,pos+1,val,sol);
    return cnt;
}

/*COSE DA SAPERE
1. sol e val hanno dimensione n 
2. sol è un vettore di 0 e 1 usato generalmente per CONTROLLI
3. nella MAIN quando chiamo powerset nei campi cnt e pos posso mettere 0*/
