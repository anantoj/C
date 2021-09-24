#include <stdio.h>

int main(void){
    
    int a,b,c,d;

    int cases;
    scanf("%d", &cases);

    for (int tc = 0; tc < cases; tc++){
        int x = 0;
        int isfound = 0;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        while (x < 100000 && isfound == 0){ 
        // NOTE: Use && not || because only one of the conditions need to be broken to cancel the loop
            if (((a*x + b)%d) == c){
                isfound = 1;
            }
            else{
                x++;
            }
        }
        if (isfound == 1){
            printf("Case #%d: YES\n", tc+1);
        }
        else{
            printf("Case %d: NO\n", tc+1);
        }
    }
    
    return 0;
}