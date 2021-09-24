#include <stdio.h>
#include <math.h>

// const double e = 2.718281828459045;

int main(void){

    int cases;
    scanf("%d", &cases);

    for (int tc = 0; tc < cases; tc++){
        double a,b,c;

        scanf("%lf %lf %lf", &a, &b, &c);

        double ln = log(a); // ln  a

        double x = b * ln; 


        if (x < c){
            printf("Case #%d: <\n", tc+1);
        }
        else{
            printf("Case #%d: >\n", tc+1);
        }
    }
}