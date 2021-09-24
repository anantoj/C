#include <stdio.h>

int main(){
	int testcase, minute, loop, hours, min;
	
	scanf("%d", &testcase);
	
	for(loop = 1; loop <= testcase; loop++){
		scanf("%d", &minute);
		hours = minute / 60;
		min = minute % 60;
		
		printf("Case #%d:", loop);
		if(hours < 10){
			printf(" 0%d:", hours);
		} else {
			printf(" %d:", hours);
		}
		if(min < 10){
			printf("0%d\n", min);
		} else {
			printf("%d\n", min);
		}
	}
	
	return 0;
}
