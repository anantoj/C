#include <stdio.h>

int main(void)
{
    int x, y;
    int *ptrx, *ptry, *ptrz;

    ptrx = &x;
    ptry = &y;
    // ptrz is currently not pointing to anything

    printf("Pointers of x and y: \n");
    printf("&x: %p %p\n", ptrx, &x);
    printf("&y: %p %p\n", ptry, &y);

    printf("&x+1: %p\n", ptrx+1); // CHEAT be careful
    printf("Values of x, y, and ptrz: %d %d %p\n", x,y,ptrz);

    // Note 1: Uninitialized variables have trash in them
    // Note 2: On line 14, there is no guarantee that 
    //         &x and &y will be close to each other
}