#include <stdio.h>

int main(){
	int number = 1;
	int repeat;
	scanf("%d", &repeat);
	
	for(int x = 1; x <= repeat; x++){
		number = ( number * 2) + 1;
	}
	printf("%d\n", number);
	
	return 0;
}
