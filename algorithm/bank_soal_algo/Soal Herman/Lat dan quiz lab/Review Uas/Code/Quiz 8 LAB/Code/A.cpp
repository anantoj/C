#include <stdio.h>

int sumDigit(int num){
	int sum = 0;
	while(num != 0){
		sum += (num % 10);
		num /= 10;
	}
	return sum;
}

int main(){
	int testcase;
	int sum, num, totalNum;
	
	scanf("%d", &testcase);
	
	for(int loop = 1; loop <= testcase; loop++){
		scanf("%d", &num);
		
		sum = sumDigit(num);
		while(sum >= 10){
			sum = sumDigit(sum);
		}
		printf("%d\n", sum);
	}
	
	return 0;
}
