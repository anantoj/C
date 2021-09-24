#include <stdio.h>
#include <math.h>

long power(int x, unsigned long long y)
{
    int mod = 1000000007;
    unsigned long long tmp;
    if (y == 0)
    {
        return 1;
    }
    tmp = power(x , y/2);
    if (y % 2 == 0)
    {
        return (tmp * tmp) % mod;
    }
    else
    {
        return (x * tmp * tmp) % mod;
    }
}

int main(void)
{
    int cases;
    scanf("%d", &cases);

    for (int i = 0; i <cases; i++)
    {        
        int a,b;
        scanf("%d %d", &a, &b);

        long two = power(2,a);

        long three = power(3,b);

        long ans = (two * three) % 1000000007;        
        printf("%ld\n", ans);

    }
}