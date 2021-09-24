#include <stdio.h>
#include <math.h>

int main(){
	int x = 1;
	float y = (float)x * 60 / 100;
	int a = (int)ceil(y);
	printf("%d", a);
	
	return 0;
}
