#include <stdio.h>
#include <stdlib.h>
typedef struct node *link;
struct node{
    int valore;
    link next;
};

link inseriscicoda(int val1, link ptrP,link *head)
{
    link nodocoda = malloc(sizeof(struct node));
    if(nodocoda==NULL)
    {
        printf("Attenzione! errore di assegnamento memoria");
    }

    //GENERO NODO CHE ANDRA' ALLA CODA
    nodocoda->next = NULL;
    nodocoda->valore = val1;

    //IN CASO DI PRIMA INIZIALIZZAZIONE se head è null nodocoda sarà la head
    if(*head==NULL)
    {
        *head=nodocoda;
    }
    //IN ITERAZIONI SUCCESSIVE FACCIO PUNTARE IL PUNTATORE LINK PRECEDENTE A NODOCODA
    else
    {
        ptrP->next = nodocoda;
    }

    return nodocoda;
}
int main(void)
{
    int value;
    link head=NULL;
    link ncoda;
    printf("Esempio con 10 elementi ");
    for(int i=0;i<10;i++)
    {
        scanf("%d",&value);
        ncoda = inseriscicoda(value,ncoda,&head);
    }

    for(link x=head;x!=NULL;x=x->next)
    {
        printf("%d ",x->valore);
    }
}