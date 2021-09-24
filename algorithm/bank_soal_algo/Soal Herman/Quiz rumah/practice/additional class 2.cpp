#include <stdio.h>

int main(){
	int number;
	
	scanf("%d", &number); fflush(stdin);
	
//	for(int i = 1; i <= number; i++){
//		for(int j = 1; j <= i; j++){
//			if(j == i || j > i){
//				printf("*");
//			} else {
//				printf(" ");
//			}
//		}
//		puts("");
//	}

	for(int i = 1; i <= number; i++){
		for(int j = 1; j <= number; j++){
			printf("*");
		}
		puts("");
	}
			
	return 0;
}
