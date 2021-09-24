#include <stdio.h>
int main(){
	int input, i;
	int angka[100]={0};
	int total3[100]={0};
	int temp;
	int flag[100];
	int total1[100]={0};
	
	scanf("%d",&input);
	
	for(i=0;i<input;i++)
	{
	
	scanf("%d",&angka[i]);	
	if(angka[i]<10)
	
	{
		flag[i]=1;
	}
	else 
	{
			flag[i]=2;
					
			temp=angka[i];
			
			total1[i]= temp%10 ;		
			
	while(temp>=1)
	{
			
			temp=temp/10;
			total1[i]+=temp%10;	
			
	}
			if(total1[i]>10)
		{
			
			temp=total1[i];
			total3[i]=temp%10;
			
			while(temp>=1)
			{
				temp=temp/10;
				total3[i]+=temp%10;
			}
		}
			else
			{
			
			total3[i]=NULL;
			
			}
			
		}
		
 }
	for(int i=0;i<input;i++)
		{
		if(flag[i]==1){
			printf("case#%d: %d",i+1,angka[i]);	
		}
		else
		{
			if(total3[i]!=NULL){
			printf("case#%d: %d %d %d\n",i+1,angka[i],total1[i],total3[i]);
		}	
		
		else
		{
			printf("case#%d: %d %d %d\n",i+1,angka[i],total1[i]);
		}
		}
		
		
	}
	
	
		return 0;
}
