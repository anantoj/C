#include <stdio.h>

int jobo(int n){
    if(n == 0) return 0;
    if(n == 1) return 1;
    if(n == 2) return 1;
    return jobo(n-1) + jobo(n-3);
}
int main(void){
    int n;
    scanf("%d", &n);

    int ans  = jobo(n);

    printf("%d\n", ans);
}