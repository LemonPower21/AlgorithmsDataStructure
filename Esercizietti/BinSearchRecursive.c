#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int BinSearch(int *v,int t,int l,int r)
{
    if(l>=r)
    {
        if(v[l]==t)
        {
            return l+1;
        }
        else
        {
            return -1;
        }
    }
    int m = (l+r)/2;
    if(v[m]==t)
    {
        return m+1;
    }
    if(t>v[m])
    {
        return BinSearch(v,t,m+1,r);
    }
    if(t<v[m])
    {
        return BinSearch(v,t,l,m-1);
    }

}

int main(void)
{
    int vettore[10] = {0,1,2,3,4,5,6,7,8,9};
    int t1=1;
    int t2;
    printf("Il valore %d si trova in %d casella",t1,BinSearch(vettore,t1,0,9));
}