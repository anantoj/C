#include <stdio.h>

int main(){
	int testcase;
	long long int a,b,c,d;
	int state;
	long long int x;
	
	scanf("%d", &testcase);
	
	for(int loop = 1; loop <= testcase; loop++){
		state = 0;
		scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
		printf("Case #%d:", loop);
		
		if(d <= c){
			state = 0;
		}else{
			for(int x = 0; x < d; x++){
				if((a*x + b) % d == c){
					state = 1;
					break;
				}
			}
		}
		
		if(state == 1){
			printf(" YES\n");
		} else {
			printf(" NO\n");
		}
	}
	return 0;
}
