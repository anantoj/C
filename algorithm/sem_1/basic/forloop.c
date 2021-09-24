#include <stdio.h>

int main(void){
    printf("Input: ");
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            int numI = n-i+1;
            int numJ = n-j+1;
            if (numI > numJ){
                printf("%d ", numI);
            }
            else printf("%d ", numJ);
        }
        for (int j = n-1; j >= 1; j--){
            int numI = n-i+1;
            int numJ = n-j+1;
            if (numI > numJ){
                printf("%d ", numI);
            }
            else printf("%d ", numJ);
        }
        printf("\n");
    }

    for (int i = n-1; i >= 1; i--){     
        for (int j = 1; j <= n; j++){
            int numI = n-i+1;
            int numJ = n-j+1;
            if (numI > numJ){
                printf("%d ", numI);
            }
            else printf("%d ", numJ);
        }
        for (int j = n-1; j >= 1; j--){
            int numI = n-i+1;
            int numJ = n-j+1;
            if (numI > numJ){
                printf("%d ", numI);
            }
            else printf("%d ", numJ);
        }
        
        printf("\n");
    }
}