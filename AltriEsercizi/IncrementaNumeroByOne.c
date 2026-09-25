#include <stdio.h>
void sumone(int *a)
{
    (*a)++;
}
int main(void)
{
    int a = 10;
    printf("Sommando 1 a %d",a);
    sumone(&a);
    printf(" ottengo %d",a);
}