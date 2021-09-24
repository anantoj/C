#include<stdio.h>



int main(){
//	char letter[100];
//	int i = 10, counter = 0;
//	while(counter != i){
//		letter[counter] = 65 + counter;
//		counter++;
//	}
//	char letter = 199;
//	int x = 1;
//	int a = 199;
//	// A = 65 | Z = 90 |||| a = 97 | z = 122
//	while(a > 122){
//		letter -= 29;
//		a -= 29;
//		x++;
//		printf("%d\n", a);
//	}
	
//	for(int x = 0; x < 4; x++){
//		letter -= 29;
//	}
	
//	printf("The letter: %c | %d\n", letter, letter);

	for(int x = 0; x < 3; x++){
		for(int y = 0; y < 3; y++){
			if(x == 1 && y == 1){
				printf("K");
			} else {
				printf("#");
			}
		}
		puts("");
	}
	
	return 0;
}
