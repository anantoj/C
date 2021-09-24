#include <stdio.h>

int row = 0, col = 0;

int findTile(char board[105][105], int curRow, int pos){
	int tap = 0;
	for(int x = 0; x < col; x++){
		if(board[curRow][x] == '|'){
			if(x != pos){
				tap = 1;
				break;
			} else if(x == pos){
				tap = 0;
				break;
			}
		} else if(board[curRow][x] == '\\'){
			if(x != pos){
				tap = 1;
				break;
			} else if(x == pos){
				tap = 0;
				break;
			}
		} else if(board[curRow][x] == '/'){
			if(x != pos){
				tap = 1;
				break;
			} else if(x == pos){
				tap = 0;
				break;
			}
		} else if(x == col - 1){
			tap = 0;
		}
	}
	return tap;
}

int findPos(char board[105][105], int curRow){
	int pos = 0;
	for(int x = 0; x < col; x++){
		if(board[curRow][x] == '|'){
			pos = x;
			break;
		} else if(board[curRow][x] == '\\'){
			pos = x + 1;
			break;
		} else if(board[curRow][x] == '/'){
			pos = x - 1;
			break;
		} else if(x == col - 1){
			pos = -1;
		}
	}
	return pos;
}


int main(){
	int testcase, totalTap, pos;
	char board[105][105];
	
	scanf("%d", &testcase);
	
	for(int x  = 1; x <= testcase; x++){
		scanf("%d %d", &row, &col);
		pos = -2;
		totalTap = 0;
		
		for(int i = 0; i < row; i++){ //baris
			scanf("%s", board[i]);
		}
		
		for(int checkRow = 0; checkRow < row; checkRow++){
			totalTap = totalTap + findTile(board, checkRow, pos);
			pos = findPos(board, checkRow );
		}
		printf("Case #%d: %d\n", x, totalTap);
	}
	
	return 0;
}
