#include <stdio.h>

int main(void){
    int size;
    scanf("%d", &size);

    long tmp[size];
    for (int i = 0; i < size; i++){
        scanf("%ld", &tmp[i]);
    }

    int cases;
    scanf("%d", &cases);

    for (int tc = 0; tc < cases; tc++){
        long long max;
        scanf("%lld", &max);
        long arr[size];
        long long sum = 0;
        int count = 0;
        
        int ans = -1;

        int peng = 0;
        for (int i = 0; i < size; i++){
            // scanf("%ld", &arr[i]);
            arr[i] = tmp[i];
        
            if (sum + arr[i] <= max){
                sum += arr[i];
                count++;
                
            }
            else{
                if (ans < count){
                    ans = count;
                } 

                sum+=arr[i];
                count++;

                while(sum > max){
                    sum -= arr[peng];
                    peng++;
                    count--;
                }
                
            }
        }

        // for last if count longer than ans
        if (ans < count){
            ans = count;
        } 

        if (ans == 0){
            printf("Case #%d: -1\n",tc+1);
        }
        else{
            printf("Case #%d: %d\n",tc+1, ans);
        } 
    }
}