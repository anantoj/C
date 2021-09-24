#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
	char a[100];
	scanf("%s", &a);
	int i, j, start = 0;
	int count = 0;
	for (i  = 0; i < strlen(a); i++){
		if (isalpha(a[i-1]) && isdigit(a[i])){
			for (j = 0; j < 11 - count; j++){
				printf(" ");
			}
			printf("%c", a[i]);
		}
		else if (isdigit(a[i-1]) && isalpha(a[i])){
			printf("\n%c", a[i]);
			count = 1;
		}
		else{
			printf("%c", a[i]);
			count++;
		}
	}	
	printf("\n");
	return 0;
}
