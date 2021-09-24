#include <stdio.h>

void swap(int *arr1, int *arr2){
	int temp = *arr1;
	*arr1 = *arr2;
	*arr2 = temp;
}

int partition(int arr[], int start, int end){
	int val = arr[end];
	int sortedIdx = start - 1;
	
	for(int x = start; x < end; x++){ //pivot wont be checked
		if(arr[x] <= val){
			sortedIdx++;
			swap(&arr[x], &arr[sortedIdx]);
		}
	}
	swap(&arr[sortedIdx + 1], &arr[end]);
	return sortedIdx + 1;
}

int quick(int arr[], int start, int end){
	if(start < end){
		int pivot = partition(arr, start, end);
	
		quick(arr, start, pivot - 1);
		quick(arr, pivot + 1, end);
	}
}

int binSearch(int arr[], int start, int end, int wanted){
	if(start <= end){
		int mid = (start + end) / 2;
		if(wanted == arr[mid]){
			return mid;
		} else {
			if(wanted < arr[mid]){
				end = mid - 1;
			} else if(wanted > arr[mid]){
				start = mid + 1;
			}
			return binSearch(arr, start, end, wanted);
		}
	} else {
		printf("Data Not Found\n");
		return -1;
	}
}

int main(){
	int arr[100], queue;
	int size, search;
	
	scanf("%d %d", &size, &search);
	for(int x = 0; x < size; x++){
		scanf("%d", &arr[x]);
	}
	
	quick(arr, 0, size - 1);;
	for(int y = 0; y < size; y++){
		printf("%d\n", arr[y]);
	}
	
	for(int i = 0; i < search; i++){
		scanf("%d", &queue);
		int val = binSearch(arr, 0, size - 1, queue);
		printf("search res: %d\n", val);
	}
	
	return 0;
}
