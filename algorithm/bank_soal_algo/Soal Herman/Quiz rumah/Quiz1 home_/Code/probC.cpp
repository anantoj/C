#include <stdio.h>

int main(){
int num_count;
int total = 0;
scanf("%d", &num_count);

total = num_count*(num_count + 1)/2;

printf("%d\n", total);

return 0;
}
