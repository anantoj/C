#include <stdio.h>

int main(){
	int testcase , row, col, total;
	char piece;
	
	scanf("%d", &testcase);
	row = 0;
	col = 0;
	for(int loop = 1; loop <= testcase; loop++){
		scanf("%d %d", &row, &col);
		int cake[15][15]; //row = baris | col = kolom
		total = 0;
		
		for(int baris = 0; baris < row; baris++){ //input 
			for(int kolom = 0; kolom < col; kolom++){
				scanf(" %c", &piece);
				if(piece == 'S'){
					cake[baris][kolom] = 0;
				} else if(piece == '.'){
					cake[baris][kolom] = 1;
				}
			}
		}
		
		for(int x = 0; x < row; x++){ //cek baris
			for(int y = 0; y < col; y++){
				if(cake[x][y] == 0){
					break;
				} else if(y == col - 1){
					for(int z = 0; z < col; z++){
						if(cake[x][z] == 1)
						total += 1;
						cake[x][z] = 2;
					}
				}
			}
		}
		
		for(int a = 0; a < col; a++){ //cek kolom
			for(int b = 0; b < row; b++){
				if(cake[b][a] == 0){
					break;
				} else if(b == row - 1){
					for(int c = 0; c < row; c++){
						if(cake[c][a] == 1){
						total += 1;
						cake[c][a] = 2;	
						}
					}
				}
			}
		}
		
		printf("Case #%d: %d\n", loop, total);
	}
	
	return 0;
}
