#include <stdio.h>

int formula(int n, int *counter){
    if (n == 3 || n == 4) *counter= *counter + 1;

    if (n == 0) return 1;
    if (n == 1) return 2;

    if (n%3 == 0) return formula(n-n/3,counter)+1;
    // no need to *counter or &counter
    // or else it will be a double pointer/address (ptr to ptr)

    return formula(n-1,counter) + n + formula(n-2,counter) + 1;

}

int main(void){
    int cases;
    scanf("%d", &cases);

    for (int tc = 0; tc < cases; tc++){
        int num;
        scanf("%d", &num);

        int counter = 0;
       
        int ans = formula(num, &counter);
        printf("Case #%d: %d %d\n",tc+1, ans, counter);

    }
}