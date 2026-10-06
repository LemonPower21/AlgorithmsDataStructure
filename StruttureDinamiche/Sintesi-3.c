/*
FUNZIONI RICORSIVE
    Tail-Recursive: Funzioni dove la chiamata ricorsiva è l'ultima operazione da eseguire, non si rischia overflow
         A) Mantengo costante occupazione di memoria a O(1)
         B) Non rischio StackOverflow
    Non-Tail-Recursive: Funzioni dove la chiamata ricorsiva non è l'ultima cosa ad esempio return n*funz() .... MOLTIPLICAZIONE NON SI PUO' FARE SE PRIMA CHIAMO LA FUNZIONE

    Tail Call Optimization (TCO): Il compilatore permette di ottimizzare le funzioni rendendole TAIL Recursive applicando ottimaziono O2 e O3 dello standard ISO.

    Esiste una dualità tra "ricorsione" e "iteratività" infatti algoritmi come quelli di fibonacci son facilmente replicabili con un ciclo for
    */






/*
ALGORITMI ORDINAMENTO RICORSIVI (CONCETTI DI BASE)
    - Dati da ordinare non sono sempre necessariamente interi
    - I dati appartengono aun tipo "Item" definito come struct
    1) Generalizzazione: un campo è la chiave, gli altri sono  dati aggiuntivi
    2) Posso leggere scrivere i dati di Item


    -Si parla dunque di ADT (Tipo di dato astratto)
    ADT I Classe: L'utente non sa nulla e vede solo quello che il programmatore permette di vedere
    Quasi ADT: L'utente può vedere qualcosa
    
    

    TIPOLOGIA ADT:
    1) Scalare con chiave coincidente
    2) Vettore dinamico di caratteri e chiave coincidente
    3) Vettore sovradimensionato STATICAMENTE in struct
    4) Vettore dinamico di caratteri in struct
    
    
ALGORITMI DI ORDINAMENTO RICORSIVI

    MERGE SORT: Simile al bottom-up merge sort (da 1 solo elemento fino n elementi ordinati). Il Mergesort invece spezza il vettore in
    vettori più picoli finchè non si arriva alla CONDIZIONE DI TERMINAZIONE: l=r oppure l>r cioè quando abbiamo finito di spezzare
    si rifonde in maniera ordinata

    -Si usa il (<=) per garantire stabilità dell'algoritmo

    MERGE SORT:
        1) NON IN LOCO: Usa vettore ausiliario (IL SUO LIMITE OLTRE AL FATTO CHE DIVIDE SEMPRE A META')
        2) STABILE: Usa il (<=) per confronti
        3) DATA-INDIPENDENT: Operazioni indipendenti dai dati, quindi worst=medio=best
        4) COMPLESSITA': THETA(N*log(N))
            COMBINE = THETA(N)
            DIVIDE = THETA(1)
            ....
    QUICKSORT:
        1) IN LOCO
        2) INSTABILE
        3) DATA-DEPENDENT: Devo distinguere i 3 casi
            -MIGLIORE: Due vettori ugualmente dimensionati THETA(NLOGN)
            -PEGGIORE: Un vettore da N-1 e vettore da 1 elemento THETA(N2)  quindi vince mergesort
            -MEDIO: Non è facilmente possibile definire il caso medio in quanto esso è data dependent
                    Posso concludere che i cammini sono logaritmici con base diversa: qualche ramo è piu diramato qualcunaltro no
            Infatti talvolta viene preso un pivot casuale che abbassa FATTORIALMENTE la possibilità di cadere nel caso peggiore generalmente la mediana

        Partizioniamo attraverso un elemento che diventa divisore con elementi a destra di lui maggiori dell'elemento e quelli
        alla sua sinistra sono più piccoli: divido in funzione dei dati. Trovo quindi coppie elementi disordinate scambiando rispettando
        che il pivot sia rispettato (piccoli a sx e grandi a dx) usa indice i in salita e indice j in discesa finche non trovo il pivot cioè i=j
        i parte da -1 j parte dalla fine "Partion" costa THETA(N)
        Viene usato WRAPPER che ci da l ed r

        */


/*
PROBLEMI RICERCA E OTTIMIZZAZIONE 
    SPAZIO DELLE SOLUZIONI:
        - Spazio soluzione inizialmente vuota
        - Incrementato  a pezzi

    STRUTTURE DATI PER RICERCA
        - CODA: ricerca in ampiezza FIFO
        - PILA: ricerca in profondità LIFO
        - CODA A PRIORITA': Ricerca è best-first
    ALGORITMO PER RICERCA:
        - INFORMATO: Sa tutto del problema
        - NON INFORMATO: Sa poco del problema
        - COMPLETO: Se esplora tutto spazio soluzioni
    SPAZIO SOLUZIONI E' RAPPRESENTATO DA:
        -Altezza n
        -Grado k
        -Radice (soluzione inizialmente vuota)
        -Nodi intermedi (soluzioni parziali)
        -Foglie (soluzioni)




I problemi informatici e matematici si suddividono principalmente in tre categorie: i problemi di calcolo, 
che si risolvono mediante procedimenti deterministici in un numero finito di passaggi; i problemi di ricerca, focalizzati sull'esplorazione 
di uno spazio di soluzioni per verificare l'esistenza o enumerare configurazioni valide; e i problemi di ottimizzazione, in cui si ricerca la soluzione 
migliore capace di minimizzare o massimizzare una specifica funzione obiettivo legata a costi o vantaggi. Per affrontare queste problematiche, l'esplorazione dello 
spazio delle soluzioni procede tipicamente in modo incrementale a partire da una configurazione vuota. A seconda della struttura dati adottata per gestire i nodi, come
 una coda FIFO per la ricerca in ampiezza, una pila LIFO per quella in profondità o una coda a priorità per l'approccio best-first, gli algoritmi possono muoversi nello spazio 
 di ricerca in modo informato o non informato. Questa struttura viene comunemente modellata come un albero di ricerca, in cui la radice rappresenta lo stato iniziale vuoto e le foglie corrispondono alle 
 soluzioni complete, un concetto applicabile anche a problemi pratici di scelta e combinazione. Alla base di questa analisi formale vi è il calcolo combinatorio, che studia il conteggio e la 
 classificazione degli elementi in base a criteri di unicità, ordinamento e ripetizione. In questo contesto, il principio di addizione stabilisce che la cardinalità di un insieme partizionato in
  sottoinsiemi disgiunti è pari alla somma delle loro dimensioni, mentre il principio di moltiplicazione definisce il numero complessivo di configurazioni ottenibili da sequenze di scelte indipendenti
   come il prodotto delle singole cardinalità.
*/