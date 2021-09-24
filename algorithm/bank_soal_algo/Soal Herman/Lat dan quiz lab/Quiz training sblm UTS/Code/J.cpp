#include <stdio.h>

int main(){
	int teman, point = 0, counter = 0;;
//	int all = 3 + teman;
	
	scanf("%d", &teman);
	
	for(int x = 1; x <= teman + 3; x++){
		if(counter == 2){
			counter = 0;
			continue;
		}
			point += 1;
			counter += 1;
	}
	
	printf("%d\n", point);
	
	return 0;
}
