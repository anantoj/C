#include <stdio.h>

//output every black piece position that can be attacked by white piece -> white attack black
//white piece -> uppercase
//black piece -> lowercase

int pawn(int row, int col, char board[9][9]){
	if(board[row + 1][col - 1] == 'P' || board[row + 1][col + 1] == 'P'){
		return 1;
	} else {
		return 0;
	}
}

int knight(int row, int col,  char board[9][9]){
	if(row + 1 < 8 && col + 2 < 8){ //ok
		if(board[row + 1][col + 2] == 'N'){
			return 1;
		}
	} 
	if(row - 1 >= 0 && col + 2 < 8){ //ok
		if(board[row - 1][col + 2] == 'N'){
			return 1;
		}
		
	}
	if(row + 1 < 8 && col - 2 >= 0){
		if(board[row + 1][col - 2] == 'N'){
			return 1;
		}
	}
	if(row - 1 >= 0 && col - 2 >= 0){
		if(board[row - 1][col - 2] == 'N'){
			return 1;
		}
	}
	if(row + 2 < 8 && col + 1 < 8){//ok
		if(board[row + 2][col + 1] == 'N'){
			return 1;
		}
		
	}
	if(row + 2 < 8 && col - 1 >= 0){//ok
		if(board[row + 2][col - 1] == 'N'){
			return 1;
		}
	}
	if(row - 2 >= 0 && col + 1 < 8){ //ok
		if(board[row - 2][col + 1] == 'N'){
			return 1;
		}
	}
	if(row - 2 >= 0 && col - 1 >= 0){ //ok
		if(board[row - 2][col - 1] == 'N'){
			return 1;
		}
	}
	return 0;
}

int rook(int row, int col, char board[9][9]){
	int x;
//	int flag = 0;
	//check from position to the most upper position
	for(x = 1; x < 8; x++){ 
		if(board[row-x][col] == '.'){
			continue;
		}else if(board[row - x][col] != 'R' ){
			break;
		} else if(board[row - x][col] == 'R'){
			return 1;
		}else if(row - x < 0){
			break;
		}
	}
	
	//check from position to bottom
	for(x = 1; x < 8; x ++){ 
		if(board[row + x][col] == '.'){
			continue;
		}if(board[row + x][col] != 'R'){
			break;
		} else if(board[row + x][col] == 'R'){
			return 1;
		} else if(row + x > 8){
			break;
		}
	}
	
	//check from position to right
	for(x = 1; x < 8; x ++){ 
		if(board[row][col + x] == '.'){
			continue;
		}if(board[row][col + x] != 'R'){
			break;
		} else if(board[row][col + x] == 'R'){
			return 1;
		} else if(col + x > 8){
			break;
		}
	}
	
	//check from position to left
	for(x = 1; x < 8; x ++){ 
		if(board[row][col - x] == '.'){
			continue;
		}if(board[row][col - x] != 'R'){
			break;
		} else if(board[row][col - x] == 'R'){
			return 1;
		} else if(col - x < 0){
			break;
		}
	}
	
	return 0;
	
}

int bishop(int row, int col, char board[9][9]){
	int x;
	for(x = 1; x < 8; x++){ //diagonal top left
		if(board[row - x][col - x] == '.'){
			continue;
		} else if(board[row- x][col - x] != 'B' ){
			break;
		} else if(board[row - x][col - x] == 'B'){
			return 1;
		} else if(row - x < 0 || col - x < 0){
			break;
		}
	}
	
	for(x = 1; x < 8; x++){ //diagonal top right
		if(board[row - x][col + x] == '.'){
			continue;
		} else if(board[row - x][col + x] != 'B' ){
			break;
		} else if(board[row - x][col + x] == 'B'){
			return 1;
		} else  if(row - x < 0 || col + x > 8){
			break;
		}
	}
	
	for(x = 1; x < 8; x++){ //diagonal bottom left
		if(board[row + x][col - x] == '.'){
			continue;
		} else if(board[row + x][col - x] != 'B'){
			break;
		} else if(board[row + x][col - x] == 'B'){
			return 1;
		} else if(row + x > 8 || col - x < 0){
			break;
		}
	}
	
	for(x = 1; x < 8; x++){ //diagonal bottom right
		if(board[row + x][col + x] == '.'){
			continue;
		} else if(board[row + x][col + x] != 'B'){
			break;
		} else if(board[row + x][col + x] == 'B'){
			return 1;
		} else if(row + x > 8 || col + x > 8){
			break;
		}
	}
	return 0;
}

