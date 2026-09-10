#include <stdio.h>
int main(void)
{
    int a = 5;
    int *ptr = &a;

    //LUNGHEZZA = sizeof(v)/sizeof(cella)
    int v[5] = {1,2,3,4,5};
    int *ptrV = v; //OPPURE *ptrV = &v[0]

    //MATRICE
    int m[2][3] = {
        {10, 20, 30},
        {40, 50, 60}
    };

    //P
    int *ptrM1 = &m[0][0]; //PUNTATORE AL PRIMO ELEMENTO
    int *ptrM2 = m[1]; //PUNTATORE AL PRIMO ELEMENTO DELLA SECONDA RIGA

    //INDIRIZZO PUNTATO DAL PUNTATORE
    printf("Indirizzo puntato dal puntatore: %p\n",ptr);
    //INDIRIZZO DEL PUNTATORE
    printf("Indirizzo del puntatore: %p\n",&ptr);
    //STAMPO TRAMITE VARIABILE
    printf("Valore di a: %d\n",a);
    //DEFERENZIAZIONE DEL PUNTATORE
    printf("Valore di a (deferenziando puntatore): %d\n", *ptr);
    //INDIRIZZO DI PARTENZA DEL VETTORE
    printf("Indirizzo di partenza del vettore: %p\n",v);
    //INDIRIZZO DI PARTENZA DEL VETTORE
    printf("Indirizzo di partenza del vettore: %p\n",ptrV);
    //CONTENUTO DEL TERZO ELEMENTO TRAMITE VETTORE
    printf("Contenuto del terzo elemento tramite vettore: %d\n",v[2]);
    //CONTENUTO DEL TERZO ELEMENTO TRAMITE PUNTATORE
    printf("Contenuto del terzo elemento tramite puntatore: %d\n",*(ptrV+2));
    //CONTENUTO DEL SECONDO ELEMENTO SOMMATO DI 2 TRAMITE VETTORE
    printf("Contenuto del secondo elemento tramite vettore a cui sommo 2: %d\n",v[1]+2);
    //CONTENUTO DEL SECONDO ELEMENTO SOMMATO DI 2 TRAMITE PUNTATORE
    printf("Contenuto del secondo elemento tramite puntatore a cui sommo 2: %d\n", *(ptrV+1)+2);

    //STAMPO V TRAMITE VETTORE
    printf("Stampo elementi di v tramite VETTORE\n");
    for(int i=0;i<(sizeof(v) / sizeof(v[0]));i++)
    {
        printf("%d ",v[i]);
    }

    //STAMPO celle v TRAMITE VETTORE
    printf("\nStampo celle di v tramite VETTORE\n");
    for(int i=0;i<(sizeof(v) / sizeof(v[0]));i++)
    {
        printf("%p ",&v[i]);
    }
    //STAMPO v TRAMITE PUNTATORE
    printf("\nStampo valori di v tramite PUNTATORE\n");
    for(int i=0;i<(sizeof(v) / sizeof(v[0]));i++)
    {
        printf("%d ",*(ptrV + i));
    }

    //STAMPO V TRAMITE puntatore
    printf("\nStampo celle di v tramite PUNTATORE\n");
    for(int i=0;i<(sizeof(v) / sizeof(v[0]));i++)
    {
        printf("%p ",ptrV+i);
    }

    //AGGIORNO CELLA-0 A 2 USANDO VETTORE
    v[0] = 2;
    printf("\nAggiorno cella 0 al valore 2 usando VETTORE: %d\n",v[0]);
    //AGGIORNO CELLA-1 A 7 USANDO Puntatore
    *(ptr+1) = 7;
    printf("\nAggiorno cella 1 al valore 7 usando VETTORE: %d\n",*(ptr+1));


    //Stampo elemento i,j con MATRICE
    printf("\nStampo elemento i,j con MATRICE: %d\n",m[1][2]);
    printf("Valore [1][1] con ptrM1: %d\n", *(ptrM1 + (1 * 3) + 1)); // Oppure *(ptrM1 + 4)
    // 2. Indirizzo della posizione [1][1] usando ptrM1
    printf("Indirizzo [1][1] con ptrM1: %p\n", ptrM1 + 4);
    // 3. Valore della posizione [1][1] usando ptrM2 (partendo già da m[1][0])
    printf("Valore [1][1] con ptrM2: %d\n", *(ptrM2 + 1));
    // 4. Indirizzo della posizione [1][1] usando ptrM2
    printf("Indirizzo [1][1] con ptrM2: %p\n", ptrM2 + 1);
}
