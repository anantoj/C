// Triplenacci

#include <stdio.h>

int tri(int n){
    if (n == 1) return 2;
    if (n == 2) return 3;
    if (n == 3) return 4;
    return tri(n-3) + tri(n-2) + tri(n-1);
}

int main(void){
    int n = 9;
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", tri(i));
    }
    printf("\n");
}