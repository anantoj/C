// display these variables
// a+ c, x + c,dx + x, ((int) dx) + ax, a + x, s + b, ax + b, s + c, ax + c, ax + ux

#include <stdio.h>

int main(void)
{
    int a = 125, b = 12345;
    long ax = 1234567890;
    short s = 4043;
    float x = 2.13459;
    double dx = 1.1415927;
    char c = 'W';
    unsigned long ux = 2541567890;

    printf("a + c =  %d\n", a + c);         // int + char = int
    printf("x + c = %f\n", x + c);          // float + char = float 
    printf("dx + x = %lf\n", dx + x);       // double + float = double OR float
    printf("((int) dx) + ax =  %ld\n", ((int) dx) + ax); // long + int = long  || how to typecast (int)var
    printf("a + x = %f\n", a + x);          // int + float = float
    printf("s + b =  %d\n", s + b);         // short + int = int
    printf("ax + b = %ld\n", ax + b);       // long + int = long
    printf("s + c =  %d\n", s + c);         // short + char = short
    printf("ax + c = %ld\n", ax + c);       // long + char = long
    printf("ax + ux = %ld\n", ax + ux);     // long + unsigned long = long OR unsigned long

    return 0;

/*  CONCLUSION:
        char = weakest
        float / double = strongest
        long stronger than int
*/

}