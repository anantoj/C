#include <stdio.h>
#include <string.h>

int main(){
	char kata[1][10];
	scanf("%s", kata[0]);
	int i = 0;
	while(kata[0][i] != '\0'){
		i++;
		printf("%d\n", i);
	}
	return 0;
}
