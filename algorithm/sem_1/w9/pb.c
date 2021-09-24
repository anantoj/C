#include <stdio.h>

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int *arr, int low ,int high){
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
    int size;
    scanf("%d", &size);

    int odd[size];
    int even[size];
    
    int oddidx = 0, evenidx = 0;
    int num;

    for (int i = 0; i < size; i++){
        scanf("%d", &num);

        if (num % 2 == 0){
            even[evenidx] = num;
            evenidx++;
        }
        else{
            odd[oddidx] = num;
            oddidx++;
        }
    }

    quickSort(odd, 0, oddidx - 1);
    quickSort(even, 0, evenidx - 1);

    int cases;
    scanf("%d", &cases);

    for (int tc = 0; tc < cases; tc++){
        int max;
        scanf("%d", &max);

        int oddCounter = 0;
        int oddFlag = 0;

        for (int i = oddidx -1; i >= 0; i--){

            if (oddFlag == 1) break;

            if (odd[i] >= max){
                oddCounter += i;
                continue;
            }
            else{
                for (int j = 0; j <= i; j++){
                    if (odd[i] + odd[j] >= max){
                        oddCounter += (i - j);
                        break;
                    }
                    else if (j == i - 1){
                        oddFlag = 1;
                    }
                }
            }
        }

        int evenCounter = 0;

        int evenFlag = 0;
        for (int i = evenidx -1; i >= 0; i--){

            if (evenFlag == 1) break;

            if (even[i] >= max){
                evenCounter += i;
                continue;
            }
            else{
                for (int j = 0; j <= i; j++){
                    if (even[i] + even[j] >= max){
                        evenCounter += (i - j);
                        break;
                    }
                    else if (j == i -1){
                        evenFlag = 1;
                    }
                }
            }
        }

        printf("Case #%d: %d %d\n", tc+1, oddCounter, evenCounter);
    }
}