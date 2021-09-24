#include <stdio.h>

// accessing arrays through pointer arithmetic

int main(void)
{
    int A[10] = {1,2,3,4,5,6,7,8,9,10};

    for (int *T = A; *T != 10; T++)
    {
        printf("%d ", *T);
    }
    printf("\n");
    
    for (int *T = A+9; *T != 1; T--)
    {
        printf("%d ", *T);
    }
    printf("\n");
}