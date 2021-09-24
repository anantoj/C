#include <stdio.h>

int main(){
	int testcase, digit;
	long long int number, temp, total;
//	char sdigit1[20], sdigit2[20];
	
	
	scanf("%d", &testcase);
	
	for(int loop = 1; loop <= testcase; loop++){
		scanf("%lld", &number);
		temp = number;
		total = number;
		printf("Case #%d:", loop);
		do{
			printf(" %lld", total);
			digit = 0;
			total = 0;
			while(temp != 0){
				total = total + (temp % 10);
				temp /= 10;
				digit++;
			}
			temp = total;
			
		}while(digit != 1);
		printf("\n");
	}
	
	return 0;
}
