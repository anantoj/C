// converts integer to binary

#include <stdio.h>

int main(void)
{
    int decimal;
    printf("Enter decimal number: ");
    scanf("%d", &decimal);

    int bit;
    printf("Enter number of bits: ");
    scanf("%d", &bit);

    printf("Binary: ");

    for (int i = bit-1; i>=0; i--)
    {
        int k = decimal >> i;

        if (k & 1)
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
    }
    printf("\n");
}