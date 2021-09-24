#include <stdio.h>

int main(){
	
	int Case, Countdown, i, j;
	scanf("%d", &Case);
	
		for (i = 1 ; i <= Case ; i++ )
		{
		
			scanf("%d", &Countdown);
			printf("Case #%d:\n", i );
		
		for(j=Countdown ; j>=1 ; j--)
		{
			
			
			if(j==Countdown || j==60 || j==30 || j==10 || j==5)
			{
				
				printf("%d SECONDS TILL NEW YEAR!!\n", j);
				
			}
			else{
				printf("%d\n", j);	
				}
			
		}
	}
	
	return 0;
}
