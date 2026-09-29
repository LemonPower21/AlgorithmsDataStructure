#include <stdio.h>
int main(void)
{
    //LEZIONE-1 ALLOCAZIONE DINAMICA
    /*
    -IMPLICITA: Non si vede, automatico
    -ESPLICITA: Controllata dal programmatore
    -DINAMICA:
        1) VIENE FATTO IN FASE ESECUZIONE
        2) PERMETTE DI CAMBIARE DIMENSIONE STRUTTURA DATI
        3) STRUTTURA DATI SARA' SOGGETTA ALL'AGGIUNTA E LA RIMOZIONI DEGLI ELEMENTI 
        
        VARIABILI SOGGETTE ALLE SEGUENTI REGOLE:
            1) ESISTENZA
            2) MEMORIA 
            3) VISIBILITA'
        VARUIABILI POSSONO ESSERE:
            1) GLOBALI:
                A) PERMANENTI
                B) DEFINITE FUORI DA FUNZIONI (ANCHE FUORI DA MAIN)
                C) GENERALMENTE DEFINITE  NELL'INTESTAZIONE DEL FILE.C

                VANTAGGI:
                - Accessibili da tutte le funzioni
                -Semplici ed efficienti
                SVANTAGGI:
                - Poco affidabili
            2) LOCALI:
               A) TEMPORANEE
               B) DEFINITE DENTRO LA FUNZIONE 
        ALTRO:
        - FUNZIONI IN C SONO DICHIARATE FUORI DALLA FUNZIONE CHE STO "VEDENDO"
        
    PROGRAMMA CHE ESEGUE UN ANALISI:
        - LESSICALE
        - SINTATTICO (ERRORE: inr)
        - SEMANTICO (ERRORE: int a="2.18")
    PROCESSO BUILD: 
        1) ANALISI
        2) CODICE OGGETTO
        3) LINKER: Chiama le librerie, file.c diversi e oggetti e genera eseguibile 
        4) LOADER: Prende eseguibile (e le sue istruzioni) e lo carica in RAM  
            A) CODICE 
            B) VARIABILI GLOBALI
            C) VARIABILI LOCALI E PARAMETRI FORMALI ---> stackframe allocate nello stack
            
    REGOLE DI ALLOCAZIONE AUTOMATICA
        A) Variabili GLOBALI e LOCALI hanno dimensione nota
        B) Vettori e Matrici  devono avere dimensione calcolabile
        C) I vettori come parametri formali decadono a puntatori*
        
        1) VARIABILI GLOBALI
            A) allocate all’avvio del programma
            B) restano in vita per tutto il programma
            C) ricordano i valori assegnati da funzioni
            D) l’attributo "static" limita la loro visibilità al file in cui compaiono

        2) VARIABILI LOCALI
            A) raggruppate con i parametri formali in uno stack frame
            B) allocate nello stack ad ogni chiamata della funzione
            C) deallocate automaticamente all’uscita dalla funzione
            D) non ricordano i valori precedenti

        3) VARIABILI LOCALI "STATIC"
            A) visibilità limitata alla funzione
            B) allocate assieme alle variabili globali
            C) ricordano i valori (della chiamata precedente)
    
    ALLOCAZIONE E RILASCIO ESPLICITI
        - Permettono di creare/distruggere dati in runtime
        - Dimensionare a runtime vettori o matrici
        
        ATTENZIONE: 
            1) La memoria dinamica si trova in un area chiamata HEAP
            2) Alla memoria dinamica si ACCEDE SOLO TRAMITE PUNTATORI
            - malloc: usata per allocazione (int *p = malloc(...))  dove p contiene un puntatore, (un vettore di interi)
            - free(p): liberiamo ciò a cui punta p  (facciamo de-allocazione)     

    DIMENSIONE DI STRUTTURE DATI
        - FISSA
        - MODIFICABILE
        - CONTENITORE: singoli dati allocati a pezzi

    FASI STRUTTURA DATI DINAMICA
        1) ALLOCAZIONE ESPLICITA
        2) UTILIZZO
        3) DISTRUZIONE

    DICHIARAZIONE MEMORIA DINAMICA (#include <stdlib.c>)
        void* malloc(size_t size)    #LA malloc() NON VUOLE CONOSCE I TIPI, bisogna solo dargli quanti "size" byte vuole allocare
        TIPO SIZE_T: intero senza segno
        
        - Al dato allocato si accede unicamente tramite puntatore
        - Il puntatore ritornato è opaco, tocca al programmatore passare al tipo
        desiderato mediante assegnazione a opportuna variabile puntatore

        SE s NON PUNTA A NULLA POSSO USARE sizeof(*s) se ho dichiarato già s!
            1) Conviene usare cast esplicito per IDENTIFICARE FACILMENTE ERRORI

    ERRRORI MALLOC
        1) DIMENSIONE RICHIESTA INFERIORE ALLA NECESSARIA
            (double *)malloc (sizeof(int))   #ESEMPIO CLASSICO DI ERRORE (Il concetto è quello che sta nella sizeof deve essere maggiore di quello che sta a cast)
        
        2) USO DEL "TIPO DEL PUNTATORE A DATO" RISPETTO A "PUNTATORE A DATO"
            p = (struct stud*)malloc(sizeof(struct(stud *)))  #ESEMPIO DI ERRORE: (Regola generale è avere un asterisco in più a sinistra)

        3) SCORDARE N NEL PRODOTTO PER FABBRICARE VETTORE
             v= malloc(sizeof(*v))  SBAGLIATO
             v = malloc(n*sizeof(*v))

    APPROFONDIMENTO
        Un vettore di puntatori è formalmente un puntatore a puntatori

    CONSEGUENZE ERRORI:
        1) SPRECO MEMORIA SE ALLOCO TROPPO
        2) SE ALLOCO MENO VADO IN "CRASH" (INDIRIZZO NON AMMESSO) OPPURE SPORCO ALTRI TIPO DI DATI
    
    TALVOLTA IN CASO DI ERRORI malloc() RITORNA NULL SE NON HA SPAZIO

    FUNZIONE calloc() E free()   #CLEAR AND ALLOC 
        1) PENSATA PER VETTORI
        2) COSTA O(N) A CAUSA AZZERAMENTO  (calloc() e realloc())
        3) COMPORTAMENTO MENO CASUALE SE SBAGLIO

        void* calloc(size_t n, size_t, size);    n=dimensione byte, size= quanti ne voglio!

        - In allocazione dinamica (cosi come i file) talvolta è meglio dare free (o chiudere file), soprattutto se abbiamo programmi complessi che funzionano per giorni

        void free(void* p)
        
        ATTENZIONE: SI POSSONO USARE SOLO PUNTATORI OTTENUTI CON MALLOC E CALLOC 
        ATTENZIONE: Se non faccio free potrei incorrere in dei memory leak ----> ALLOCO DINAMICAMENTE MEMORIA SENZA FARE FREE

    FUNZIONE realloc()   #FUNZIONE CHE PERMETTE DI ALLARGARE/STRINGERE VETTORI DINAMICI, RITORNANDO NUOVO PUNTATORE 
    
        void* realloc(void* p,size_t newsize)

        RIDUZIONE DI DIMENSIONE:
            1) Possibile sempre

        AUMENTO DI DIMENSIONE PUO' ESSERE:
            1) Possibile "In-place"
            2) Possibile ma altrove
            3) Impossibile

    VETTORI E MATRICI DINAMICHE
        VETTORI DINAMICI
            -Dimensione nota in esecuzione
            -Può variare riallocazione
            -Evitare il sovradimensionamento del vettore 
            (vedi Inverti.c /InvertiRealloc.c /InvertiReallocOpt.c)

        MATRICI DINAMICHE
            - Nelle funzioni come parametri formali non posso mettere **m perchè devo sapere sempre "Numero colonne"
            - SOLUZOONE MONODIMENSIONALE TRASPOSTA: L'elemento m[i][j] si trova in posizione [nc*i + j]  (Talvolta per stampare trasposta conviene mettere for-j esterno e for-i interno)
                v = (float *) malloc(nr*(nr*sizeof(float)))
            (vedi Trasposta.c)

            - SOLUZIONE BIDIMENSIONALE:
            (vedi TraspostaPtr.c)

        GENERALITA'
            1) VETTORI E MATRICI DINAMICI SONO ACCESSIBILI A PARTIRE DA UN PUNTATORE
            2) PUNTATORE E' UN DATO
            3) MATRICI E VETTORI SONO CREATI IN F SONO
                A) Generalmente usati in F
                B) Potrebbero essere usate da altre funzioni
            (vedi malloc2Dr.c e malloc2Dp.c)
            4) Per pulire vettore di puntatori devo prima deallocare le m[i] e in seguito la m

    VETTORI A DIMENSIONE VARIABILE (VLA)
        - Errore: ritornare vettore da funzione (return v)---> funzione viene cancellata dallo stack STAI SBAGLIANDO!





        */

}