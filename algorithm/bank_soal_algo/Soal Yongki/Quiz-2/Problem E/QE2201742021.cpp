#include<stdio.h>


int main(){
	
	int n = 0;
	
	scanf("%d", &n);
	getchar();
	
	
	for(int i = 0 ; i < n; i++){
		int m = 0;
		int jum = 0;
		
		scanf("%d",&m);
		getchar();
		
		printf("Case #%d:",i+1);
		do{
			if(m > 10) printf(" %d",m);
			while(m > 0){
				jum += m % 10;
				m /= 10;
			}
			m = jum;
		}while((m / 10) > 10);
		
		printf(" %d",m);
		printf("\n");
	}
	
	
	
	return 0;
}
