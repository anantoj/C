#include <stdio.h>

int main(){
	
	int jumtestcase, i;
	int length_mess;
	int space, j;
	char kalimat[201];
	
	scanf("%d", &jumtestcase);
	for ( i = 1 ; i <= jumtestcase ; i++){
		scanf("%d", &length_mess); getchar();
		scanf("%[^\n]", &kalimat); getchar();
		printf("Case #%d: ", i);
		
		space = 0;
		for( j = 0 ; j < length_mess ; j++){
			if(kalimat[j] == ' ') space++;
			if (space % 2 == 0){
				printf("%c", kalimat[j]);
			}
		}
		printf("\n");
	}
	return 0;
}
