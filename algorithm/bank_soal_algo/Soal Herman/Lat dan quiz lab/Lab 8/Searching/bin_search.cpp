#include <stdio.h>
int binary(int *arr, int start, int end, int find){
	if(start < end){
		int mid = (start + end) / 2;
		if(arr[mid] == find){
			return mid;
		} else if(arr[start] == find){
			return start;
		} else if(arr[end] == find){
			return end;
		} else{
			if(arr[mid] > find){
				end = mid - 1;
			} else if(arr[mid] < find){
				start = mid + 1;
			}
			return(arr, start, end, find);
		}
	} else{
		return -1;
	}
}

int alt_binary(int *arr, int left, int right, int find){
	if(right >= 1){
		int mid = (left + (right))/2;
		if(arr[mid] == find) return mid;
		if(arr[mid] > find) return alt_binary(arr, left, mid-1, find);
		return alt_binary(arr, mid + 1, right, find);
	} else{
		return -1;
	}
}

int main(){
	int arr[] = { 2, 3, 4, 10, 40 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int x = 1; 
    int result = binary(arr, 0, n, x); 
    (result == -1) ? printf("Element is not present in array") 
                   : printf("Element is present at index %d", 
                            result); 
    return 0;
}
