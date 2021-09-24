#include <stdio.h>

int  main(){
	int testcase, loop;
	long long int n, x, m, total, difference, multiply, remain, i;
	
	scanf("%d", &testcase);
	
	for(loop = 1; loop <= testcase; loop++){
		scanf("%lld %lld %lld", &n, &x, &m);
		total = 0;
		
		printf("Case #%d:\n", loop);
		for(i = 1; i <= n; i++){
//			printf("loop ke-%lld\n", i);
			if(total <= x) {
				total = total + i;
//				printf("sumed total: %lld\n", total);
			} 
			if(total > x){ //if the total is greater than the limit, the total will substracted with m
				difference = 0;
				multiply = 0;
				printf("%lld\n" , total);
				difference = total - x;
				
				if(difference >= m){ //if the difference is equal or greater than the substractor (m)
					multiply = difference / m;
					remain = difference % m;
					if(remain > 0){
						multiply++;
					}
				} else {
					multiply++;
				}
				total = total - (multiply * m);
			}
			
				 
		}
	}
	return 0;
}
