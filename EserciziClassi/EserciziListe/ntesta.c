#include <stdio.h>
#include <stdlib.h>

typedef struct node *link;
struct node{
    int valore;
    link next;
};

link inseriscitesta(int val, link ptrH)
{
    /*Quello che facciamo qui è creare un nuovo nodo di tipo lista allocato dinamicamente e facciamo si che "il suo next" punti 
    proprio alla PRECEDENTE TESTA e che il suo valore sia quello dato dalla funzione*/
    link nodo = malloc(sizeof(struct node));
    if(nodo==NULL)
    {
        printf("Errore il nodo non è stato allocato correttamente!");
        return ptrH;
    }
    nodo->next= ptrH;
    nodo->valore = val;
    return nodo;
}

int main(void)
{
    printf("Simuliamo inserimento di 10 valori IN TESTA OGNI VOLTA");
    link head = NULL;
    int valore;
    for (int i=0;i<10;i++)
    {
        scanf("%d",&valore);
        head = inseriscitesta(valore, head);
    }

    //FACCIAMO LA STAMPA PARTENDO DALLA TESTA
    printf("Stampa partendo dalla testa");
    for(link x=head;x!=NULL;x=x->next)
    {
        printf("\nIl valore inserito e': %d",x->valore);
    }
}