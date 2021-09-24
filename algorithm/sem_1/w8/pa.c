#include <stdio.h>

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int *arr, int low, int high){
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high -1; j++){
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

int main(void){
    int cases;
    scanf("%d", &cases);

    for (int tc = 0; tc < cases; tc++){
        int size;
        scanf("%d", &size);

        int arr[5001];

        for (int i = 0; i <size; i++){
            scanf("%d", &arr[i]);
        }

        double sum = 0;

        for (int i = 0; i < size; i++){
            sum += arr[i];
        }

        double mean = sum / size;

        quickSort(arr,0, size-1);
        
        double median;

        if (size %2 != 0){
            int index = size - (size/2);
            median = (double)arr[index-1];
        }
        else{
            int x = arr[size/2-1];
            int y = arr[size/2];
            median = (double)(x+y)/2;
        }
        
        printf("Case #%d:\n",tc +1);
        printf("Mean : %.2lf\n", mean);
        printf("Median : %.2lf\n", median);


    }
}