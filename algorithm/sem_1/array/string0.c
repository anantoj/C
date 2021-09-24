#include <stdio.h>

int main(void)
{
    // Pointer of characters is the same as pointers to integers
    char a = 'a';
    char *ptr = &a;

    // we can initialize an array of chars
    // the same way as an array of int
    char str0[20] = {'c', 'l', 'a', 'u', 's'};

    // we can also initialize an array of chars
    // using "String Literals"
    char str1[20] = "BINUS";

    // Print the array of chars
    printf("str0 = %s\n", str0);
    
}