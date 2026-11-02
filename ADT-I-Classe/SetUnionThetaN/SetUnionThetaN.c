#include <stdio.h>

int main(void)
{
    int set1[5] = {1,3,5,7,9};
    int set2[5] = {0,2,4,6,8};
    int size1 = 5, size2 = 5;
    int insiemeunion[10];                 /* size1 + size2: worst case */
    int i = 0, j = 0, k = 0;

    while (i < size1 || j < size2)
    {
        //ESAURIMENTO SET1
        if (i >= size1)                  
            insiemeunion[k++] = set2[j++];
        //ESAURIMENTO SET2
        else if (j >= size2)             
            insiemeunion[k++] = set1[i++];

        //3CASISTICHE
        else if (set1[i] < set2[j])
            insiemeunion[k++] = set1[i++];
        else if (set1[i] > set2[j])
            insiemeunion[k++] = set2[j++];
        else                              
        {
            insiemeunion[k++] = set1[i++];
            j++;
        }
    }

    for (int z = 0; z < k; z++)  
        printf("%d ", insiemeunion[z]);
    printf("\n");
    return 0;
}