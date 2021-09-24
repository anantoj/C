#include <stdio.h>

int main(void){
    int arr[6][6];

    for (int i= 0; i < 6; i++){
        for (int j = 0; j < 6; j++){
            scanf("%d", &arr[i][j]);
        }
    }

    int max;

    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            int sum = 0;
            sum += arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i+1][j+1] +arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2];
            if (i == 0 && j == 0) 
                max = sum;
            else{
                if (sum > max) max = sum;
            }
        }
    }

    printf("%d\n", max);
    return 0;
}