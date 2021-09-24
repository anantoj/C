#include <stdio.h>

void swap(int arr[], int &number1, int &number2){
	int temp = number1;
	number1 = number2;
	number2 = temp;
}

void bubble(int arr[], int size){
	for(int x = 0; x < size - 1; x++){
		for(int y = x + 1; y < size; y++){
			if(arr[x] > arr[y]){
				swap(arr, arr[x], arr[y]);
			}
		}
	}
}

int main(){
	int testcase;
	int totalData, lines, number[205];
	int matriks[205][205];
	int col;
	
	scanf("%d", &testcase);
	
	for(int loop = 1; loop <= testcase; loop++){ //testcase loop
		
		//reset matriks elemen to -1
		for(int reset1 = 0; reset1 < 205; reset1++){ 
			for(int reset2 = 0; reset2 < 205; reset2++){
				matriks[reset1][reset2] = -1;
			}
		}
		
		// -1 = blank elemen
	
		scanf("%d %d", &totalData, &lines);
		if(totalData % lines == 0){
			col = totalData / lines;
		} else {
			col = (totalData / lines) + 1;
		}
		
		for(int input = 0; input < totalData; input++){ //taking input
			scanf("%d", &number[input]);
//			printf("Number[%d]: %d", input, number[input]);
		}
//		puts("");
		bubble(number, totalData);
		
		int idx;
		totalData -= 1;
		for(int storeRow = 0; storeRow < lines; storeRow++){
			idx = storeRow;
			for(int storeCol = 0; storeCol < col; storeCol++){
				if(idx <= totalData){
					matriks[storeRow][storeCol] = number[idx];
				} else {
					matriks[storeRow][storeCol] = -1;
				}
				idx += lines;
			}
		}
		
		printf("Case #%d:\n", loop);
		for(int print1 = 0; print1 < lines; print1++){
			for(int print2 = 0; print2 < col; print2++){
				if(matriks[print1][print2 + 1] == -1){
					printf("%d", matriks[print1][print2]);
					break;
				} else if(print2 == col - 1){
					printf("%d", matriks[print1][print2]);
				} else {
					printf("%d ", matriks[print1][print2]);
				}
			}
			printf("\n");
		}
		
	}
	
	return 0;
}
