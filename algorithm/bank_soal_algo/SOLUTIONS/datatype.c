#include <stdio.h>

int main(void)
{
    int cases;
    scanf("%d", &cases);

    for (int tc = 0; tc < cases; tc++)
    {
        long long num;
        scanf("%lld", &num);

        if (num > 2147483647)
        {
            printf("Case #%d: long long\n", tc+1);
        }
        else
        {
            printf("Case #%d: integer\n", tc+1);
        }
    }
}