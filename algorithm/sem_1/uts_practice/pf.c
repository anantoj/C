#include <stdio.h>
#include <math.h>
#include <string.h>

int main(void)
{
    int cases;
    scanf("%d", &cases);

    for (int tc = 0; tc < cases; tc++)
    {
        char str[100];
        scanf("%s", str);
        double DigitCounter = 0;
        for (int i = 0; i < strlen(str); i++)
        {
            if (str[i] == '0'|| str[i] == '1')
            {
                DigitCounter++;
            }
        }
        DigitCounter -= 1;
        
        double ans = 0;

        for (int i = 0; i < strlen(str); i++)
        {
            if (str[i] == '(')
            {
                ans -= pow(2, DigitCounter);
                DigitCounter--;
                i += 2;
            }
            else if (str[i] == '1')
            {
                ans += pow(2,DigitCounter);
                DigitCounter--;

            }
            else if(str[i] == '0')
            {
                DigitCounter--;
            }
        }
        printf("Case #%d: %.lf\n", tc+1, ans);
    }   
}

