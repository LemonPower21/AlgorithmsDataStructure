#include <stdio.h>
#include <stdlib.h>

#define MAXCHOICE 10
#define MAXLENCHOICE 256

typedef struct 
{
    int nelementi;
    char elementi[MAXCHOICE][MAXLENCHOICE];
}Insieme;


void PrincipioMoltiplicazione(int ninsiemi,int pos, Insieme *vettore, char sol[][MAXLENCHOICE])
{
    if(pos>=ninsiemi) //CASO TERMINALE, STAMPO SOLUZIONE CHE HA DIMENSIONE PARI AL NUMERO DI INSIEMI
    {
        for(int i=0;i<ninsiemi;i++)
        {
            printf("%d",sol[i]);
        }
        printf("\n");
        return;
    }
    for(int j=0;j<vettore[pos].nelementi;j++)  //PER OGNI INSIEME DEL VETTORE DI INSIEMI FACCIO SCORRERE J CHE SARA IL SELETTORE DI STRINGA E POS SARA' IL SELETTORE DI INSIEME (POS+1 VADO A INSIEME SUCCESSIVO)
    {
        strcpy(sol[pos],vettore[pos].elementi[j]);
        PrincipioMoltiplicazione(ninsiemi,pos+1,vettore,sol);
    }
}

int main(void)
{
    FILE *fp = fopen("viaggi.txt","r");
    if(fp==NULL)
    {
        printf("Attenzione errore di lettura del file!");
        return 1;
    }
    int numinsiemi;
    fscanf(fp,"%d",&numinsiemi);
    Insieme *vettoreinsiemi = (Insieme *)malloc(sizeof(Insieme)*numinsiemi);
    for(int i=0;i<numinsiemi;i++)
    {
        int nelementi;
        fscanf(fp,"%d",&nelementi);
        vettoreinsiemi[i].nelementi = nelementi;
        for(int j=0;j<nelementi;j++)
        {
            fscanf(fp,"%s",vettoreinsiemi[i].elementi[j]);
        }
    }
    return 0;
}