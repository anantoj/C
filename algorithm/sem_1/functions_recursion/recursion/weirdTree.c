#include <stdio.h>

int foo(int n, int m){
    if (m == 0) return 1;
    printf("%d %d\n", n,m);
    int x =  ((foo(n-1,m-1)) * (n-1) + (m));
    printf("x = %d\n", x);
    return x;
}

int main(void){
    int cases;
    scanf("%d", &cases);

    for (int tc = 0; tc < cases; tc++){
        int n, m;

        scanf("%d %d", &m, &n);

        int ans = foo(n,m);
        printf("%d\n", ans);
    }
}