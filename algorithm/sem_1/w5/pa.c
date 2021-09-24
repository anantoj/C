#include <stdio.h>

int main(void){
    int a = 0;
    int b = 0;
    int c = 0;

    scanf("%d %d %d", &a, &b, &c);

    int time = 0;

    int x = b - c;
    int y = c - a;

    if (x == y){
        printf("%d\n",x);
    }
    else printf("%d\n", -1);
}