#include <stdio.h>

int main(){
	int number, faktorial = 1, res;
	
	scanf("%d", &number);
	
	for(int x = 1; x <= number; x++){
		faktorial = faktorial * x;
	}
	
	if(number == 2){
		printf("%d\n", 2 * 1);
	} else if(number == 3){
		printf("%d\n", (faktorial / 2));
	} else if(number > 3){
		printf("%d\n", (faktorial / 2) / 2);
	}
	
	return 0;
}
