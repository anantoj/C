#include <stdio.h>

int main(void){
    int size;
    scanf("%d", &size);

    long arr[size];
    for (int i = 0; i <size; i++){
        scanf("%ld", &arr[i]);
    }

    int cases;
    scanf("%d", &cases);

    for (int tc = 0; tc <cases; tc++){
        long long sum = 0;
        long long find;
        scanf("%lld", &find);
        int index = 0;
        int notfound = 0;
        for (int i = 0; i < size; i+=2){
            if (i == 0 && sum + arr[0] > find){
                notfound = 1;
                break;
            }
            sum += (arr[i] + arr[i+1]);
            // printf("%ld %ld\n", arr[i], arr[i+1]);
            // printf("sum = %lld\n", sum);
            index+=2;
            if (sum >= find){
                break;
            }
        }
        int ans;
        if (notfound == 1){
            ans = -1;
        }
        else if (sum < find){
            ans = size;
        }
        else if (sum == find){
            ans = index;
        }
        else if (sum - arr[index-1] <= find){
            ans = index-1;
        }
        else if (sum - arr[index-1] - arr[index-2] <= find){
            ans = index - 2;
        }

        

        printf("Case #%d: %d\n", tc+1, ans);
    }


    
}