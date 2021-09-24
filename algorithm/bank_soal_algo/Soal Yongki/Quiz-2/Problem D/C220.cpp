#include <stdio.h>

int main(){
	int t, i, j;
	char n[100000];
	int b;
	int max = 0;
	char ans = '1';
	int k = j + 1;
	int temp = 0;
	
		scanf("%d", &t);
		
	for (i = 0; i < t; i++)
	{
		
		scanf("%d", &b); 
		scanf("%s", &n);  
		
	for (j = 0; j < b-1; j++)
		{
		
		if (n[j] == n[j+1])

			{
			
		while (k < b && n[j] == n[k])
				{
				temp++;
				k++;
				}
				
				j = k;
				temp++;
				
				if (max <= temp)
				{
					max = temp;
					ans = n[k];
				}
			}
			
		}
		printf("Case #%d: %c %d\n", i, ans, max);
	}
	return 0;
}
