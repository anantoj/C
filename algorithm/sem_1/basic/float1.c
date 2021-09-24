// a program that shows that there needs to be at least one float if "float var = int / int"
// importance of typecasting

#include <stdio.h>

int main(void)
{
    int a = 5;
    int b = 2;

    float c = (float)a / b; // if all variables are int, then there at least need to be  1 typecasting
    
    printf("%f\n", c);
}