int queen(int row, int col, char board[9][9]){
	int x;
	for(x = 1; x < 8; x++){ 
		if(board[row-x][col] == '.'){
			continue;
		}else if(board[row - x][col] != 'Q'){
			break;
		} else if(board[row - x][col] == 'Q'){
			return 1;
		}else if(row - x < 0){
			break;
		}
	}
	
	//check from position to bottom
	for(x = 1; x < 8; x ++){ 
		if(board[row + x][col] == '.'){
			continue;
		}if(board[row + x][col] != 'Q'){
			break;
		} else if(board[row + x][col] == 'Q'){
			return 1;
		} else if(row + x > 8){
			break;
		}
	}
	
	//check from position to right
	for(x = 1; x < 8; x ++){ 
		if(board[row][col + x] == '.'){
			continue;
		}if(board[row][col + x] != 'Q'){
			break;
		} else if(board[row][col + x] == 'Q'){
			return 1;
		} else if(col + x > 8){
			break;
		}
	}
	
	//check from position to left
	for(x = 1; x < 8; x ++){ 
		if(board[row][col - x] == '.'){
			continue;
		}if(board[row][col - x] != 'Q'){
			break;
		} else if(board[row][col - x] == 'Q'){
			return 1;
		} else if(col - x < 0){
			break;
		}
	}
		
	for(x = 1; x < 8; x++){ //diagonal top left
		if(board[row - x][col - x] == '.'){
			continue;
		} else if(board[row- x][col - x] != 'Q' ){
			break;
		} else if(board[row - x][col - x] == 'Q'){
			return 1;
		} else if(row - x < 0 || col - x < 0){
			break;
		}
	}
	
	for(x = 1; x < 8; x++){ //diagonal top right
		if(board[row - x][col + x] == '.'){
			continue;
		} else if(board[row - x][col + x] != 'Q' ){
			break;
		} else if(board[row - x][col + x] == 'Q'){
			return 1;
		} else  if(row - x < 0 || col + x > 8){
			break;
		}
	}
	
	for(x = 1; x < 8; x++){ //diagonal bottom left
		if(board[row + x][col - x] == '.'){
			continue;
		} else if(board[row + x][col - x] != 'Q'){
			break;
		} else if(board[row + x][col - x] == 'Q'){
			return 1;
		} else if(row + x > 8 || col - x < 0){
			break;
		}
	}
	
	for(x = 1; x < 8; x++){ //diagonal bottom right
		if(board[row + x][col + x] == '.'){
			continue;
		} else if(board[row + x][col + x] != 'Q'){
			break;
		} else if(board[row + x][col + x] == 'Q'){
			return 1;
		} else if(row + x > 8 || col + x > 8){
			break;
		}
	}
	return 0;
	
}

int king(int row, int col, char board[9][9]){
	for(int x = -1; x <= 1; x++){
		for(int y = -1; y <= 1; y++){
			if(row + x >= 0 && row + x <= 7 && col + y >= 0 && col + y <= 7){
				if(board[row + x][col + y] == 'K'){
					return 1;
				}
			}
		}
	}
	return 0;
}

int checkPiece(int row, int col, char board[9][9]){
	int x;
	if(pawn(row, col, board) == 1) {
		printf("%c %d\n", 65 + col, 8 - row);
//		printf("Attacked by Pawn\n");
		return 1;
	} else 
	if(knight(row, col, board) == 1) {
		printf("%c %d\n", 65 + col, 8 - row);
//		printf("Attacked by Knight\n");
		return 1;
	} else 
	if(rook(row, col, board) == 1) {
		printf("%c %d\n", 65 + col, 8 - row);
//		printf("Attacked by Rook\n");
		return 1;
	} else 
	if(bishop(row, col, board) == 1) {
		printf("%c %d\n", 65 + col, 8 - row);
//		printf("Attacked by Bishop\n");
		return 1;
	} else
	if(queen(row, col, board) == 1) {
		printf("%c %d\n", 65 + col, 8 - row);
//		printf("Attacked by queen\n");
		return 1;
	} else
	if(king(row, col, board ) == 1) {
		printf("%c %d\n", 65 + col, 8 - row);
//		printf("Attacked by King\n");
		return 1;
	}
	
	return 0;
}

void board(char board[9][9]){ //check for any pieces of chess on the board
	int flag = 0;
	int count = 0;
	for(int x = 0; x < 8; x++){
		for(int y = 0; y < 8; y++){
			if(board[x][y] >= 97 && board[x][y] <= 122){
//				printf("Percobaan ke-%d\n", count);
				count++;
				flag += checkPiece(x, y, board);
			}
		}
	}
	if(flag == 0){ //if no black piece can be attacked
		printf("-1\n");
	}
}

int main(){
	int testcase;
	char chessBoard[9][9];
	scanf("%d", &testcase);
	
	for(int loop = 1; loop <= testcase; loop++){ //testcase loop
		
		//input board and chess piece
		for(int row = 0; row < 8; row++){ //row notation is number || bottom to top (1 - 8)
			scanf("%s", &chessBoard[row]);	  //col notation is alphabet || left to right (a - h)
		}
		printf("Case #%d:\n", loop);
		board(chessBoard);

	}
	
	return 0;
}
