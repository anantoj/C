#include <stdio.h>

void swap(int &number, int &number1){ //the changes this function do will affect the array
	int temp = number;
	number = number1;
	number1 = temp;
}

void bubble(int number[], int size){
	printf("Bubble sort\n--------------------------\n");
	for(int x = 0; x < size - 1; x++){ //angka terakhir pasti tersort sendiri setelah n - 1 sorting
		for(int y = x + 1; y < size; y++){
			if(number[x] > number[y]){
				swap(number[x], number[y]); //giving acces straight to the address e.g passing by reference
				printf("swap %d:", x + 1);
				for(int output = 0; output < size; output++){
					printf(" %d", number[output]);
				}
				puts("\n");
			}
		}
	}
}

void selection(int number[], int size){
	printf("Selection sort\n--------------------------------\n");
	for(int x = 0; x < size - 1; x++){
		int min = x; //first index 
			printf("swap %d:", x + 1);
		for(int y = x + 1; y < size; y++){
			if(number[min] > number[y]){
				min = y;
			}
		}
		
		if(min != x){ //if there a new index assigned to replace the initial index (x)
			swap(number[x], number[min]);
		}
			
	
		for(int output = 0; output < size; output++){
			printf(" %d", number[output]);
		}
		puts("\n");
	}
}

int partition(int arr[], int low, int high){
	int pivot = arr[high];
	int i = low - 1;
//	printf("Low : %d\n", low);
//	printf("High: %d\n", high);
//	printf("Pivot: %d\n", pivot);
//	printf("int i: %d\n", arr[i]);
	for(int j = low; j < high; j++){
		if(arr[j] <= pivot){
			i++;
			swap(arr[i], arr[j]);
			
//			for(int x = 0; x < high; x++){
//				printf("%d ", arr[x]);
//			}
//			puts("");
		}
	}
	swap(arr[i + 1], arr[high]);
//	printf("Return: %d\n", i + 1);
//	puts("\n
	return (i + 1);
}

void quick(int arr[], int low, int high){
	if(low < high){
		int pi = partition(arr, low, high);
		quick(arr, low, pi - 1);
		quick(arr, pi + 1, high);
	}
}

int main(){
	int number[6] = {99, 12, 8, 22, 17, 31};
	int size = 6;
	bubble(number, size);
	
	int number2[6] = {99, 12, 8, 22, 17, 31};
	selection(number2, size);
	
	int number3[7] = {10, 7, 12, 8, 3, 2, 6};
//int number3[6] = {99, 12, 8, 22, 17, 31};
	puts("Quick Sort\n--------------------------------------------");
	int big = sizeof(number3) / sizeof(number3[0]);
	printf("Size: %d\n", big);
	quick(number3, 0, big - 1);
	for(int x = 0; x < big; x++){
		printf("%d ", number3[x]);
	}
	
	return 0;
}
