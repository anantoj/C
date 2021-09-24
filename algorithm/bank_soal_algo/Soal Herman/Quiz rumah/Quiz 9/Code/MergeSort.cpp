#include <stdio.h>

void merge(int arr[], int left, int mid, int right){
	int i, j, k;
	//size of left array and right array
	int leftSide = mid - left + 1;
	int rightSide = right - mid;
	
	int arrL[leftSide], arrR[rightSide];
	//copying element of arr to arrL and arrR
	for(i = 0; i < leftSide; i++){
		arrL[i] = arr[left + i];
	}
	for(j = 0; j < rightSide; j++){
		arrR[j] = arr[mid + 1 + j];
	}
	
	i = 0;
	j = 0;
	k = left; //first idx of the merged array
	while(i < leftSide && j < rightSide){
		if(arrL[i] <= arrR[j]){
			arr[k] = arrL[i];
			i++;
		} else {
			arr[k] = arrR[j];
			j++;
		}
		k++;
	}
	
	//copy remaining of arrL element to arr
	while(i < leftSide){
		arr[k] = arrL[i];
		i++;
		k++;
	}
	
	//copy remaining of arrR element to arr
	while(j < rightSide){
		arr[k] = arrR[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[], int left, int right){
	if(left < right){
		int mid = (left + right) / 2;
		
		mergeSort(arr, left, mid); //sort from mid to left
		mergeSort(arr, mid + 1, right);
		
		merge(arr, left, mid, right);
	}
}

void printArr(int arr[], int size){
	for(int i = 0; i < size; i++){
		printf("%d\n", arr[i]);
	}
	puts("");
}

int main(){
	int arr[] = {1002, 19, 3, 8, 22, 123, 14, 5234, 123, 657, 41, 829, 34, 2314, 15};
	int size = sizeof(arr) / sizeof(arr[0]);
	puts("Before:");
	printArr(arr, size);
	
	mergeSort(arr, 0, size - 1);
	
	puts("After:");
	printArr(arr, size);
	
	return 0;
}
