#include <stdio.h>

int main(){
	int testcase, algebra1[3], algebra2[3];
	scanf("%d", &testcase);
	
	for(int loop = 1; loop <= testcase; loop++){
		scanf("%d %d %d", &algebra1[0], &algebra1[1], &algebra1[2]);
		scanf("%d %d %d", &algebra2[0], &algebra2[1], &algebra2[2]);
		float det = (float) algebra1[0] * algebra2[1] - algebra2[0] * algebra1[1];
		
		float x = (float) (algebra1[2] * algebra2[1] - algebra2[2] * algebra1[1]) / det;
		float y = (float) (algebra1[0] * algebra2[2] - algebra2[0] * algebra1[2]) / det;
		
		printf("Case #%d:\n", loop);
		printf("x = %.4f\n", x);
		printf("y = %.4f\n", y);
	}
	
	return 0;
}
