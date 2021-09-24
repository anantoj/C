// bubble sort, selection sort, insertion sort

#include <stdio.h>

void bubbleSort (int *arr, int size)
{
    for (int a = 0; a < size - 1; a++)
    {
        for (int b = 0; b < size - a - 1; b++)
        {
            if (arr[b] < arr[b+1])
            {
                int tmp = arr[b];
                arr[b] = arr[b+1];
                arr[b+1] = tmp;
            }
        }
    }
}

void selectionSort (int *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int max_idx = i;
        for (int j = i+1; j < size; j++)
        {
            if (arr[max_idx] < arr[j])
            {
                max_idx = j;
            }
        }
        int tmp = arr[i];
        arr[i] = arr[max_idx];
        arr[max_idx] = tmp;
    }
}

void insertionSort (int *arr, int size)
{
    for (int i = 1; i < size; i++)
    {
        int value = arr[i];
        int j = i - 1 ;

        while (j >= 0 && (arr[j] > value))
        {
            arr[j+1] = arr[j];
            j--;
            
        }
        arr[j+1] = value;
    }
}

void swap(int *a, int*b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int *arr, int low, int high){
    int pivot = arr[high]; 
    int i = low - 1;

    for (int j = low; j < high; j++){
        if (arr[j] < pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i+1], &arr[high]);
    return i+1;
}

void quickSort(int *arr, int low, int high){
    if (low < high){
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

int main(void)
{
    int arr[] = {2,5,10,7,3};
    
    int num = sizeof(arr) / sizeof(int);

    // insertionSort(arr, num);

    quickSort(arr, 0, num-1);

    for (int j = 0; j < num; j++)
    {
        printf("%d ", arr[j]);
    }
    printf("\n");
    
}