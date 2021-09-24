#include <stdio.h>

int main(){
	
	int in1, in2;
	int out1, out2, out_total=0;
	
	scanf("%d %d", &in1, &in2);
	
	out1 = in1 % 10;
	out2 = in2 / 10;
	out_total = out1 * 10 + out2;
	
	printf("%d\n", out_total);
	
	
	
	return 0;
}


