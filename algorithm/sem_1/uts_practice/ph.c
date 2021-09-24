#include <stdio.h>
#include <math.h>

int main(void)
{
    int cases;
    scanf("%d", &cases);

    for (int i = 0; i < cases;i++)
    {
        int n, a, b;
        
        scanf("%d %d %d", &n, &a, &b);
        
        int keep_b = b;
        int key = -1;
        int cycle = 0;
        while (key != a)
        {
            if (cycle != 0)
            {
                b *= keep_b;
            }
           
            int moda = a % n;
            int modb = b % n;
            key = (moda * modb) % n;

            cycle++;
        }
        printf("Case #%d: %d\n", i+1, cycle);
    }
}