# Guida alla Scelta dei Modelli Combinatori negli Esercizi

Questa guida raccoglie i criteri per individuare il modello combinatorio corretto da applicare nella risoluzione degli esercizi e nella ricerca nello spazio delle soluzioni tramite algoritmi ricorsivi (backtracking).

---

## Mappa Decisionale Rapida

Per capire quale modello applicare, rispondi a queste domande:

1. **L'ordine conta?**
   * **Sì** $\rightarrow$ Disposizioni o Permutazioni.
   * **No** $\rightarrow$ Combinazioni, Powerset o Partizioni.

2. **Si usano tutti gli elementi o solo un sottoinsieme $k$?**
   * **Tutti gli elementi ($k = n$)** $\rightarrow$ Permutazioni.
   * **Solo $k$ elementi** $\rightarrow$ Disposizioni o Combinazioni.
   * **Sottoinsiemi di lunghezza variabile** $\rightarrow$ Powerset.
   * **Suddivisione di tutti gli elementi in gruppi** $\rightarrow$ Partizioni.

3. **Gli elementi si possono ripetere?**
   * **Sì** $\rightarrow$ Modelli con ripetizione.
   * **No** $\rightarrow$ Modelli semplici.

---

## 1. Principio di Moltiplicazione
* **Quando si usa:** Quando un problema richiede di prendere $n$ decisioni in sequenza, in cui il numero di scelte disponibili a ogni livello varia o dipende da una struttura precisa.
* **Caratteristiche:** $N = n_1 \times n_2 \times \dots \times n_k$.
* **Esempi tipici:** 
  * Calcolare quanti menu diversi si possono comporre scegliendo tra $A$ antipasti, $B$ primi e $C$ secondi.
  * Modellare la struttura delle scelte in un albero di decisione.

---

## 2. Disposizioni Semplici ($D_{n,k}$)
* **Quando si usa:** Quando si scelgono $k$ elementi da un gruppo di $n$ oggetti distinti.
* **Caratteristiche:**
  * L'ordine **conta**.
  * **Senza** ripetizione (un elemento non può essere riusato).
* **Vettore di soluzione (`sol`):** Contiene i valori presi dal vettore degli elementi.
* **Esempi tipici:**
  * Creare codici o PIN a cifre distinte.
  * Assegnare i primi tre posti (podio) in una gara tra $n$ concorrenti.

---

## 3. Disposizioni con Ripetizione (${D'}_{n,k}$)
* **Quando si usa:** Quando si scelgono $k$ elementi da un gruppo di $n$, e lo stesso oggetto può essere scelto più volte.
* **Caratteristiche:**
  * L'ordine **conta**.
  * **Con** ripetizione.
* **Vettore di soluzione (`sol`):** Di dimensione $k$, ogni posizione memorizza l'indice o il valore scelto tra gli $n$ disponibili.
* **Esempi tipici:**
  * Generazione di sequenze binarie su $n$ bit.
  * Parole d'ordine con caratteri ripetibili.

---

## 4. Permutazioni Semplici ($P_n$)
* **Quando si usa:** Caso particolare delle disposizioni in cui $k = n$. Si ordinano **tutti** gli $n$ elementi distinti disponibili.
* **Caratteristiche:**
  * L'ordine **conta**.
  * **Senza** ripetizione.
* **Esempi tipici:**
  * Anagrammi di una parola con lettere tutte distinte.
  * Stabilire l'ordine di esecuzione di un insieme fisso di compiti.

---

## 5. Permutazioni con Ripetizione ($P_n^{(a,b,...)}$)
* **Quando si usa:** Si ordinano tutti gli elementi di un *multiinsieme* in cui vi sono elementi identici (con frequenze $a, b, \dots$).
* **Caratteristiche:**
  * L'ordine **conta**, ma scambiare due elementi identici non produce una nuova soluzione.
  * Nel codice si gestisce solitamente tenendo traccia delle **scorte/occorrenze** disponibili per ciascun tipo.
* **Esempi tipici:**
  * Anagrammi di parole con lettere ripetute (es. "ANANAS").
  * Problema delle collane con numero fisso di pietre per tipo.

---

