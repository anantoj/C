#include <stdio.h>

int main(){

char name1[10],name2[10],name3[10], phone1[8], phone2[8], phone3[8];
scanf("%[A-z]%[0-9]%[A-z]%[0-9]%[A-z]%[0-9]", name1, phone1, name2, phone2, name3, phone3);
printf("%-10s %s\n", name1, phone1);
printf("%-10s %s\n", name2, phone2);
printf("%-10s %s\n", name3, phone3);


return 0;
}
