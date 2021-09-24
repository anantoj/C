#include <stdio.h>

int arr[100005] = {};

int main(){	
	int testcase, number, elements;
	
	scanf("%d", &testcase);
	
	for(int loop = 1; loop <= testcase; loop++){
		
		for(int reset = 0; reset < 100005; reset++){ //reset value
			arr[reset] = 0;
		}
		
		scanf("%d", &number);
		
		for(int x = 0; x < number; x++){
			scanf("%d", &elements);
			arr[elements] += 1; //input 5 akan masuk ke index 4
		}
		printf("Case #%d:\n", loop);
		for(int out = 0; out < 100005; out++){
			if(arr[out] != 0){
				printf("%d %d\n", out, arr[out]);
			}
		}
	}
	
	return 0;
}
