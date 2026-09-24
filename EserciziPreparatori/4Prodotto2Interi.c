#include <stdio.h>
#include <math.h>

// X rappresenta il primo numero come vettore mentre Y rappresenta il secondo numero
long prodint(int *x, int lx, int rx, int *y, int ly, int ry, int n)
{
    long tmp1, tmp2, tmp3; // Variabili dichiarate ma non utilizzate nella versione corrente
    
    // CASO BASE: Se i vettori si riducono a 1 sola cifra (n == 1)
    if(n == 1)
    {
        return (x[lx] * y[ly]); // Esegue la moltiplicazione elementare (come le tabelline)[cite: 1]
    }
    
    // PASSO RICORSIVO (Divide et Impera con a=4, b=2):
    // t1 calcola il prodotto delle parti sinistre (xs * ys)
    long t1 = prodint(x, lx, (lx + rx) / 2, y, ly, (ly + ry) / 2, n / 2);
    
    // t2 calcola i prodotti incrociati (xs * yd + xd * ys)
    long t2 = prodint(x, lx, (lx + rx) / 2, y, ly + n / 2, ry, n / 2) + 
              prodint(x, lx + n / 2, rx, y, ly, (ly + ry) / 2, n / 2);
              
    // t3 calcola il prodotto delle parti destre (xd * yd)
    long t3 = prodint(x, lx + n / 2, rx, y, ly + n / 2, ry, n / 2);
    
    // COMBINA: Ricompone il risultato finale applicando i fattori di scala basati sulle potenze di 10  C(n) = THETA(n)    (stiamo ricombinando risultati albero e in questo caso a causa delle somme e prodotti parziali arriviamo a theta(n))
    return t1 * pow(10, n) + t2 * pow(10, n / 2) + t3;
}

int main(void)
{
    int a[] = {1, 0, 0, 0};
    int b[] = {1, 2, 3, 4};
    
    // Chiamata iniziale: passiamo i vettori, gli indici di inizio (0) e fine (3), e la dimensione iniziale delle cifre (4)[cite: 1]
    printf("Il risultato della moltiplicazione e':  %ld", prodint(a, 0, 3, b, 0, 3, 4));
    return 0;
}

/*
 ========================================================================================================
 MEGA COMMENTO: SPIEGAZIONE PASSO PASSO DELL'ALBERO DI RICORSIONE (ESEMPIO CON N = 4)
 ========================================================================================================
 
 Quando esegui `prodint(a, 0, 3, b, 0, 3, 4)` con due numeri di 4 cifre (n = 4), l'algoritmo segue 
 una strategia "Divide et Impera" multi-via (con a = 4 sottoproblemi e fattore di riduzione b = 2)[cite: 1]:
 
 1. LIVELLO 0 (n = 4):
    La funzione riceve i vettori interi di 4 cifre (`lx=0, rx=3` e `ly=0, ry=3`).
    Poiché n != 1, la funzione NON si ferma e si divide in tre grandi blocchi ricorsivi per calcolare t1, t2 e t3:
    - Calcola `t1` chiamando `prodint` sulla metà di sinistra di entrambi i numeri (dimensione n/2 = 2).
    - Calcola `t2` sommando due chiamate ricorsive incrociate (sinistra-destra e destra-sinistra) di dimensione n/2 = 2.
    - Calcola `t3` chiamando `prodint` sulla metà di destra di entrambi i numeri (dimensione n/2 = 2).

 2. LIVELLO 1 (n = 2):
    Ognuna delle chiamate precedenti riceve ora sottointervalli di dimensione 2 (es. indici da 0 a 1, o da 2 a 3).
    Dato che n = 2 (ancora diverso da 1), ciascuna di queste istanze si divide nuovamente a sua volta:
    - Ognuno dei 3 rami (t1, t2, t3) genera a sua volta altre sotto-chiamate con dimensione dimezzata (n/2 = 1).

 3. LIVELLO 2 / CASO BASE (n = 1):
    La ricorsione raggiunge la base quando la dimensione dei sottointervalli diventa n = 1.
    - A questo punto l'istruzione `if(n == 1)` diventa vera[cite: 1].
    - La funzione smette di ramificare e restituisce direttamente la moltiplicazione elementare tra la singola cifra 
      del primo vettore e la singola cifra del secondo vettore (`x[lx] * y[ly]`)[cite: 1].

 4. FASE DI RISALITA E COMBINAZIONE:
    - I risultati elementari restituiti dalle foglie (n=1) risalgono ai livelli superiori.
    - Vengono combinati tramite le somme di `t1`, `t2` e `t3`.
    - Ciascun blocco intermedio scala i risultati moltiplicandoli per le potenze di 10 adeguate (`pow(10, n)` e `pow(10, n/2)`)[cite: 1].
    - Infine, l'ultimo `return` del livello 0 ricompone il numero intero definitivo e lo restituisce al `main`, 
      che lo stampa a schermo tramite lo specificatore `%ld`.
 ========================================================================================================
*/