## 6. Combinazioni Semplici ($C_{n,k}$ o $\binom{n}{k}$)
* **Quando si usa:** Si sceglie un sottoinsieme di $k$ elementi da $n$ distinti e l'ordine di scelta non ha importanza.
* **Caratteristiche:**
  * L'ordine **NON conta**.
  * **Senza** ripetizione.
* **Esempi tipici:**
  * Formare comitati o squadre di $k$ persone.
  * Estrazioni del lotto o combinazioni per tornei.

---

## 7. Combinazioni con Ripetizione (${C'}_{n,k}$)
* **Quando si usa:** Si scelgono $k$ oggetti da $n$ categorie, senza considerare l'ordine, e gli oggetti di una categoria possono essere scelti più volte.
* **Caratteristiche:**
  * L'ordine **NON conta**.
  * **Con** ripetizione.
* **Esempi tipici:**
  * Lanci simultanei di $k$ dadi (dove conta solo il numero di ricorrenze di ciascuna faccia).
  * Acquisto di $k$ oggetti scelti tra $n$ tipi diversi con scorta illimitata.

---

## 8. Powerset / Insieme delle Parti ($\mathcal{P}(S)$)
* **Quando si usa:** Quando bisogna esplorare **tutti i possibili sottoinsiemi** di un insieme $S$, di qualsiasi dimensione (incluso l'insieme vuoto).
* **Caratteristiche:**
  * Ogni elemento ha una scelta binaria: **incluso (1)** o **escluso (0)**.
  * Dimensione dello spazio delle soluzioni: $2^n$.
* **Vettore di soluzione (`sol`):** Vettore di flag booleani/interi `sol[pos] = 0` oppure `1`.
* **Esempi tipici:**
  * *Problema dello zaino (Knapsack)*: scegliere quali oggetti mettere nello zaino per massimizzare il valore.
  * *Somma di sottoinsiemi (Sum of Subsets)*: trovare sottoinsiemi la cui somma è pari a un target.

---

## 9. Partizioni di un Insieme
* **Quando si usa:** Quando bisogna **suddividere l'intero insieme di $n$ elementi** in $k$ blocchi (o un numero variabile di blocchi) **non vuoti e disgiunti**.
* **Caratteristiche:**
  * **Ogni elemento deve appartenere obbligatoriamente a uno e un solo blocco** (nessun elemento viene scartato o duplicato).
  * La dimensione totale cresce secondo i *Numeri di Bell* ($B_n$).
* **Vettore di soluzione (`sol`):** `sol[pos]` contiene l'indice del blocco a cui è stato assegnato l'elemento `pos`.
* **Algoritmi di riferimento:** Algoritmo di Er oppure Disposizioni con Ripetizione modificate con controllo sulle occorrenze dei blocchi.
* **Esempi tipici:**
  * Problemi di clustering o raggruppamento di tutti i dati disponibili.
  * Ripartizione di $n$ risorse tra $k$ processi senza lasciare risorse inutilizzate.

---

## Tabella Riassuntiva

| Modello | Ordine conta? | Ripetizione? | N. Elementi usati | Vettore Soluzione (`sol`) |
| :--- | :---: | :---: | :---: | :--- |
| **Disposizioni Semplici** | Sì | No | $k \le n$ | Valori/Indici presi dagli $n$ disponibili |
| **Disposizioni Ripetute** | Sì | Sì | $k$ qualsiasi | Indici tra $0$ e $n-1$ per ogni posizione |
| **Permutazioni Semplici** | Sì | No | Tutti ($k = n$) | Riordinamento dell'insieme iniziale |
| **Permutazioni Ripetute** | Sì | Sì (limitate) | Tutti ($k = n$) | Riordinamento con gestione scorte |
| **Combinazioni Semplici** | No | No | $k \le n$ | Sottoinsieme ordinato (per evitare duplicati) |
| **Combinazioni Ripetute** | No | Sì | $k$ qualsiasi | Conteggio/Frequenza delle scelte |
| **Powerset** | No | No | Variabile ($0 \dots n$) | Flag binari (`0` = escluso, `1` = incluso) |
| **Partizioni Insieme** | No | No | Tutti ($n$) | Indice del blocco a cui appartiene l'elemento |
