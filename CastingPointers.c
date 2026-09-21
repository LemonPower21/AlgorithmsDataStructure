#include <stdio.h>

int main() {
    // 1. Creiamo un intero. In esadecimale 0x11223344 mostra chiaramente i 4 byte.
    int numero = 0x11223344;  
    

    /*Per quanto concerne l'indirizzo 0x11 è il più significativo, 0x44 è il meno significativo SEMPRE. Se siamo in LITTLE ENDIAN (e sapendo che il primo byte è quello LSB il puntatore va da 0x44 a 0x11)
    mentre se usiamo BIG ENDIAN la lettura andrà dal MSB (cioè 0x11) al LSB cioè 0X44 in altri termini al byte0 big endian abbiamo 0x11*/

    // 2. IL CASTING CRUCIALE: Convertiamo il puntatore a int in un puntatore a char (INT=32bit CHAR=8bit)
    char *ptr_carattere = (char *)&numero;

    // 3. Accediamo carattere per carattere (byte per byte) modificando il puntatore
    printf("Byte 0: 0x%x\n", *ptr_carattere);       // Primo byte
    printf("Byte 1: 0x%x\n", *(ptr_carattere + 1)); // Secondo byte
    printf("Byte 2: 0x%x\n", *(ptr_carattere + 2)); // Terzo byte
    printf("Byte 3: 0x%x\n", *(ptr_carattere + 3)); // Quarto byte

    return 0;
}
