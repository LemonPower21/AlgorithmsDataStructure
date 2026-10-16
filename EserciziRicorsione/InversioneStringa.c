#include <stdio.h>

void invertistringa(char *s,int l,int r)
{
    //SONO ALLA FINE
    if(l>=r)
    {
        return;
    }
    char temp= s[l];
    s[l]= s[r];
    s[r]=temp;
    invertistringa(s,l+1,r-1);
}
int main(void)
{
    char s[10] = "ciaobella\0";
    invertistringa(s,0,8);
    printf("%s",s);
    return 0;
}