// inputs seperated by commas

#include <stdio.h>

int main(void)
{
    int a, b, c;
    printf("Input three numbers seperated by comma: ");
    scanf("%d,%d,%d", &a, &b, &c);

    printf("%d\n", a + b + c);
} 