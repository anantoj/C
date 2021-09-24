# include <stdio.h> 
# include <math.h> 

int prime(double n)
{
    int flag = 1;
    for (int i = 2; i < (int)n / 2; i++)
    {
        if ((int)n % i == 0)
        {
            flag = 0;
            break;
        }
    }
    return flag;
}

int main(void)
{
    int cases;
    scanf("%d", &cases);

    for (int tc = 0; tc < cases; tc++)
    {
        int num;
        scanf("%d", &num);

        printf("Case #%d:\n", tc+1);

        double base = 2;
        double raise = 1;

        int sum = 0;

        while (1)
        {
            int count = num / pow(base, raise);
            sum += count;
            raise++;
            if (count == 0)
            {
                break;
            }
        }

        printf("%.0lf %d\n", base, sum);

        for (double base = 3; base<= num; base += 2)
        {
            if (prime(base) != 0)
            {
                sum = 0;
                raise = 1;
                while (1)
                {
                    int count = num / pow (base, raise);
                    sum += count;
                    raise++;
                    if (count == 0)
                    {
                        break;
                    }
                }
                printf("%.0lf %d\n", base, sum);
            }
        } 
    }
}