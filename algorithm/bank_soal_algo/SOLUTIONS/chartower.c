#include <stdio.h>

int main(void)
{
    int height;

    scanf("%d", &height);

    int counter = 1;
    int ascii = 65;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j< height - i; j++)
        {
            if (i + j == height -1)
            {
                char alphabet = (ascii + (i%26));
                for (int k = 0; k < counter; k++)
                {
                    if (k == 0) printf("%c", alphabet);
                    else printf(" %c", alphabet);
                }
            }
            else
            {
                printf(" ");
            }
        }
        counter++;
        printf("\n");
    }
}