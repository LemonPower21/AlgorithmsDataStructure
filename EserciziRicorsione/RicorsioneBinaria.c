#include <stdio.h>
int RicercaBinaria(int *v, int e, int l, int r)
{
    int m = (l+r)/2;
    //ACCAVALLAMENTO INDICE = FINE RICERCA NON è STATO TROVATO
    if(l>r)
    {
        return -1;
    }
    if(v[m]==e)
    {
        return m;
    }
    if(e>v[m])
    {
        return RicercaBinaria(v,e,m+1,r);
    }
    if(e<v[m])
    {
        return RicercaBinaria(v,e,l,m-1);
    }
}
int main(void)
{
    int vettore[7] = {1, 4, 5, 6, 7, 8, 9};
    int e = 4;
    printf("L'elemento %d si trova in posizione %d",e,RicercaBinaria(vettore,e,0,6));
}