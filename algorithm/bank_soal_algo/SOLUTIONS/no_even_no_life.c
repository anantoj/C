#include <stdio.h>

int main(void){
    int cases;
    scanf("%d", &cases);

    for (int tc = 0; tc < cases; tc++){
        int jojo = 0;
        int bibi = 0;

        int n;
        scanf("%d", &n);

        int num;
        for (int i = 0; i < n; i++){
            scanf("%d", &num);
            if (i %2 == 0){
                if (num % 2 == 0){
                    jojo++;
                }
            }
            else if (num %2 != 0){
                bibi++;
            }
        }

        if (jojo %2 == 0 && bibi %2 != 0){
            printf("Case #%d: :|\n", tc+1);
        }
        else if (jojo %2 == 0){
            printf("Case #%d: :)\n", tc+1);
        }
        else{
            printf("Case #%d: :(\n", tc+1);
        }
    }
}