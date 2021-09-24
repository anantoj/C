#include <stdio.h>

int main(void){
    FILE *fp;

    fp = fopen("testdata.in", "r");

    if (fp != NULL){
        int cases;
        
        fscanf(fp, "%d", &cases);

        for (int tc = 0; tc < cases; tc++){
            int n;
            fscanf(fp,"%d", &n);

            int arr[n];

            for (int i =0; i < n; i++){
                fscanf(fp, "%d", &arr[i]);
            }

            int peri = 2 *n + 2 *n + 2*arr[0] + 2*arr[n-1];

            printf("peri %d\n", peri); getchar();

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

            int total = 0;
            for (int i = 0; i< n; i++){
                total += arr[i];
            }

            printf("Case #%d: %d %d\n", tc+1, peri, total*2*2);
        }
    }
}