#include <stdio.h>

int main(){
	int  min, max, row, col;
	int array[row][col];
	int total, count = 1, avarage = 0;
	printf("masukkan ukuran tabel data: ");
	scanf("%d %d", &row, &col);
	
	
	for(int input1 = 0; input1 < row; input1++){
		for(int input2 = 0; input2 < col; input2++){
			printf("data elemen [%d][%d]: ", input1, input2);
			scanf("%d", &array[input1][input2]);
		}
	}
	
	min = array[0][0];
	for(int x = 0; x < row; x++){
		for(int y = 0; y < col; y++){
			count++;
			total += array[x][y];
			if(array[x][y] < min){
				min = array[x][y];
			}
			
			if(array[x][y] > max){
				max = array[x][y];
			}
		}
	}
	avarage = total / count;
	
	printf("Avarage : %d\n", avarage);
	printf("Max value : %d\n", max);
	printf("Min value : %d\n", min);
	
	
	
	return 0;
}
