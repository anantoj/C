#include <stdio.h>
#include <math.h>

int main(){
long long int follower, day, total;
scanf("%lld %lld", &follower, &day);

int x = 2;
int y = day;
long long int pangkat = pow(x, y);

printf("%lld\n", pangkat * follower);


return 0;
}
