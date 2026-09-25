#include <stdio.h>
#include <ctype.h>
#include <string.h>

void primomaiusc(char *v)
{
    //NELLE FUNZIONE IL VETTORE DECADE A PUNTATORE... MEGLIO USARE STRLEN O PASSARLO PRIMA DELLA CHIAMATA AD UNA FUNZIONE COSTRUITA CON RICHIESTA DEL PARAMETRO
    for(int i=0;i<(strlen(v));i++)
    {
        if(i==0 && isalpha(v[i]))
        {
            v[i] = toupper(v[i]);
        }
        else if(isalpha(v[i]) && v[i-1]==' ')
        {
            v[i] = toupper(v[i]);
        }
        else if(isalpha(v[i]) && v[i-1]!=' ')
        {
            v[i] = tolower(v[i]);
        }
    }
    printf(" La stringa e': %s",v);
}
int main(void)
{
    char stringa[100] = "cHE bELLA gIORNATA";
    primomaiusc(stringa);
}