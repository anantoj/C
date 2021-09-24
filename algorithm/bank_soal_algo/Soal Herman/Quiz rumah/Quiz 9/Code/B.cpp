#include <stdio.h>

long long int fiboNum[100005];

long long int fibo(int num, long long int fiboNum[]){
	if(num == 0){
		return 0;
	}
	if(num == 1){
		return 1;
	}
	
	return (fiboNum[num - 1] % 1000000009 + fiboNum[num - 2] % 1000000009) ;
}

int main(){
	
	for(int x = 0; x <= 100000; x++){
		fiboNum[x] = fibo(x, fiboNum);
	}
	int testcase;
	int number;
	long long int sum;
	
	scanf("%d", &testcase);
	for(int loop = 1; loop <= testcase; loop++){
		sum = 0;
		scanf("%d", &number);
		for(int x = 1; x <= number; x++){
			sum = ((sum % 1000000009) + (fiboNum[x] % 1000000009)) % 1000000009;
		}
		printf("Case #%d: %lld\n", loop, sum % 1000000009);
	}
	
	return 0;
}
