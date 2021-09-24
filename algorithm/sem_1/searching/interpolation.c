#include <stdio.h>

int interpolationSearch(int *arr, int size, int element){
    
    int low = 0;
    int high = size-1;
    // low and high are indexes

    while (low <= high && element>=arr[0] && element<=arr[high]){
        
        if (low == high){ // if array size has been "Shrinked" down to one through interpolation processes
            if (arr[low] == element){
                return low;
            }                           
            else return -1;
        }

        // Interpolation Search Formula
        int pos = low + ((double)(element - arr[low])/ (arr[high] - arr[low]) * (high - low));

        // if element is found
        if (arr[pos] == element){
            return pos;
        }
        
        if (arr[pos] < element){
            // ignore left part
            low = pos + 1;
        }
        else if (arr[pos] > element){
            // ignore right part
            high = pos - 1;
        }
    }
    return -1; // make sire control reach non-void
}

int main(void){
   
    int arr[] = {10,20,30,40,50,60,70,80,90,100};

    int size = sizeof(arr) / sizeof(int);

    // element to be searched
    int element = 80; 

    int index = interpolationSearch(arr, size, element);

    if (index == -1){
        printf("Element Not Found\n");
    }
    else{
        printf("index = %d\n", index);
    }

}