#include <stdio.h>

void swap(int *a, int *b){
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

int main(void){
    FILE *fp;
    fp = fopen("testdata.in", "r");

    int cases;
    fscanf(fp, "%d\n", &cases);

    for (int tc = 0; tc < cases; tc++){
        int row, col;

        fscanf(fp, "%d %d\n", &row, &col);

        int size = row * col;

        int arr[size];
        
        for (int i = 0; i < size; i++){
            if (i+1 % col == 0)
                fscanf(fp, "%d\n", &arr[i]);
            else 
                fscanf(fp, "%d ", &arr[i]);
        }

        quickSort(arr, 0, size-1);

        if (size % 2 == 0){
            double median = 1.0 * ((double)arr[size / 2] + (double)arr[size/2 - 1]) / 2.0;
            int number = (arr[size/2] + arr[size/2-1])/2;
            double diff = median - number;
            if (diff < 0.5){
                printf("Case #%d: %d\n", tc+1, number);
            }
            else{
                printf("Case #%d: %d\n", tc+1, number+1);
            }
        }
        else{
            printf("Case #%d: %d\n", tc+1, arr[size/2]);
        }
    }
}