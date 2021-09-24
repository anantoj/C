#include <stdio.h>

int main(void)
{
    int a, b, c;
    
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);

    if (a%111 == 0)
    {
        printf("0.%d...\n", a/111);
    }
    else if (a < 10)
    {
        printf("0.00%d...\n",a);
    }
    else if (a < 100)
    {
        printf("0.0%d...\n",a);
    }
    else
    {
        printf("0.%d...\n", a);
    }
    if (b % 111 == 0)
    {
        printf("0.%d...\n", b/111);
    }
    else if (b < 10)
    {
        printf("0.00%d...\n",b);
    }
    else if (b < 100)
    {
        printf("0.0%d...\n",b);
    }
    else
    {
        printf("0.%d...\n",b);
    }
    if (c%111 == 0)
    {
        printf("0.%d...\n", c/111);
    }
    else if (c < 10)
    {
        printf("0.00%d...\n",c);
    }
    else if (c < 100)
    {
        printf("0.0%d...\n",c);
    }
    else
    {
        printf("0.%d...\n",c);
    }
}
