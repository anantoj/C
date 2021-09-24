#include <stdio.h>

// how to initialize and access and array

int main(void)
{
    int A[10] = {1,2,3,4,5,6,7,8,9,10};
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");

    // Partial Assignment
    int B[10] = {1,2,3};
    for (int i =0; i < 10; i++)
    {
        printf("%d ", B[i]); // the rest of unsigned elements will be 0
    }
    printf("\n");

    // No assignment
    int C[10];
    for (int i = 0; i <10; i++)
    {
        printf("%d ", C[i]); // this will print out garbage values that are previously in the memory space
    }
    printf("\n");
}