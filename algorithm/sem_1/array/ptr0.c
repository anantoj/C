#include <stdio.h>

int main(void)
{
    int i = 0;
    int *ptr;

    ptr = &i; // the pointer ptr now points to the address of i
    *ptr = 5;

    printf("Content : %d\n", i);
    printf("Value of *ptr: %d\n", *ptr);
    printf("Pointer address: %p\n", ptr);

    // remeber that to print the address that a pointer is pointing to
    // you use %p
}