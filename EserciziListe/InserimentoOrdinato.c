typedef struct node *link;
struct node
{
    int valore;
    link next;
};

int CompareNumber(int a, int b)
{
    if(a<b)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

link InserimentoOrdinato(int v, link head)
{
    link p,x;
    //CREONODO
    link n = newnode(v,NULL);
    if(n==NULL)
    {
        printf("Attenzione errore di allocazione!");
    }
    //VERIFICO CONDIZIONE DI VUOTO OPPURE ELEMENTO PIU' PICCOLO DELLA TESTA
    if(head==NULL || Compare(v,head->valore)<0)
    {
        n->next=head;
        return n;
    }
    for(p=head,x=head->next;x!=NULL ||CompareNumber(v,x->valore)>=0;p=x,x=x->next);
    n->next = x;
    p->next = n;
    return head;
}