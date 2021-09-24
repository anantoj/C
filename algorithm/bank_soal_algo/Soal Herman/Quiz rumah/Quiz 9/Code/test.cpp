#include <stdio.h>

int factorial(int n) {
   //base case
   if(n == 0) {
      return 1;
   } else {
      return n * factorial(n-1);
   }
}

int fibbonacci(int n) {
   if(n == 0){
      return 0;
   } else if(n == 1) {
      return 1;
   } else {
      return (fibbonacci(n-2) + fibbonacci(n-1));
   }
}

int main() {
   int n = 99;
   int i;
	
//   printf("Factorial of %d: %d\n" , n , factorial(n));
//   printf("Fibbonacci of %d: " , n);
//	
//      printf("%d ",fibbonacci(n));            
	printf("%d", 1 / 2);
}
