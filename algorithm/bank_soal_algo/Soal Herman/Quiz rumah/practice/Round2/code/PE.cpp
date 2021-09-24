#include <stdio.h>

int main(){
	int ballon, atk, def;
	int killed = 0;
	scanf("%d %d", &ballon, &atk);
	
	for(int x = 0; x < ballon; x++){
		scanf("%d", &def);
		
		if(atk > def){
			killed = killed + 1;
		}
	}
	
	printf("%d\n", killed);
	
	return 0;
}
