#include <stdio.h>

void swap(int &num1, int &num2){
	int temp = num1;
	num1 = num2;
	num2 = temp;
}

void bubble(int *arr, int size){
	printf("Address of arr[0]: %d\n", arr[0]);
	for(int x = 0; x < size - 1; x++){
		for(int y = x + 1; y < size; y++){
			if(arr[x] > arr[y]){
				swap(arr[x], arr[y]);
			}
		}
	}
}

void selection(int *arr, int size){
	for(int x = 0; x < size - 1; x++){
		int min = x;
		for(int y = x + 1; y < size; y++){
			if(arr[x] > arr[y]){
				min = y;
				break;
			}
		}
	}
}

int main(){
	int arr[20] = {6, 12, 9, 17, 11, 10, 5, 1, 15, 3};
	printf("%d\n", arr[0]);
	bubble(arr, 10);
	for(int x = 0; x < 10; x++){
		printf("%d\n", arr[x]);
	}
	return 0;
}
