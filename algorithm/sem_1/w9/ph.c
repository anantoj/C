#include <stdio.h>
#include <math.h>

int main(void){
    FILE *fp;
    fp = fopen("testdata.in", "r");

    int cases;
    fscanf(fp, "%d\n", &cases);
 
    for (int tc = 0; tc < cases; tc++){
        double num;
        fscanf(fp, "%lf\n", &num);
        
        double ans = cbrt(num);

        printf("Case #%d: %.0lf\n", tc+1, ans);

    }
}