#include <stdio.h>
int main (void)
{
    /*
    LISTE
        -SEQUENZA LINEARE (LISTE): Insime finito di elementi di tipo generico "Item" disposti consecutivamente in cui a ogni elemento è associato univocamente un indice 
            A) C'è relazione d'ordine (PREDECESSORE - SUCCESSORE)   (Tranne per chi sta alla fine o a posizione 0)
            
                1) Sequenza per definazione ordinata in termini posizionali, se è ordinata per valori invece la chiamiamo "Ordinata"
                2) Accesso avviene per:
                    A) CHIAVE
                    B) POSIZIONE

                    ATTENZIONE: Il costo può essere O(N) oppure O(1)  (può essere anche log(n))
                        O(1): Cerca il terzo
                        O(N): Cerca il valore 4

                3) Esempi di sequenze lineari sono 
                    A) VETTORI
                    B) LISTA CONCATENATA (Fabbricate con Struct Val e Item(Dato)(Generalmente struttura) Key(Chiave)(Numero o puntatore a char))  Rappresentata con quadratini |VAL|NEXT| chiamati NODI
                        ATTENZIONE: LISTE CONCATENATE DOPPIE Permettono di andare avanti e indietro
                        - Dati non contigui
                        -VANTAGGIO: Memoria, SVANTAGGIO: O(N)

                        -Se conviene possiamo mettere Key dentro Item e fare funzioni Keyget()

                4) Operazioni
                    - Ricerca: in base a una chiave
                    - Inserzione: Inserire elemento
                    - Cancellazione: In LISTE CONCATENATE solo in testa
                        * CANELLA E DISTRUGGI
                        * CANCELLA E ESTRAI
                        * 
                    -Attraversamento:
                        I) per guardare lista (for(x=head, x!=NULL; x= x->next) dove x è puntatore )
                        II) per bypass, cancellazione, insercione (Puntatore al nodo corrente e al suo predecessore p=NULL;  for(x=head;x!=NULL; p=x x=x->next))    (x successore di p)
                        IIA) possiamo usare un solo puntatore usando il primo
                        III) Un modo permette di non gestire separetamente head
                        IV) Tramite ricorsion
                ATTENZIONE: Conviene usare vettori come liste quando vogliamo accesso diretto e operazione tramite aritmetica puntatori

                5) Per definire un tipo di dato node 
                    A) (Contine struttura Item e struct node *next (puntatore))
                    B) Ci sono diversi modi per definire i nodi
            
            B) ALLOCAZIONE DINAMICA NODI
                1) Dichiariamo puntatore a nodo 
                2) Dichiariamo la "head" che punta a NULL (Permette di vedere se è vuota o pien con un if)

    
    
    
    
    */
    return 0;
}