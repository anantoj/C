#include <stdio.h>

long long int fibo[100005];

long long int fibonacci(long long int fibo[], int num){
	if(num == 0){
		return 0;
	} else if(num == 1){
		return 1;
	}
	
	return (fibo[num - 1] + fibo[num - 2]) % 1000000009;
}

int main(){
	int testcase, num;
	long long int sum;
	
	for(int x = 0; x < 100001; x++){
		fibo[x] = fibonacci(fibo, x);
	}
	
	scanf("%d", &testcase);
	for(int loop = 1; loop <= testcase; loop++){
		scanf("%d", &num);
		
		sum = 0;
		for(int y = 0; y <= num; y++){
			sum = (sum + fibo[y]) % 1000000009;
		}
		printf("Answer: %d\n", sum);
	}
	
}
