#include <stdio.h>

int main(void){

    char alpha[27] = "abcdefghijklmnopqrstuvwxyz";
    int cases;
    scanf("%d", &cases);

    for (int tc = 0; tc < cases; tc++){
        int n;
        scanf("%d", &n);
        printf("Case #%d: ", tc+1);
        for (int i = 0; i < n; i++){
            printf("%c", alpha[i]);
        }

        printf("\n");

    }
}