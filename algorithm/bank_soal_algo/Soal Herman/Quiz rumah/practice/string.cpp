#include<stdio.h>
 
int main() {
   char name[50];
   char temp;
   int length;
   
   scanf("%s", name);
   
   int length = strlen(name);
   
   length -= 1;
  	while(start < length){
  		printf("asd\n");
  		temp = name[start];
  		name[start] = name[length];
  		name[start] = temp;
  		printf("%d %d\n", start, length);
  		printf("%c %c\n", name[start], name[length]);
  		start++;
  		length--;
  		
	  }
   
   printf("%s", name);
   return 0;
}
