#include <stdio.h>

long long int pangkat(long long int number, long long int square, long long int mod){
	long long int total = 0;
	for(int j = 0; j <= square; j++){
		if(j == 0){
			total = 1;
		} else {
			total = total * number;
		}
	}
	total = total % mod;
	return total;
}

int  main(){
	long long int testcase, a, b, n, result, cycle;
	int counter;
	
	scanf("%d", &testcase);
	
	for(int loop = 1; loop <= testcase; loop++){
		
		scanf("%lld %lld %lld", &n, &a, &b);
		counter = 0;
		
		for(int x = 0; x < 100000; x++){
			result = ((a % n) * (pangkat(b, x, n)) % n);
			if(x == 0){
				cycle = result;
				counter += 1;
			} else if(result == cycle){
				break;
			} else {
				counter += 1;
			}
			
		}
		printf("Case #%d: %d\n", loop, counter);
	}
	
	return 0;
}
