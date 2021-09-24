// Write a C program to shift an element in left direction and return a new array
// CARE: '==' operator

#include <stdio.h>

int main(void)
{
    int num;
    printf("Number of Elements: ");
    scanf("%d", &num);

    int arr[num];

    for (int i = 0; i < num; i++)
    {
        printf("Element %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    
    printf("Elements in original array:");
    for(int i = 0; i < num; i++)
    {
        if (i == num -1) // remember to use '==' operator when comparing!
            printf(" %d\n", arr[i]);
        else
            printf(" %d,", arr[i]);
    }
  

    for (int i = 0; i < num - 1; i++)
    {
        int tmp = arr[i];
        arr[i] = arr[i+1];
        arr[i+1] = tmp;
    }
    printf("Elements in new array:");
    for(int i = 0; i < num; i++)
    {
        if (i == num -1)
            printf(" %d\n", arr[i]);
        else
            printf(" %d,", arr[i]);
    }
   

}