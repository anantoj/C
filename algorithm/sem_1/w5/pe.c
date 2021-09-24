#include <stdio.h>

int main(void){

    // int cases;
    // scanf("%d", &cases);

    // for (int tc = 0; tc <cases; tc++){
    //     int sum;
    //     scanf("%d", &sum);

    //     int plus = 3;
    //     int ans = 1;
    //     for (int i = 0; i < sum; i++){
    //         ans+= (plus + i-1);
    //     }
    //     printf("Case #%d: %d\n", tc+1, ans);
    // }

    int sum;
    scanf("%d", &sum);

    int plus = 3;
    int ans = 1;
    for (int i = 0; i < sum; i++){
        ans+= (plus + i-1);
    }
    printf("%d\n", ans);
}