#include <stdio.h>

int main(void)
{
    int cases;
    scanf("%d", &cases);

    for (int i = 0; i < cases; i++)
    {
        int num;
        scanf("%d", &num);
        printf("Case #%d:\n", i+1);
        for (int j = 1; j <= num; j++)
        {
            if ((j % 3 == 0 || j % 5 == 0) && j % 15 != 0)
            {
                printf("%d Jojo\n", j);
            }
            else
            {
                printf("%d Lili\n", j);
            }
        }
    }
}