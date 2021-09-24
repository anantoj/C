#include <stdio.h>

int main(){
	int testcase, number, zero, one, temp1, temp2;
	char input[100005];
	
	scanf("%d", &testcase);
	
	for(int loop = 1; loop <= testcase; loop++){
		scanf("%d", &number); getchar();
		zero = 0;
		one = 0;
		temp1 = 0;
		temp2 = 0;
		for(int x = 0; x < number; x++){
			scanf("%c", &input[x]);
		}
		for(int y = 0; y < number; y++){
			if(input[y] == '1'){
				if(temp2 > zero){
					zero = temp2;
				}
				temp2 = 0;
				temp1++;
			} else if(input[y] == '0'){
				if(temp1 > one){
					one = temp1;
				}
				temp1 = 0;
				temp2++;
			}
		}
		
		if(temp1 > one){
			one = temp1;
		}
		if(temp2 > zero){
			zero = temp2;
		}
		
		printf("Case #%d:", loop);
		if(zero > one){
			printf(" 0 %d\n", zero);
		} else if(zero < one){
			printf(" 1 %d\n", one);
		}
		
	}
	
	return 0;
}
