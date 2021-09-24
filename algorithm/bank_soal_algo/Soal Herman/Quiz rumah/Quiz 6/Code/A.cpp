#include <stdio.h>

void pattern(int number, int counter, char prev[]){
	int currLetter = 65 + counter;
	char previous[100000];
	
	if(counter == number - 	1){
		sprintf(previous, "%s%c%s", prev, currLetter, prev);
		printf("%s\n", previous);
		return;
	}	
	sprintf(previous, "%s%c%s", prev, currLetter, prev);

	
	pattern(number, counter + 1, previous);
	
	
}

int main(){
	int testcase, number;
	scanf("%d", &testcase);
	
	for(int loop = 1; loop <= testcase; loop++){
		scanf("%d", &number);
		printf("Case #%d: ", loop);
		pattern(number, 0, "");
	}
	
	return 0;
}
