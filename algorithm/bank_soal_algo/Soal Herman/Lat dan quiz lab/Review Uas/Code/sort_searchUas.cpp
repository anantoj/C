//sorting n searching
#include <stdio.h>

void merge(int arr[], int start, int mid, int end){
	int sizeL, sizeR;
	int counter, x, y;
	sizeL = mid + 1 - start;
	sizeR = end - mid;
	
	counter = 0;
	int arrL[sizeL], arrR[sizeR];
	for(x = 0; x < sizeL; x++){
		arrL[counter] = arr[start + x];
		printf("Copy %d to arrL\n", arr[start + x]);
		counter++;
	}
	
	counter = 0;
	for(y = 0; y < sizeR; y++){
		arrR[counter] = arr[mid + 1 + y];
		printf("Copy %d to arrR\n", arr[mid + 1 + y]);
		counter++;
	}
	puts("");
	
	x = y = 0;
	counter = start;
	printf("Sorted number:");
	while(x < sizeL && y < sizeR){
		if(arrL[x] <= arrR[y]){
			arr[counter] = arrL[x];
			x++;
		} else {
			arr[counter] = arrR[y];
			y++;
		}
		printf(" %d", arr[counter]);
		counter++;
	}
	
	while(x < sizeL){
		arr[counter] = arrL[x];
		printf(" %d", arr[counter]);
		x++;
		counter++;
	}
	
	while(y < sizeR){
		arr[counter] = arrR[y];
		printf(" %d", arr[counter]);
		y++;
		counter++;
	}
	puts("\n");
}

void mergeSort(int arr[], int start, int end){
	
	printf("(Start: %d) (End: %d)\n", start, end);
	
	if(start < end){
		int mid = (start + end) / 2;
		for(int x = start; x <= end; x++){
			printf("%d ", arr[x]);
		}
		puts("");
		mergeSort(arr, start, mid);
		mergeSort(arr, mid + 1, end);
		puts("Merge");
		merge(arr, start, mid, end);
	}
}

int main(){
	int arr[10000];
	int size;
	
	scanf("%d", &size);
	for(int x = 0; x < size; x++){
		scanf("%d", &arr[x]);
	}
	
	mergeSort(arr, 0, size - 1);
	
	return 0;
}
