#include <stdio.h>
int TrovaMassimo(int *v,int l, int r)
{
    if(l==r)
    {
        return v[l];
    }
    int m = (l+r)/2;
    int maxdx = TrovaMassimo(v,m+1,r);
    int maxsx = TrovaMassimo(v,l,m);
    return (maxsx > maxdx) ? maxsx : maxdx;
}
int main(void)
{
   int  v[5] = {1,2,3,66,77,0};
   printf("Il massimo e': %d",TrovaMassimo(v,0,4));
}