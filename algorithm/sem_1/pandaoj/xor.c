#include <stdio.h>

int main(void)
{
    int cases;
    scanf("%d", &cases);

    for (int tc = 0; tc < cases; tc++)
    {
        int num;
        scanf("%d", &num);
    
        int arr[num];

        for (int i = 0; i < num; i++)
        {
            scanf("%d", &arr[i]);
        }

        int counter = 0;
        
        int b, store;
        for (int i = 0; i < num-1; i++)
        {
            store = arr[i];
            for (int j = i+1; j < num; j++)
            {
                b = arr[j];
                store = store ^ b;
                if (store == 0) counter++;
            }
        }
        
        printf("Case #%d: %d\n", tc+1, counter);
    }
}