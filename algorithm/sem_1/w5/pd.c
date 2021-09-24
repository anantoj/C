#include <stdio.h>

int main(void){
    int cases;
    scanf("%d", &cases);

    for (int tc = 0; tc < cases; tc++){
        int size;
        scanf("%d", &size);

        int jojo[size][size];
        int bibi[size][size];
        int lili[size][size];

        for (int i = 0; i < size; i++){
            for (int j = 0; j < size; j++){
                scanf("%d", &jojo[i][j]);

            }
        }  
        for (int i = 0; i < size; i++){
            for (int j = 0; j < size; j++){
                scanf("%d", &lili[i][j]);

            }
        }  
        for (int i = 0; i < size; i++){
            for (int j = 0; j < size; j++){
                scanf("%d", &bibi[i][j]);

            }
        }  
        int tmp[size][size];
        for (int i = 0; i < size; i++){
            for (int j = 0; j < size; j++){
                tmp[i][j] = 0;
                for (int k = 0; k < size; k++){
                    tmp[i][j] += lili[i][k] * bibi[k][j];
                }
            }
        }


        int ans[size][size];
      
        for (int i = 0; i < size; i++){
            for (int j = 0; j < size; j++){
                ans[i][j] = 0;
                for (int k = 0; k < size; k++){
                    ans[i][j] += tmp[i][k] * jojo[k][j];
                }
            }
        }

        printf("Case #%d:\n", tc+1);
        for (int i = 0; i < size; i++){
            printf("%d", ans[i][0]);
            for (int j = 1; j < size; j++){

                printf(" %d", ans[i][j]);

            }
            printf("\n");
        }  
    }
}