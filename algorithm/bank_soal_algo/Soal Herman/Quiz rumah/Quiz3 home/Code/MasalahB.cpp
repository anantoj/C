#include <stdio.h>

int main(){
	int testcase, size, maxR, maxC;
	scanf("%d", &testcase);
	
	for(int loop = 0; loop < testcase; loop++){ //testcase
		scanf("%d", &size);
		int matrix[size][size];
		
		for(int i = 0; i < size; i++){ //input
			for(int j = 0; j < size; j++){
				scanf("%d", &matrix[i][j]);
			}
		}
		printf("Case #%d:\n", loop + 1);
		printf("Row :");
		for(int x = 0; x < size; x++){
			maxR = -128;
			for(int y = 0; y < size; y++){
				if(matrix[x][y] > maxR){
					maxR = matrix[x][y];
				}
				}
				printf(" %d", maxR);
			}
			printf("\n");
			
			printf("Col :");
		for(int x2 = 0; x2 < size; x2++){
			maxC = -128;
			for(int y2 = 0; y2 < size; y2++){
				if(matrix[y2][x2] > maxC){
					maxC = matrix[y2][x2];
				}
			}
			printf(" %d", maxC);
		}
			printf("\n");
		}
		
	return 0;
}
