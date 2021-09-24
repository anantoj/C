#include <stdio.h>

int main(){
	int t, i, j;
	char n[100000];
	int b;
	int x = 0;
	int y = 0;
	int maxX = 0;
	int maxY = 0;
	
	scanf("%d", &t);
		
	for (i = 0; i < t; i++){		
		scanf("%d", &b); 
		scanf("%s", n);  
			
		for (j = 0; j < b; j++){
			if (n[j] == '0'){
				x++;
				y = 0;
				if (maxX < x)  maxX = x;
			}else if (n[j] == '1'){
				y++;
				x = 0;	
				if (maxY < y)  maxY = y;	
			}		
		}
		
		if(x >= y){
			printf("Case #%d: %c %d\n", i+1, '0' , maxX);
		}else{
			printf("Case #%d: %c %d\n", i+1, '1' , maxY);
		}
		
		x = 0;
		y = 0;
		maxX = 0;
		maxY = 0;
	}

	return 0;
}
