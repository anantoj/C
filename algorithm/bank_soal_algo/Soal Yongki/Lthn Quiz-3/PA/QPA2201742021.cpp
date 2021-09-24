#include <stdio.h>

	int main(){
		
	int in, i=0;
	int out;
	
	scanf("%d", &in);
	do{
		out = in * 2 + 1;
	} while (i < in);
	printf("%d", out);
	return 0;
}
