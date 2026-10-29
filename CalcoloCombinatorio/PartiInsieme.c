void PartiInsieme(int pos, int *val, int *sol, int n, int k) {
    int i, j, ok = 1, *occ;
    
    if (pos >= n) {
        occ = calloc(k, sizeof(int));
        for (j = 0; j < n; j++)
            occ[sol[j]]++;
            
        i = 0;
        while ((i < k) && ok) {
            if (occ[i] == 0) 
                ok = 0;
            i++;
        }
        
        if (ok) { 
            /* STAMPA SOLUZIONE */ 
        }
        free(occ);
        return;
    }
    
    for (i = 0; i < k; i++) {
        sol[pos] = i; 
        PartiInsieme(pos + 1, val, sol, n, k);
    }
}