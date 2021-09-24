#include <stdio.h>

int main(){
	int testcase, row, col, eaten, flag1, flag2;
	scanf("%d" , &testcase);
	
	for(int loop = 1; loop <= testcase; loop++){ //testcase loop
		scanf("%d %d", &row, &col);
		char matrix[row][col];
		eaten = 0;
		
		for(int a = 0; a < row; a++){ //scan matrix element
			for(int b = 0; b < col; b++){
				scanf("%1s", &matrix[a][b]);
			}
		}
		
		for(int r = 0; r < row; r++){ // checker and output
		flag1 = 0;
		flag2 = 0;
		
			for(int c = 0; c < col; c++){
				if(matrix[r][c] == 's'){ //row strawberry checking
				flag1 += 1;
				
			}
				if(matrix[c][r] == 's'){ //coulumn strawberry checker
					flag2 += 1;
					
				}
			}
		if(flag1 == 0)	{ //row
			for(int output1 = 0; output1 < col; output1++){
				if(matrix[r][output1] == '.'){
					eaten += 1;
					matrix[r][output1] = '#';
				}
			}
		}
		
		if(flag2 == 0)	{ //col
			for(int output2 = 0; output2 < col; output2++){
				if(matrix[output2][r] == '.'){
					eaten += 1;
					matrix[output2][r] = '#';
				}
			}
		}
		
	}
	printf("Case #%d: %d\n", loop, eaten);
}
	return 0;
}
