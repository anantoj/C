#include <stdio.h>

// NOTE: data must be sorted first

// [][][][][][][][]
// (l)           (r)

int binSearch(int *arr, int x, int size){
    // initialize left and right indexes
    int left = 0;
    int right = size -1;

    while (left <= right) { 
        // initialize mid
        int mid = (left + right) / 2; 

        // Check if x is present at mid 
        if (arr[mid] == x) 
            return mid; // no need to use ELSE after this because it will immediately stop if FOUND, and continue if NOT FOUND
  
        // If x greater, ignore left half 
        if (arr[mid] < x) 
            left = mid + 1; 
  
        // If x is smaller, ignore right half 
        else
            right = mid - 1; 
    } 
  
    // if we reach here, then element was 
    // not present 
    return -1; 
}

int main(void){
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};

    int index = binSearch(arr,7,10);

    printf("%d\n", index);
}