#include <stdio.h>
#include <string.h>

int main(void)
{
    int cases;
    scanf("%d", &cases);


    for (int a = 0; a < cases; a++)
    {
        int slen;
        scanf("%d", &slen); getchar();
        char str[10000];
        scanf("%[^\n]s", str);
        printf("Case #%d: ", a+1);
        for (int i = 0; i < strlen(str); i++)
        {
            
            if (str[i] == ' ')
            {
                int Spacecounter = 1;
                int j = i;
                while (Spacecounter != 2)
                {
                    if (str[j+1] != ' ')
                    {
                        j++;
                    }
                    else
                    {
                        Spacecounter++;
                    }
                }
                i = j+1;
                printf(" ");
            }
            else printf("%c", str[i]);
        }
        printf("\n");
    }
}