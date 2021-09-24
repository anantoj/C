#include <stdio.h>

// Fibonacci's Numbers:
// 0 1 1 2 3 5 8 13 21...

int fib(int n){
    if (n == 1) return 0;
    if (n == 2) return 1;
    return fib(n-2) + fib (n-1);
}

// void displayFib(int a){
//     for (int i = 1; i <= a; i++)
//     {
//         printf("%d ", fib(i));
//     }
// }

void displayNextFib(int a, int b, int n){
    int c = a + b;
    printf("%d ",c);
    if (n > 0) displayNextFib(b, c, n-1);
}

void displayFib(int n){
    if (n >= 1) printf("0 ");   // NOTE: Use >= and not ==
    if (n >= 2) printf("1 "); 
    if (n >= 3) displayNextFib(0, 1, n-3);
}

int main(void){

    displayFib(9);

    printf("\n");
}