#include <stdio.h>

int main(void){
    int cases;
    scanf("%d", &cases);

    for (int tc = 0; tc < cases; tc++){
        int n;
        scanf("%d", &n);

        int arr[n];

        for (int i =0; i < n; i++){
            scanf("%d", &arr[i]);
        }

        int peri = 2 *n + 2 *n + 2*arr[0] + 2*arr[n-1];

        for (int i = 0; i < n; i++){
            if ( i == n-1){
                continue;
            }
            else{
                if (arr[i] > arr[i+1]){
                    peri += 2*(arr[i] - arr[i+1]);
                }
                else if (arr[i] < arr[i+1]){
                    peri += 2*(arr[i+1] - arr[i]);
                }
            }
        }
        // printf("%d\n", peri);

        int total = 0;
        for (int i = 0; i< n; i++){
            total += arr[i];
        }

        // printf("%d\n", total*2*2);

        printf("Case #")
    }
}