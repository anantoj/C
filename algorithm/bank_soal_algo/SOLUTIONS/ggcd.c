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

int GCD(int a, int b){
    if (a < b)
        return GCD(b,a);
    if (b != 0)
        return GCD(b,a%b);
    return a;
}

int main(void){
    int cases;
    scanf("%d", &cases);

    for (int tc = 0; tc <cases; tc++){
        int size;
        scanf("%d", &size);
        
        int arr[size];
        
        for (int i = 0; i < size; i++){
            scanf("%d", &arr[i]);
        }

        quickSort(arr, 0, size-1);

        int ans = 0;

        for (int i = 0 ; i < size-1; i++){
            for (int j = i+1; j < size;j++){
                int tmp = GCD(arr[j], arr[i]);
                if (tmp > ans){
                    ans = tmp;
                }
            }
        }

        printf("Case #%d: %d\n",tc+1,ans);
    }
}