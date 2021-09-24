#include <stdio.h>
#include <math.h>

int main(void){
    int cases;
    scanf("%d ", &cases);

    for (int tc = 0; tc < cases; tc++){
        long long num;
        scanf("%lld", &num);

        // long long total;
        
        // total = (num * num * num)  + 5 * num;
        // total /= 6;

        long long total = 0;

        for (int i = 1; i < num; i++){
            total += (num - i) * i;
        }

        total += num;



        printf("Case #%d: %lld\n", tc+1, total);
    }
}