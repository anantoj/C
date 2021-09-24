#include <stdio.h>

int main(){
	int testcase, people, number, total;
	
	
	scanf("%d", &testcase);
	for(int loop = 0; loop < testcase; loop++){ //testcase looping
		scanf("%d", &people);
		int floor[100] = {};
		total = 0;
		for(int input = 0; input < people; input++){
			scanf("%d", &number);
			
			if(floor[number - 2] == 0 && floor[number - 1] == 0 && floor[number] == 0){
				floor[number - 1] = 1;
				total += floor[number - 1];
			}
		}
		printf("Case #%d: %d\n", loop + 1, total);
	}
	
	return 0;
}
