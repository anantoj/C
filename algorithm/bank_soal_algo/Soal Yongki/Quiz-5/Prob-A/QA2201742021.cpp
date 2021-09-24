#include <stdio.h>

int main(){
	
	int jumtestcase, i;
	int jumnum, j, k, l, m;
	char num1[101], num2[101];
	int number1[101], number2[101];
	int total[1000];
	int pin = 0;
	
	scanf("%d", &jumtestcase);
	for(i = 0 ; i < jumtestcase ; i++){
		scanf("%d %s %s", &jumnum, &num1, &num2);
		printf("Case #%d: ", i+1);
		for(j = 0 ; j < jumnum ; j++){
			number1[j] = num1[j] - '0';
		}
		for(k = 0 ; k < jumnum ; k++){
			number2[k] = num2[k] - '0';
		}
		for(l = jumnum - 1 ; l >= 0 ; l--){
			total[l] = number1[l] + number2[l];
			if(total[l] > 9){
				total[l] = ((number1[l] + number2[l]) - 10);
			if(l != 0){
				number1[l-1] += 1;
			}
			else{
				pin++;
			}
			}
		}
			if(pin > 0){
				printf("1");
			}
		for(m = 0 ; m < jumnum ; m++){
			printf("%d", total[m]);
		}
		printf("\n");
	}
	return 0;
}
