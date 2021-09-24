#include <stdio.h>

int main(){
	int testcase, friends;
	long long int level, min, max, maxfriend[1050], difference;
	scanf("%d", &testcase);
	
	for(int loop = 1; loop <= testcase; loop++){ //loop testcase
	max = 0;
	min = 0;
	difference = 0;
		scanf("%d %d", &friends, &level);
		for(int x = 0; x < friends; x++){
			scanf("%d", &maxfriend[x]);
			if(x == 0){
				max = maxfriend[0];
				min = maxfriend[0];
			}
			if(max < maxfriend[x]){
				max = maxfriend[x];
			}
			if(min > maxfriend[x]){
				min = maxfriend[x];
			}	
		}
		difference = max - min;
		if(difference > level){
			printf("Case #%d: NO\n", loop);
		} else {
			printf("Case #%d: YES\n", loop);
		}
	}
	
	return 0;
}
