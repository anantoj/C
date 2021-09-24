#include <stdio.h>

// Fibonacci's Numbers:
// 0 1 1 2 3 5 8 13 21...

int fib(int n){
    if (n == 1) return 0;
    if (n == 2) return 1;
    return fib(n-2) + fib (n-1);
}
int main(void){
    printf("Fibonacci: %d\n", fib(9));
}