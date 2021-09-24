#include <stdio.h>

int main(){
	int cake[3][4];
	int row = 3, col = 4;
	char piece;

	for(int baris = 0; baris < row; baris++){ //input 
			for(int kolom = 0; kolom < col; kolom++){
				scanf(" %c", &piece);
				if(piece == 's'){
					cake[baris][kolom] = 0;
				} else if(piece == '.'){
					cake[baris][kolom] = 1;
				}
			}
		}
		
	for(int print1 = 0; print1 < row; print1++){
		for(int print2 = 0; print2 < col; print2++){
			printf("array [%d[%d]: %d", print1, print2 ,cake[print1][print2]);
		}
		puts("");
	}
		
		return 0;
}
