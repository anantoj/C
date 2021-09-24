#include <stdio.h>

void insertionSort(long long *arr, int size){
    for (int i = 1; i < size; i++){
        long long value = arr[i];
        long long j = i - 1;

        while (j >= 0 && arr[j] > value){
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = value;
    }
}

int main(void){
    int cases;
    scanf("%d", &cases);

    for(int tc = 0; tc < cases; tc++){
        long long arr[25];
        long long sum = 0;
        for (int i = 0; i < 25; i++){
            scanf("%lld", &arr[i]);
            sum += arr[i];
        }

        insertionSort(arr, 25);

        long long a,b,c,d,e;

        // for (int i = 0; i < 25; i++){
        //     printf("%lld ", arr[i]);

        // }

        a = arr[0] / 2;

        e = arr[24] / 2;

        b = arr[1] - a;
        
        d = arr[23] - e;

        c = (sum - 10*a - 10*b - 10*d - 10*e) / 10;

        printf("Case #%d: %lld %lld %lld %lld %lld\n", tc+1, a, b, c, d, e);
    }

}