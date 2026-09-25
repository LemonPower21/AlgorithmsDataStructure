#include <stdio.h>
void controllaMatr(int m[4][4])
{
    int controllaR[4]={0}, controllaC[4]={0};
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(m[i][j]<0)
            {
                controllaC[j] +=1;
                controllaR[i] +=1;
            }
        }
    }
    for(int i=0;i<4;i++)
    {
        if(controllaR[i]==4)
        {
            printf("La riga %d e' negativa\n",i+1);
        }
        if(controllaC[i]==4)
        {
            printf("La colonna %d e' negativa\n",i+1);
        }
    }
}

int main(void)
{
    int m1[4][4] = {{1,2,3,4},{-1,-2,-3,-4},{1,0,1,0},{0,0,0,0}};
    int m2[4][4] = {{-1,2,3,4},{-1,+2,-3,-4},{-1,0,1,0},{-2,0,0,0}};    
    controllaMatr(m1);
    controllaMatr(m2);
}