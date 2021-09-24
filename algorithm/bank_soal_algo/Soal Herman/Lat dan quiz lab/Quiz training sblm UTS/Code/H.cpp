#include <stdio.h>

int main(){
	long long int follower, day;
	
	scanf("%lld %lld", &follower, &day);
	for(int x = 1; x <= day; x++){
		follower *= 2;
	}
	
	printf("%lld\n", follower);
	return 0;
}
