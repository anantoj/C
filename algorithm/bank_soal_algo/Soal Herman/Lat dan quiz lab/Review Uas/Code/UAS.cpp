// recursive
#include <stdio.h>

long long int arr[1000];

//int fibo(int number){
//	if(number == 1){
//		return 1;
//	} else if(number == 0){
//		return 0;
//	}
//	
//	return fibo(number - 1) + fibo(number - 2);
//	
//}

long long int fibo(long long int num, long long int arr[]){
	if(num == 1){
		return 1;
	} else if(num == 0){
		return 0;
	}
	
	return (arr[num - 1] + arr[num - 2]) % 1000000009;
}

void merge(int arr[], int start, int mid, int end){
	int x, y, counter;
	int sizeL = mid + 1 - start;
	int sizeR = end - mid;
	
	int leftArr[sizeL], rightArr[sizeR];
	
	counter = 0;
	for(x = 0; x < sizeL; x++){
		leftArr[counter] = arr[start + x];
		counter++;
	}
	
	counter = 0;
	for(y = 0; y < sizeR; y++){
		rightArr[counter] = arr[mid + 1 + y];
		counter++;
	}
	
	x = y = 0;
	counter = start;
	while(x < sizeL && y < sizeR){
		if(leftArr[x] <= rightArr[y]){
			arr[counter] = leftArr[x];
			x++;
		} else {
			arr[counter] = rightArr[y];
			y++;
		}
		counter++;
	}
	
	while(x < sizeL){
		arr[counter] = leftArr[x];
		x++;
	}
	
	while(y < sizeR){
		arr[counter] = rightArr[y];
		y++;
	}
}

void mergeSort(int arr[], int start, int end){
	if(start < end){
		int mid = (start + end) / 2;
		
		mergeSort(arr, start, mid);
		mergeSort(arr, mid + 1, end);
		merge(arr, start, mid, end);
	}
}

int binSearch(int arr[], int start, int end, int search){
	if(start <= end){
		int mid = (start + end) / 2;
		if(search == arr[mid]){
			return mid;
		} else {
			if(search > arr[mid]){
				start = mid + 1;
			} else {
				end = mid - 1;
			}
			return binSearch(arr, start, end, search);
		}
	} else {
		return -1;
	}
}

int main(){
//	long long int sum, res = 0;
//	for(int x = 0; x < 1000; x++){
//		arr[x] = fibo(x, arr);
//	}
//	
//	scanf("%d", &sum);
//	for(int y = 0; y < sum; y++){
//		res = (res + arr[y]) % 1000000009;
//	}
//	printf("%d Fibo sum: %d\n", sum, res);

	int arr[1000], size;
	
	scanf("%d", &size);
	for(int loop = 0; loop < size; loop++){
		scanf("%d", &arr[loop]);
	}
	
	mergeSort(arr, 0, size - 1);
	for(int x = 0; x < size; x++);
	
	int queue;
	printf("How many queue: ");
	scanf("%d", &queue);
	int temp;
	for(int x = 0; x < queue; x++){
		scanf("%d", &temp);
		int idx = binSearch(arr, 0, size - 1, temp);
		if(idx == -1){
			puts("No Such Number Found");
		} else {
			printf("Number temp is located at idx %d\n", idx);
		}
	}
	return 0;
}
