#include <stdio.h>

// Memory addresses for arrays are CONTINUOUS

int main(void)
{
    int A[10] = {1,2,3,4,5,6,7,8,9,10};

    for (int i = 0; i < 10; i++)
    {
        printf("A[%d] Address: %p  Content: %d\n", i, &A[i], A[i]);
    }
    printf("\n");

    // We can access the array by address or by index
    printf("A[3]: ptr: %p; Value: %d\n", &A[3], A[3]); // by index
    printf("A+3: ptr: %p; Value: %d\n", A+3, *(A+3));

    // Because arrays are just pointers
    // We can point/access values outside of the size of our array
    // But it must be relative to the position of the array
    printf("A[15] = %d", A[15]);
    printf("A[15000] = %d", A[15000]);

    int x = 69;

    printf("x = %d\n", x);
    printf("A[10] = %d\n", A[10]);
}