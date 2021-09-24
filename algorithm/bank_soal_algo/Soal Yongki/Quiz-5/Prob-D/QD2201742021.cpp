#include<stdio.h>

int main(){
	int jumtestcase, i;
	int j, N;
	long long int A, total;
	long long int B, count;
	
	scanf("%d", &jumtestcase);
	for(i = 0 ; i < jumtestcase ; i++){
		
		scanf("%lld %d", &A, &N);
		printf("Case #%d:\n", i+1);
		printf("%lld", A);
		
		for(j = 0 ; j < N ; j++){
		
			if(j == 0) count = 2;
			else count = total;
			B = count - 1;
			total = (count + B) % 1000000007;
			printf(" %lld", (total + A - 2) % 1000000007);
		}
		printf("\n"); 
	}
	return 0;
}
