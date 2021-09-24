#include <stdio.h>

struct address{
	char address[50];
	int postal;
};

struct data{
	char name[100];
	int number;
	address addData;
};

int main(){
	data person;
	printf("insert name: ");
	scanf("%s", person.name);
	printf("insert number: ");
	scanf("%d", &person.number);
	printf("insert address: " );
	scanf("%s", person.addData.address);
	printf("insert postal code: ");
	scanf("%d", &person.addData.postal);
	
	printf("%s %d %s %d\n", person.name, person.number, person.addData.address, person.addData.postal);
	
	return 0;
}
