#include <stdio.h>
#include <stdlib.h>

//DEFINISCO IL NODO
typedef struct node *link;
struct node{
    int val;
    link next;
};
//CREO FUNZIONE CHE CREI IL NODO
link newnode(int v,link n)
{
    link x;
    x = malloc(sizeof(struct node));
    if(x==NULL)
    {
        printf("Errore di allocazione!");
    }
    else
    {
        x->val = v;
        x->next = n;
    }
    return x;
}
//INSERISCO IL NODO IN TESTA (NON HO BISOGNO CONTROLLI SULLA TESTA PRECEDENTE)
link InsNodoTesta(int v, link headprec)
{
    link hnow = newnode(v,headprec);
    return hnow;
}
//INSERISCO IL NODO IN CODA (HO BISOGNO DI CONTROLLI SULLA TESTA)
link InsNodoCoda(int v, link head)
{
    link x;
    if(head==NULL)
    {
        return newnode(v,NULL);
    }
    for(x=head; x!=NULL; x=x->next);
    x->next = newnode(v,NULL);
    return head;
}


int main()
{

}
