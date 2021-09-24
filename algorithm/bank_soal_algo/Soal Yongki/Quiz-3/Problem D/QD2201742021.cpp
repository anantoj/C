#include<stdio.h>

int main(){
	
	int jumcase, a;
	int jumco, b;
	int jumrow, c;
	int d = 0;
	char string [10001];
	
	scanf("%d",&jumcase);
	
	for(a = 1 ; a <= jumcase ; a++){
		scanf("%s",&string);
		scanf("%d %d",&jumco,&jumrow);
		printf("Case #%d:\n",a);
		
		d=0;
		for(b = 0 ; b < jumco ; b++){
		for(c = 0 ; c < jumrow ; c++){
		 	if (c == jumrow - 1){
				printf("%c", string[d]);
			}else if(c != jumrow - 1){
				printf("%c ", string[d]);
 		}
			d++;
		}
		printf("\n");
	}
	
	}
		
	return 0;
}
