#include <stdio.h>

int main(){
	
	int jumtestcase, i;
	int jumnum, j, k, l, m, n;
	int total[10000];
	int pin = 0;
	
	scanf("%d", &jumtestcase);
	for(i = 0 ; i < jumtestcase ; i++){
		scanf("%d", &jumnum);
	int num1[jumnum+1], num2[jumnum+1];
		for(j = 0 ; j < jumnum ; j++){
			scanf("%1d", &num1[j]);
		}
		for(k = 0 ; k < jumnum ; k++){
			scanf("%1d", &num2[k]);
		}
		for(l = jumnum - 1 ; l >= 0 ; l--){
			total[l] = total[l] + num1[l] + num2[l];
			if(total[l] > 9 && l != 0){
				pin = total[l];
				total[l-1] = total[l] / 10;
				total[l] %= 10;
			}
		}
		printf("Case #%d: ", i+1);
		for(m = 0 ; m < jumnum ; m++){
			printf("%d", total[m]);
		}
		printf("\n");
		for(n = 0 ; n < jumnum ; n++){
			total[n] = 0;
			num1[n] = 0;
			num2[n] = 0;
		}
	}
	return 0;
}
