#include <stdio.h>

int main(){
	char name1[15], price1[10], name2[15], price2[10], name3[15], price3[10];
	
	scanf("%[A-z]%[0-9]%[A-z]%[0-9]%[A-z]%[0-9]", name1, price1, name2, price2, name3, price3);
	
	printf("%-10s %s\n", name1, price1);
	printf("%-10s %s\n", name2, price2);
	printf("%-10s %s\n", name3, price3);
	
	return 0;
}
