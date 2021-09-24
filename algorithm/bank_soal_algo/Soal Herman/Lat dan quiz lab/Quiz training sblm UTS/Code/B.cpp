#include <stdio.h>

int main(){
	int num1, num2, res;
	
	scanf("%d %d", &num1, &num2);
	res = ((num1 % 10) * 10) + (num2 / 10) ;
	printf("%d\n", res);
	
	
	return 0;
}
