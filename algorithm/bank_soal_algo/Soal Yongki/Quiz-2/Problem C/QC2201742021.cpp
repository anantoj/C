#include <stdio.h>

int main() {

	int jumTesCase = 0;
	scanf("%d", &jumTesCase);
	getchar();
	
	if(jumTesCase > 10 || jumTesCase < 1) return 0;
	
	for(int i = 0 ; i < jumTesCase; i++){
		int n = 0, x = 0, m = 0;
		int sum = 0;
		
		scanf("%d %d %d", &n, &x, &m);
		getchar();
		
		printf("Case #%d:\n", i+1);
		if(n > 100000 || n < 1 || x > 1000000000 || x < 1 || m > 1000000000 || m < 1) continue;
		for(int j = 1; j <= n; j++){
			sum+= j;
			if(sum > x){
				printf("%d\n",sum);
				while(sum > x){
				sum -= m;
				}
			}
		}
	}

	return 0;
}
