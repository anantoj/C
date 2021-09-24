#include <stdio.h>

int main(void){
    FILE *fp;
    fp = fopen("testdata.in", "r");

    if (fp != NULL){
        int a, b;
        fscanf(fp, "%d %d", &a, &b);
        printf("%d\n", a+b);
    }
}