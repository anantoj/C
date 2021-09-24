#include <stdio.h>
int main(){
	int x, y, quadrant;
	scanf("%d", &x);
	scanf("%d", &y);
	
	if(x > 0 && y > 0){
		quadrant = 1;
	} else if(x < 0 && y > 0){
		quadrant = 2;
	} else if(x < 0 && y < 0){
		quadrant = 3;
	} else if(x > 0 && y < 0){
		quadrant = 4;
	} else{
		quadrant = -1;
	} printf("%d\n", quadrant);
	
	return 0;
}
