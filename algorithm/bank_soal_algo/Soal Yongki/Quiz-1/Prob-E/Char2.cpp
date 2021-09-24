#include <stdio.h>

int main(){
	
	char a[10],b[10],c[10];
	int A,B,C;
	
	scanf("%[^0123456789]%d%[^0123456789]%d%[^0123456789]%d",&a,&A,&b,&B,&c,&C);
	printf("%s %d\n",a,A);
	printf("%s %d\n",b,B);
	printf("%-10s %d\n",c,C);
	
	return 0;
}
