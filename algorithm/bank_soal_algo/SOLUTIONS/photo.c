#include <stdio.h>

int main(void){

    int cases;
    scanf("%d", &cases);

    for (int tc = 0; tc < cases; tc++){
        int n;
        scanf("%d", &n);

        for (int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if (i == 1 || i == n || j == 1 || j == n){
                    printf("#");
                }
                else{
                    printf(" ");
                }
            }
            printf("\n");
        }
    }
}