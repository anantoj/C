 #include <stdio.h>

int main(void)
{
    int cases;
    scanf("%d", &cases);

    for (int tc = 0; tc < cases; tc++)
    {
        int size;
        scanf("%d", &size);

        char str1[size];
        char str2[size];

        scanf("%s %s", str1, str2);

        int ans[size];
        int extra = 0;

        for (int i = size-1; i >= 0; i--)
        {
            int a, b;
            a = str1[i] - '0';
            b = str2[i] - '0';
            ans[i] = (a+b + extra) % 10 ;
            if (a+b >= 10)
            {
                extra = 1;
            }
            else
            {
                extra = 0;
            }
        }

        if (extra == 0)
        {
            printf("Case #%d: ", tc+1);
        }
        else
        {
            printf("Case #%d: 1", tc+1);
        }

        for (int i = 0; i < size; i++)
        {
            printf("%d", ans[i]);
        }
        printf("\n");
    }
}