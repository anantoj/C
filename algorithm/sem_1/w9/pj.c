#include <stdio.h>
#include <string.h>

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int binarySearch(int *arr, int size, int find){
    int left = 0;
    int right = size - 1;

    while (left <= right){
        int mid = (left + right) / 2;

        if (arr[mid] == find){
            return mid;
        }
        
        if (arr[mid] < find){
            left = mid+1;
        }
        else if (arr[mid] > find){
            right = mid -1;
        }
    }
    return -1;
}

// binary search GT does not return 0 indexed
int binarySearchGT(int *arr, int size, int find){
    int left = 0; 
    int right = size-1;
    int ans = size;

    while (left <= right){
        int mid = (left + right) / 2;

        if (arr[mid] > find){
            ans = mid;
            right = mid -1;
        }
        else left = mid+1;
    }

    return ans;
}


void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    /* create temp arrays */
    int L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
/* l is for left index and r is right index of the 
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l+(r-l)/2; 
  
        // Sort first and second halves 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
}

int partition(int *arr, int low, int high){
    int size = high - low;
    int pivot = arr[rand() % size + low];
    int i = low -1;
    
    for (int j = 0 ; j <high; j++){
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
    int size, operation;

    scanf("%d %d", &size, &operation);

    int arr[100000];

    for (int i = 0; i < size; i++){
        scanf("%d", &arr[i]); 
    }
    getchar();

    quickSort(arr,0, size-1);
    
    int index = size-1;

    for (int op = 0; op < operation; op++){

        char query;
        scanf("%c", &query);

        if (query == 'I'){
            int num;
            scanf("%d", &num); getchar();

            index += 1;
            arr[index]  = num;
        
            int track = index;

            for (int i = index-1; i >= 0; i--){
                if (arr[track] < arr[i]){
                    swap(&arr[i], &arr[track]);
                    track--;
                }
                else break; 
            }

            // int idx = binarySearchGT(arr, size, num);
            // memmove(&arr[idx+1], &arr[idx], sizeof(int) * (size - index));
            // arr[idx] = num;
            size += 1;

        }

        else if (query == 'A'){
            int num, change;
            scanf("%d %d", &num, &change); getchar();
            
            int x_idx = binarySearch(arr, size, num);
            int y_idx = binarySearchGT(arr, size, change);
            if (x_idx < y_idx){
                memmove(&arr[x_idx], &arr[x_idx+1], sizeof(int) * (y_idx-x_idx-1));
                arr[y_idx-1] = change;
            }
            else if (x_idx > y_idx){
                memmove(&arr[y_idx+1], &arr[y_idx], sizeof(int) * (x_idx-y_idx));
                arr[y_idx] = change;
            }

            // int target = binarySearch(arr, size, num);
            // arr[target] = change; 
            // int track = target;
            // if (target != 0 && arr[target-1] > arr[target]){
            //     // pindah ke kiri
            //     for (int i = target-1; i >= 0; i--){
            //         if (arr[track] < arr[i]){
            //             swap(&arr[i], &arr[track]);
            //             track--;
                        
            //         }
            //         else break;
            //     } 
            // }
            // else if (target != index && arr[target+1] < arr[target]){
            //     // pindah ke kanan
            //     for (int i = target+1; i <= index; i++){
            //         if (arr[track] > arr[i]){
            //             swap(&arr[i], &arr[track]);
            //             track++;
            //         }
            //         else break;
            //     } 
            // }
            
        }
        else if(query == 'D'){
            int find;
            scanf("%d", &find); getchar();

            int target = binarySearch(arr, size, find);

            for (int i = target; i < index; i++){
                swap(&arr[i], &arr[i+1]);
            }

            index--;
            
            // int idx = binarySearchGT(arr, size, num);
            // memmove(&arr[idx], &arr[idx+1], sizeof(int) * (size - index));
            size -= 1;
        }
        else if (query == 'Q'){
            int find;
            scanf("%d", &find); getchar();

            int target = binarySearchGT(arr, size, find);

            printf("%d\n", target);
        }

        // for (int i = 0; i <= index; i++){
        //     printf("%d ", arr[i]);
        // }
        // printf("\n");

    }

    
}