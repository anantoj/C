#include <stdio.h>

// errors with pointers

int main(void)
{
    int x = 2, y = 2;

    int *ptrx, *ptry;
    ptrx = &x; 
    ptry = &y;

    *ptrx +=2;
    ptry += 2; // NOTICE THE ERROR

    // pointer of y (ptry) will now point to another address (+2) which has a garbage value

    printf("(x+2) + (y+2) = %d\n", *ptrx + *ptry);
    printf("ptrx = %p  *ptrx = %d\n", ptrx, *ptrx);
    printf("ptry = %p  *ptry = %d\n", ptry, *ptry);
}