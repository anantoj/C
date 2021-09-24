#include <stdio.h>

int main(){
	
	char kata1[12], kata2[12], kata3[12];
	int nomor1, nomor2, nomor3;
	
	scanf("%[^1234567890]%d%[^1234567890]%d%[^1234567890]%d", &kata1, &nomor1, &kata2, &nomor2, &kata3, &nomor3);
	
	printf("%-10s %d\n", kata1, nomor1);
	printf("%-10s %d\n", kata2, nomor2);
	printf("%-10s %d\n", kata3, nomor3);
	
	
	return 0;
}


