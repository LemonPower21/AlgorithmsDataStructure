# Sintesi: Ottimizzazione, Controlli e Pruning nel Backtracking

| Strategia | Dove si posiziona l'`if` | Quando agisce | Obiettivo principale | 
| ----- | ----- | ----- | ----- | 
| **A) Early Stopping** | **Inizio della funzione** | Prima di esplorare l'albero | Interrompere la ricerca appena si raggiunge un limite (es. $N$ soluzioni trovate). | 
| **B) Soluzione Ottima** *(Min/Max)* | **Nel caso di successo** + **All'inizio** (*Branch & Bound*) | Durante e a fine generazione | Trovare la soluzione di costo/dimensione minima (o valore massimo) aggiornando un record `best`. | 
| **C) Controllo sulla Soluzione** | **Nel caso base** (`pos >= k`) | A fine generazione (soluzione **completa**) | Stampare/contare solo le soluzioni che rispettano i vincoli globali. | 
| **D) Pruning (Potatura)** | **Dentro il ciclo `for`** o **All'inizio** | Durante la costruzione (soluzione **parziale**) | Tagliare i rami morti o non promettenti dell'albero di ricerca. | 

---

## 1. Ricerca della Soluzione Ottima (Es. Dimensione Minima con Target)

Quando si cerca l'**ottimo** (es. sottoinsieme di **dimensione minima** che raggiunge una somma `target`), si usa la tecnica del **Branch and Bound**:
1. Si mantiene una variabile `best` (es. `min_dim`) aggiornata via riferimento (`int *min_dim`).
2. Si applica un **pruning aggressivo**: se la soluzione parziale attuale (`pos`) è già lunga quanto o più del minimo attuale (`pos >= *min_dim`), si taglia subito il ramo.

```c
int DisposizioniOttimizzate(int n, int k, int pos, int somma, int target, char sol[][MAXLEN], char val[][MAXLEN], int *min_dim) {
    
    // 1. PRUNING DI OTTIMIZZAZIONE (Branch and Bound)
    // Se la profondità attuale eguaglia o supera già il miglior risultato trovato, usciamo subito
    if (pos >= *min_dim) {
        return *min_dim; 
    }

    // 2. CONTROLLO TARGET (Condizione di successo)
    if (somma == target) {
        // Se la dimensione attuale è migliore del record, aggiorniamo il minimo!
        if (pos < *min_dim) {
            *min_dim = pos; 
        }
        return *min_dim;
    }

    // Caso base di stop (fine profondità o somma superata)
    if (pos >= k || somma > target) {
        return *min_dim;
    }

    // 3. RICORSIONE
    for (int j = 0; j < n; j++) {
        strcpy(sol[pos], val[j]);
        int val_num = atoi(val[j]);
        
        *min_dim = DisposizioniOttimizzate(n, k, pos + 1, somma + val_num, target, sol, val, min_dim);
    }
    
    return *min_dim;
}
```

---

## 2. Early Stopping (Arresto Anticipato)

* **Dove:** Subito all'inizio della funzione ricorsiva.
* **Scopo:** Evitare lavoro inutile se abbiamo già soddisfatto una condizione globale (es. trovato il numero massimo di soluzioni richieste).

```c
int DisposizioniRipetute(int n, int k, int cnt, int pos, char sol[][MAXLEN], char val[][MAXLEN]) {
    // OTTIMIZZAZIONE: Controllo globale prima di procedere
    if (cnt >= MAX_DESIDERATO) {
        return cnt;
    }
    
    if (pos >= k) {
        // ... caso base ...
    }
    
    for (int j = 0; j < n; j++) {
        strcpy(sol[pos], val[j]);
        cnt = DisposizioniRipetute(n, k, cnt, pos + 1, sol, val);
    }
    return cnt;
}
```

---

## 3. Controlli sulla Soluzione (Validazione Finale)

* **Dove:** Nel blocco del caso base (`if (pos >= k)`).
* **Scopo:** La soluzione è completa, ma vogliamo accettarla o stamparla solo se rispetta determinate regole (es. assenza di certi pattern).

```c
int DisposizioniRipetute(int n, int k, int cnt, int pos, char sol[][MAXLEN], char val[][MAXLEN]) {
    if (pos >= k) {
        // CONTROLLO: Verifica sulla soluzione COMPLETA
        if (VerificaCondizione(sol, k)) {
            for (int i = 0; i < k; i++) {
                printf("%s", sol[i]);
            }
            printf("\n");
            return cnt + 1;
        }
        return cnt; // Scartata se non valida
    }
    
    for (int j = 0; j < n; j++) {
        strcpy(sol[pos], val[j]);
        cnt = DisposizioniRipetute(n, k, cnt, pos + 1, sol, val);
    }
    return cnt;
}
```

---

## 4. Pruning Standard (Potatura della Soluzione Parziale)

* **Dove:** All'interno del ciclo `for`, **subito dopo** aver assegnato il valore e **prima** della chiamata ricorsiva.
* **Scopo:** Se la *porzione* di soluzione costruita finora (`da 0 a pos`) è già invalida, usiamo un `continue` per saltare la ricorsione su quel ramo.

```c
int DisposizioniRipetute(int n, int k, int cnt, int pos, char sol[][MAXLEN], char val[][MAXLEN]) {
    if (pos >= k) {
        for (int i = 0; i < k; i++) {
            printf("%s", sol[i]);
        }
        printf("\n");
        return cnt + 1;
    }
    
    for (int j = 0; j < n; j++) {
        strcpy(sol[pos], val[j]);
        
        // PRUNING: Verifica sulla soluzione PARZIALE
        if (!VerificaParzialeValida(sol, pos)) {
            continue; // Salta questo ramo e passa al prossimo 'j'
        }
        
        // Se il ramo è valido, scendiamo in profondità
        cnt = DisposizioniRipetute(n, k, cnt, pos + 1, sol, val);
    }
    return cnt;
}
```