#include <stdio.h>

int main(){
	
	int c, i;
	int numb;
	int coho, comi;
	
	scanf("%d", &c);
	for( i = 1 ; i <= c ; i++){
		scanf("%d", &numb);
			coho = numb / 60;
			comi = numb % 60;
		if(coho < 10 && comi >= 10){
			printf("Case #%d: 0%d:%d\n", i, coho, comi);
		}else if(coho >= 10 && comi < 10){
			printf("Case #%d: %d:0%d\n", i, coho, comi);
		}else if(coho >= 10 && comi >= 10){
			printf("Case #%d: %d:%d\n", i, coho, comi);
		}else if(coho < 10 && comi < 10){
			printf("Case #%d: 0%d:0%d\n", i, coho, comi);
		}
	}
	return 0;
}
