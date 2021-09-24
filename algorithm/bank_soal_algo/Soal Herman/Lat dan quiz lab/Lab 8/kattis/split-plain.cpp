#include <stdio.h>
#include <math.h>
int main(){
	int iteration, points, split;
	scanf("%d", &iteration);
	split = (int) sqrt(pow(4,iteration));
	points = (int) pow(split+1, 2);
	printf("%d\n", points);
	return 0;
}
