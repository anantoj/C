#include <stdio.h>

int main(void)
{
    int cases;
    scanf("%d", &cases);

    for (int tc = 0; tc < cases; tc++)
    {
        int books, change, volume;
        scanf("%d %d %d", &books, &change, &volume);

        int arr[books];

        for (int i = 1; i <= books; i++)
        {
            arr[i-1] = i;
        }

        for (int i = 0; i < change; i++)
        {
            int index = 0;
            while (arr[index] == -1)
            {
                index++;
            }
        
            for (int j = 0; j < volume; j++)
            {
                arr[index] = -1;
                index+= 1;
                index *=2;
                index -= 1;
                if (index > books)
                {
                    break;
                }
            }
        }

        int find = 0;

        while (arr[find] == -1)
        {
            if(find == books)
            {
                printf("Case #%d: -1\n", tc+1);
                break;
            }
            else find++;
        }

        if (find < books)
        {
            printf("Case #%d: %d\n", tc+1, find-1);
        }
    }
}