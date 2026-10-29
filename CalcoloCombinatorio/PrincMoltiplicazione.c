#include <stdio.h>
#include <stdlib.h>

/* Definizione della struttura Livello */
typedef struct {
    int n_scelte;
    int *scelte;
} Livello;

/* Funzione ricorsiva rinominata in PrincMolt */
int PrincMolt(int pos, Livello *val, int *sol, int n, int cnt) {
    int i;
    
    if (pos >= n) {
        for (i = 0; i < n; i++) {
            printf("%d ", sol[i]);
        }
        printf("\n");
        return cnt + 1;
    }
    
    for (i = 0; i < val[pos].n_scelte; i++) {
        sol[pos] = val[pos].scelte[i];
        cnt = PrincMolt(pos + 1, val, sol, n, cnt);
    }
    
    return cnt;
}

int main() {
    int n = 2; // Numero di livelli (profondità della ricorsione)
    Livello *val = (Livello *)malloc(n * sizeof(Livello));
    int *sol = (int *)malloc(n * sizeof(int));

    // Esempio: 2 livelli, ognuno con 2 scelte possibili (es. {1, 2})
    val[0].n_scelte = 2;
    val[0].scelte = (int *)malloc(2 * sizeof(int));
    val[0].scelte[0] = 1;
    val[0].scelte[1] = 2;

    val[1].n_scelte = 2;
    val[1].scelte = (int *)malloc(2 * sizeof(int));
    val[1].scelte[0] = 3;
    val[1].scelte[1] = 4;

    printf("Soluzioni trovate:\n");
    int totali = PrincMolt(0, val, sol, n, 0);
    printf("Numero totale di soluzioni: %d\n", totali);

    // Pulizia della memoria
    free(val[0].scelte);
    free(val[1].scelte);
    free(val);
    free(sol);

    return 0;
}