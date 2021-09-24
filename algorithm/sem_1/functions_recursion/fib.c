#include<stdio.h>

int f(int n)
{
    if (n == 0 || n == 1)
        return n;
    else
        return (f(n-1) + f(n-2));
}


int main()
{
    int n;
    int i = 0; // NOTE: Fibonnaci recursion starts the index at zero;
    int c;

    scanf("%d", &n);

    printf("Fibonacci series terms are:\n");

    for (c = 1; c <= n; c++)
    {
        printf("%d\n", f(c));
        i++;
    }

    return 0;
}



/*
    fib 4 = fib 3 + fib 2 == 2 + 1 == 3;

    fib 3 = fib 2 + 1 == 2

    fib 2 = 1 + 0 == 1

*/