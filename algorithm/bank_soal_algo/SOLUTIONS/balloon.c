#include <stdio.h>

int main(void)
{
    int num;
    unsigned long long power;
    scanf("%d %llu", &num, &power);

    unsigned long long balloon;
    int total = 0;
    for (int i = 0; i < num; i++)
    {
        scanf("%llu", &balloon);
        if (power > balloon)
        {
            total++;
        }
    }
    printf("%d\n", total);
}