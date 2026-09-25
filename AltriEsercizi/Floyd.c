#include <stdio.h>

void floyd(int n)
{
    int cnt = 1;
    int last = 1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<cnt;j++)
        {
            printf("%d ",last);
            last++;
        }
        printf("\n");
        cnt++;
    }
}
int main(void)
{
    int a =6;
    floyd(a);
    return 0;
}