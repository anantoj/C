#include <stdio.h>

// int gcd(int a, int b){
//     if (a < b) 
//         return gcd (b,a);

//     if (b != 0)
//         return gcd(b, a%b);

//     return a;
// }

long long gcd(long long n, long long m)
{
    long long gcd, remainder;

    while (n != 0)
    {
        remainder = m % n;
        m = n;
        n = remainder;
    }

    gcd = m;

    return gcd;
}

int main(void){
    int cases;
    scanf("%d", &cases);

    for (int tc = 0; tc <cases; tc++){
        int n;
        long long x;
        scanf("%d %lld", &n, &x);

        long long denom = 1;
        long long num = x;

        for (int i = 0; i < n-1; i++){
            long long keep = num;
            num = num * x + denom;
            denom = keep;
        }       

        num = num / gcd(num,denom);
        denom = denom / gcd(num,denom);

        printf("Case #%d: %lld/%lld\n",tc+1, num, denom);
    }
}