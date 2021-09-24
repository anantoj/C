#include <stdio.h>
#include <string.h>
int main(){
	char input[2000], initial[500];
	int count = 0;
	scanf("%s", input);
	for(int i = 0; i < strlen(input)-1; i++){
		if(input[i] >= 'A' && input[i] <= 'Z' && input[i] != '\0'){
			initial[count] = input[i];
			count++;
		}
	} printf("%s", initial);
	return 0;
}
