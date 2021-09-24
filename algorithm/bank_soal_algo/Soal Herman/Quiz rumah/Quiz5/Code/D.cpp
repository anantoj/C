#include <stdio.h>

int main(){
	int testcase;
	long long int num, angka1, total, x;
	
	scanf("%d", &testcase);
	
	for(int loop = 1; loop <= testcase; loop++){ //testcase loop
		scanf("%lld", &num);
		total = 0;
		angka1 = 0;
		
		for(x = 1; x <= num; x++){
			if(num % x == 0){
				if((x * x) == num){
					++total;
					printf("Case #%d: %lld\n", loop, total + total - 1); 
					break;
				} else if(x * angka1 == num){
					printf("Case #%d: %lld\n", loop, total + total);
					break;
				}
				++total;
				angka1 = x;
			}
		}	
 	}
	return 0;
}
