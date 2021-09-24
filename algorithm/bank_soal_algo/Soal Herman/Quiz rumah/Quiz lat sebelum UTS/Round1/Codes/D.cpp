#include <stdio.h>

int  main(){
	int testcase;
	long long int n, x, m, total;
	
	scanf("%d", &testcase);
	
	for(int loop = 1; loop <= testcase; loop++){
		scanf("%lld %lld %lld", &n, &x, &m);
		total = 0;
		
		printf("Case #%d:\n", loop);
		for(long long int i = 1; i <= n; i++){
			printf("summed total: %lld\n", total);
			if(total <= x) {
				total = total + i;
				if(total > x){
					printf("%lld\n" , total);
					while(total > x){
						total -= m;
					}	
				}
				
				
			}
				 
		}
	}
		
	
	
	return 0;
}
