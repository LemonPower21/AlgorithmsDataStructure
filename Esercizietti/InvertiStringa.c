//SCOPO: USARE RICORSIONE E STRDUP
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void InvertiStringa(char *s,int l, int r)
{
    if(l>=r)
    {
        printf("%s",s);
        return;
    }
    char t = s[l];
    s[l] = s[r];
    s[r] = t;
    InvertiStringa(s,l+1,r-1);
}
int main(void)
{
    char *s1 = (char *)malloc(sizeof(char)*256);
    printf("Inserire stringa massimo 255 caratteri: ");
    scanf("%s",s1);
    char *s2 = strdup(s1);
    int l=0;
    InvertiStringa(s2,l,strlen(s2)-1);
}