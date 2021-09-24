#include <stdio.h>;

int main(){
	int number = 4;
	for(int x = 0; x < number; x++){
		for(int y = number - x; y >= 1; y--){
		printf("%d ", y);	
		}
		printf("\n");
	}
	
	return 0;
}
