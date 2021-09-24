#include <stdio.h>

int checkArray (int *arr)
{
    for (int num = 1; num <=9; num++)
    {
        int counter = 0;
        for (int i = 0; i < 9; i++)
        {
            if (arr[i] == num)
            {
                counter++;
            }
        }
        if (counter > 1)
        {
            return 0;
        }
    }
    return 1;
}

int main(void)
{
    int cases;
    scanf("%d", &cases);

    int true = 0;
    for (int tc = 0; tc < cases; tc++)
    {
        int arr[9][9];
        for (int y = 0; y <9; y++)
        {
            for (int x = 0; x < 9; x++)
            {
                scanf("%d", &arr[y][x]);
            }
        }
        int counterc = 0;
        int counterr = 0;

        int save;

        for (int y = 0; y < 9; y++)
        {
            for (int check = 0; check < 9; check++)
            {
                save = arr[y][check]; // must be initialized first OUTSIDE the collumn checker
                for (int x = 0; x < 9; x++)
                {
                    if (x == check)
                    {
                        continue;
                    }
                    else if (arr[y][x] == save)
                    {
                        counterc = 1;
                        break;
                    }
                }
            }
        }

        if (counterc == 1)
        {
            printf("Case #%d: FALSE\n", tc+1);
            continue;
        }

        for (int x = 0; x < 9; x++)
        {
            for (int check = 0; check < 9; check++)
            {
                save = arr[check][x]; // must be initialized first OUTSIDE the collumn checker
                for (int y = 0; y < 9; y++)
                {
                    if (y == check)
                    {
                        continue;
                    }
                    else if (arr[y][x] == save)
                    {
                        counterr = 1;
                        break;
                    }
                }
            }
        }

        if (counterr == 1)
        {
            printf("Case #%d: FALSE\n", tc+1);
            continue;
        }

        // [a][b][c]
        // [d][e][f]
        // [g][h][i]
    
        int store[9];
        int storecounter = 0;
        int arraycheck = 1;

        // box a checker
        for (int y = 0; y < 3; y++)
        {
            for (int x = 0; x < 3; x++)
            {
                store[storecounter] = arr[y][x];
                storecounter++;
            }
        }
        arraycheck = checkArray(store);
        if (arraycheck == 0)
        {
            printf("Case #%d: FALSE\n", tc+1);
            continue;
        }

        // box b checker
        for (int y = 0; y < 3; y++)
        {
            for (int x = 3; x < 6; x++)
            {
                store[storecounter] = arr[y][x];
                storecounter++;
            }
        }
        arraycheck = checkArray(store);
        if (arraycheck == 0)
        {
            printf("Case #%d: FALSE\n", tc+1);
            continue;
        }

        // box c
        for (int y = 0; y < 3; y++)
        {
            for (int x = 6; x < 9; x++)
            {
                store[storecounter] = arr[y][x];
                storecounter++;
            }
        }
        arraycheck = checkArray(store);
        if (arraycheck == 0)
        {
            printf("Case #%d: FALSE\n", tc+1);
            continue;
        }

        // box d
        for (int y = 3; y < 6; y++)
        {
            for (int x = 0; x < 3; x++)
            {
                store[storecounter] = arr[y][x];
                storecounter++;
            }
        }
        arraycheck = checkArray(store);
        if (arraycheck == 0)
        {
            printf("Case #%d: FALSE\n", tc+1);
            continue;
        }

        // box e
        for (int y = 3; y < 6; y++)
        {
            for (int x = 3; x < 6; x++)
            {
                store[storecounter] = arr[y][x];
                storecounter++;
            }
        }
        arraycheck = checkArray(store);
        if (arraycheck == 0)
        {
            printf("Case #%d: FALSE\n", tc+1);
            continue;
        }

        // box f
        for (int y = 3; y < 6; y++)
        {
            for (int x = 6; x < 9; x++)
            {
                store[storecounter] = arr[y][x];
                storecounter++;
            }
        }
        arraycheck = checkArray(store);
        if (arraycheck == 0)
        {
            printf("Case #%d: FALSE\n", tc+1);
            continue;
        }

        // box g
        for (int y = 6; y < 9; y++)
        {
            for (int x = 0; x < 3; x++)
            {
                store[storecounter] = arr[y][x];
                storecounter++;
            }
        }
        arraycheck = checkArray(store);
        if (arraycheck == 0)
        {
            printf("Case #%d: FALSE\n", tc+1);
            continue;
        }

        for (int y = 6; y < 9; y++)
        {
            for (int x = 3; x < 6; x++)
            {
                store[storecounter] = arr[y][x];
                storecounter++;
            }
        }
        arraycheck = checkArray(store);
        if (arraycheck == 0)
        {
            printf("Case #%d: FALSE\n", tc+1);
            continue;
        }

        for (int y = 6; y < 9; y++)
        {
            for (int x = 6; x < 9; x++)
            {
                store[storecounter] = arr[y][x];
                storecounter++;
            }
        }
        arraycheck = checkArray(store);
        if (arraycheck == 0)
        {
            printf("Case #%d: FALSE\n", tc+1);
            continue;
        }
        

        printf("Case #%d: TRUE\n", tc+1);
        true++;
    }

    double percentage = (double)true / cases;

    printf("%.2lf%%\n", percentage *100);
}