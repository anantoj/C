#include <stdio.h>

// pointers to pointers
int main(void)
{
    int x = 5;
    printf("x = %d\n", x);

    int *ptrx = &x; // you can also initialize a pointer like this
    printf("&x: %p\n", ptrx);

    int **ptrptrx = &ptrx; // ptrptrx is now pointing to the adress of ptrx
    printf("&(&x): %p\n", ptrptrx);

    int ***ptrptrptrx = &ptrptrx;
    printf("&(&(&x)): %p\n", ptrptrptrx);
}