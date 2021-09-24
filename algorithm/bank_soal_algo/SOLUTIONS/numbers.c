#include <stdio.h>
#include <string.h>

int main(void)
{
    int cases;
    scanf("%d", &cases);

    for (int tc = 0; tc < cases; tc++)
    {
        unsigned long long l,r,a;

        int b;

        char str[20];

        scanf("%llu %llu %llu %d", &l, &r, &a, &b);

        printf("Case #%d:\n", tc+1);

        for (unsigned long long i = l; i <= r; i++)
        {
            if (i % a == 0)
            {
                printf("%llu ", i);
            }
            else
            {
                int flag = 0;
                sprintf(str, "%llu", i);
                for (int j = 0; j < strlen(str); j++)
                {
                    if ( b == str[j] - '0')
                    {
                        flag = 1;
                        break;
                    }
                    else continue;
                }
                if (flag == 1)
                {
                    printf("%llu ", i);
                }
            }
        }
        
        printf("\n");
    }
}