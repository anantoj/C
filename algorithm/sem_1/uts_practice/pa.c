#include <stdio.h>

int main(void)
{
    int cases;
    scanf("%d", &cases);

    for (int i = 0; i < cases; i++)
    {
        int max, left, mid, right;
        scanf("%d %d %d %d", &max, &left, &mid, &right);

        int num = left + (2*mid) + (3*right);
        int lmr = left + mid + right;
        if (num == max)
        {
            printf("Case #%d: %d\n", i+1, 1);
        }
        else
        {
            if ((max - num) % lmr == 0)
            {
                printf("Case #%d: %d\n", i+1, (max - num)/ lmr +1);
            }
            else
            {
                printf("Case #%d: -1\n", i+1);
            }
            
        }
    }
}