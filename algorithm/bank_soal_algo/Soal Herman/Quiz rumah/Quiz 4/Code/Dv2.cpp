#include <stdio.h>

int main(){
	int testcase;
	long long int num1, num2, a, b, k = 1000000007, res;
	
	scanf("%d", &testcase);
	
	for(int loop = 1; loop <= testcase; loop++){
		scanf("%lld %lld", &a, &b);
		num1 = 1, num2 = 1;
		res = 0;
		
		for(int x = 1; x <= a; ){
			if(a % 20 == 0){
//				printf("x = %d\n", x);
				num1 = (num1 * 1048576) % k;
				a -= 20;
			}else if(a % 10 == 0){
				num1 = (num1 * 1024) % k;
				a -= 10;
			} else {
				num1 = (num1 * 2) % k;
				a--;
			}
		}
		
		for(int y = 1; y <= b; ){
			if(b % 10 == 0){
//				printf("y = %d\n", y);
				num2 = (num2 * 59049) % k;
				b -= 10;
			} else {
				num2 = (num2 * 3) % k;
				b--;
			}
		}
		
		res = ((num1 % k) * (num2 % k)) % k;
		printf("%lld\n", res);
	}
	
	return 0;
}
