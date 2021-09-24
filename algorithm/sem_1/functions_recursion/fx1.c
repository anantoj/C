#include <stdio.h>

int addition(int a, int *b)
{
    int total = a + (*b);
    a = 5;  // passed by value
    *b = 5; // passed by reference
    return total;
}
int main(void)
{
    int a, b, c;

    a= 1;
    b = 2;
    c = addition(a,&b);

    printf("%d\n", c); 
    printf("After Addition:\n");
    printf("a = %d\n", a); 
    printf("b = %d\n", b);
}