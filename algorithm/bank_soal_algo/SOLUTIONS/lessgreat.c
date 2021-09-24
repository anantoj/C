#include <stdio.h>

int main(void)
{
    int cases;
    scanf("%d", &cases); getchar();

    for (int tc = 0; tc <cases; tc++)
    {
        char sign;
        scanf("%c", &sign);
        int num;
        scanf("%d", &num); getchar();

        if (sign == '>')
        {
            for (int i = 0; i < num; i++)
            {
                for (int j = 0; j < num; j++)
                {
                    if (i == j) printf("*");
                    else printf(".");                
                }
                printf("\n");
            }

            for (int i = 0 ; i < num; i++)
            {
                for (int j = 0; j < num; j++)
                {
                    if (i + j == num-1) printf("*");
                    else printf(".");
                }
                printf("\n");
            }
        }
        else
        {
            for (int i = 0 ; i < num; i++)
            {
                for (int j = 0; j < num; j++)
                {
                    if (i + j == num-1) printf("*");
                    else printf(".");
                }
                printf("\n");
            }
            for (int i = 0; i < num; i++)
            {
                for (int j = 0; j < num; j++)
                {
                    if (i == j) printf("*");
                    else printf(".");                
                }
                printf("\n");
            }
        }
    }
}