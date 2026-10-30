#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXPIATTIPERPORTATA 10
#define MAXLENPIATTO 256

typedef struct 
{
    int npiatti;
    char piatti[MAXPIATTIPERPORTATA][MAXLENPIATTO];
} Portata;

void PrincipioMoltiplicazione(int numeroportate,int pos, char sol[][MAXLENPIATTO],Portata *vettoreportate)
{
    if(pos==numeroportate)
    {
        for(int i=0;i<numeroportate;i++)
        {
            printf("%s",sol[i]);
        }
        printf("\n");
        return;
    }
    for(int k=0;k<vettoreportate[pos].npiatti;k++)
    {
        strcpy(sol[pos],vettoreportate[pos].piatti[k]);
        PrincipioMoltiplicazione(numeroportate,pos+1,sol,vettoreportate);
    }

}
int main(void)
{
    char sol[MAXPIATTIPERPORTATA][MAXLENPIATTO];
    int numeroportate;
    FILE *fp = fopen("menu.txt","r");
    if(fp==NULL)
    {
        printf("Attenzione errore di lettura file");
        return 1;
    }
    fscanf(fp,"%d",&numeroportate);
    Portata *vettore = malloc(sizeof(Portata)*numeroportate);
    for(int i=0;i<numeroportate;i++)
    {
        int npiatti;
        fscanf(fp,"%d",&npiatti);
        vettore[i].npiatti = npiatti;
        for(int j=0;j<npiatti;j++)
        {
            fscanf(fp,"%s",vettore[i].piatti[j]);
        }
    }
    PrincipioMoltiplicazione(numeroportate,0,sol,vettore);
    free(vettore);
    fclose(fp);
    return 0;
}