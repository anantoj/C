#include <stdio.h>

int main() {
	
	int Case;
	int digit;
	int sum[10000];
	int flag;
	
	scanf("%d",&Case);
	
	for(int i = 0; i < Case; i++) {
		scanf("%d",&digit);
		int a[digit+1],b[digit+1];
		
		for(int j = 0; j < digit; j++) {
			scanf("%1d",&a[j]);
		}
		for(int j = 0; j < digit; j++) {
			scanf("%1d",&b[j]);
		}
		
		for(int j = digit - 1; j >= 0; j--) {
			
			sum[j] = sum[j] + a[j] + b[j];
			
			if(sum[j] > 9 && j != 0) {
				flag = sum[j];
				sum[j-1] = sum[j] / 10;
				sum[j] %= 10;
			}
		}
		flag = 0;
		
		printf("Case #%d: ", i+1);
		for(int j = 0; j < digit; j++) {
			printf("%d",sum[j]);
		}
		printf("\n");
		for(int j = 0; j < digit; j++) {
			sum[j] = 0;
			a[j] = 0;
			b[j] = 0;
		}
	}
	
	
	return 0;
}
