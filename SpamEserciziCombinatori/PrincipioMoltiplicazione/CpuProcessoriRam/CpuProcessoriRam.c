#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSCELTECOMP 10
#define MAXLENCOMPONENTE 255
typedef struct
{
    int nscelte;
    char componente[MAXSCELTECOMP][MAXLENCOMPONENTE];
}Componenti;


void PrincipioMoltiplicazione(int pos,Componenti *vettore,char sol[][MAXLENCOMPONENTE],int ninsiemi)
{
    if(pos==ninsiemi) //CASO TERMINALE
    {
        for(int i=0;i<ninsiemi;i++)
        {
            printf("%s",sol[i]);
        }
        printf("\n");
        return;
    }
    //COPIA IN POSISIZIONE POS DELLA STRINGA K-ESIMA
    for(int k=0;k<vettore[pos].nscelte;k++)
    {
        strcpy(sol[pos],vettore[pos].componente[k]);
        PrincipioMoltiplicazione(pos+1,vettore,sol,ninsiemi);
    }
}
int main(void)
{
    char soluzione[MAXSCELTECOMP][MAXLENCOMPONENTE];
    FILE *fp = fopen("pc.txt","r");
    if(fp==NULL)
    {
        printf("Errore di lettura file!");
        return 1;
    }
    int ninsiemi;
    fscanf(fp,"%d",&ninsiemi);
    Componenti *vettore = malloc(sizeof(Componenti)*ninsiemi);
    for(int i=0;i<ninsiemi;i++)
    {
        int numerocomponenti;
        fscanf(fp, "%d",&numerocomponenti);
        vettore[i].nscelte= numerocomponenti;
        for(int j=0;j<numerocomponenti;j++)
        {
            fscanf(fp,"%s ",vettore[i].componente[j]);
        }
    }
    PrincipioMoltiplicazione(0,vettore,soluzione,ninsiemi);
    return 0;
}