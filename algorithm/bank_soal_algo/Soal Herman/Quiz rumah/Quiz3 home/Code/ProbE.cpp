#include <stdio.h>

int main(){
	int testcase, arrsize, question, left, right, res;
	scanf("%d", &testcase);
	
	for(int loop = 1; loop <= testcase; loop++){ //testcase loop
		scanf("%d %d", &arrsize, &question);
		int number[arrsize];
		
		for(int x = 0; x < arrsize; x++){ //array num input
			scanf("%d", &number[x]);
		}
		
		for(int y = 0; y < question; y++){ //question input and answer print
			scanf("%d %d", &left, &right);
			res = 0;
			for(int start = left - 1; start < right ; start++){
				res = res + number[start];
//				printf("%d\n", start);
			}
			printf("%d\n", res);
		}
		
	}
	
	return 0;
}
