#include <stdio.h>

int main(void)
{
    printf("Ciao");
    fflush(stdout);   //ESSO FORZA SVUOTAMENTO DEL BUFFER
    return 0;
}
