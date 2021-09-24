#include <stdio.h>

int main()
{
	
			long long int Case, flavour, i, j;			
			long long int strawberry, chocolate, vanilla;
			char flav;
	
			scanf("%lld", &Case);
			for (i = 1 ; i <= Case ; i++ )
			{
			scanf("%lld", &flavour);
			//fflush (stdin);
			getchar();
			
				strawberry = 0;	
				chocolate  = 0;
				vanilla    = 0;
			
			for(j = 1 ; j <= flavour ; j++)
			{
				scanf("%c", &flav);
			//	fflush (stdin);
			getchar();	
			if(flav == 's')
			{
				strawberry++;
			}
			else if(flav == 'c')
			{
				chocolate++;
			}
			else if(flav == 'v')
			{
				vanilla++;
			}   
			}
			printf("Case #%lld:\n", i);
			if(chocolate > strawberry && chocolate > vanilla)
			{
				printf("chocolate\n");
			}
			else if(strawberry > chocolate && strawberry > vanilla)
			{
				printf("strawberry\n");
			}
			else if(vanilla > chocolate && vanilla > strawberry)
			{
				printf("vanilla\n");
			}
			else if(chocolate == strawberry && strawberry > vanilla)
			{
				printf("chocolate\n");
				printf("strawberry\n");
			}
			else if(strawberry == vanilla && vanilla > chocolate)
			{
				printf("strawberry\n");
				printf("vanilla\n");
			}
			else if(chocolate == strawberry && strawberry == vanilla)
			{
				printf("chocolate\n");
				printf("strawberry\n");
				printf("vanilla\n");
			}
			else if(chocolate == vanilla && vanilla > strawberry)
			{
				printf("chocolate\n");
				printf("vanilla\n");
			}
			}

		return 0;
	
}



