#include <stdio.h>

int main(){
	int tc;
	scanf("%d", &tc);
	for(int i = 0; i < tc; i++){
		int angka, sum = 0, rsum = 0;
		scanf("%d", &angka);
		loop:
		while(angka > 0){
			sum += (angka % 10);
			angka /= 10;
		}
		if(sum >= 10){
			angka = sum;
			sum = 0;
			goto loop;
		}
		printf("%d\n", sum);
	}
	return 0;
} 
