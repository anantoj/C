#include <stdio.h>
#include <string.h>

int main(void)
{
    int cases;
    scanf("%d", &cases); getchar();

    for (int tc = 0; tc <cases; tc++)
    {
        int correctans;
        scanf("%d", &correctans); getchar();

        char str1[100001]; 
        char str2[100001];
        scanf("%s", str1); getchar();
        scanf("%s", str2); getchar();
        int diff = 0;
        int same = 0;
        for(int i = 0; i < strlen(str1); i++)
        {
            if (str1[i] != str2[i])
            {
                diff++;
            }
            else
            {
                same++;
            }       
        }

        int wrongans = strlen(str1) - correctans;

        int total = 0;

        if (correctans > same)
        {
            total += same;
        }
        else
        {
            total += correctans;
        }

        if (wrongans == diff)
        {
            total+=0;
        }
        else if (wrongans > diff)
        {
            total += diff;
        }
        else
        {
            total += wrongans;
        }

        printf("Case #%d: %d\n",tc+1, total);
    }
}