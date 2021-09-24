#include <stdio.h>

int main(){
int N = 0;
scanf("%d", &N);
int people = 3 + N;
int repeat = people;
int point = 0 ;
int ticket = 0;

while(ticket <= people){
    if(repeat % 2 == 0){
        repeat -= 2;
        point += 2;
        ticket += 3;
    } else if (repeat % 2 != 0){
        repeat -= 1;
        point += 1;
        ticket += 1;
    }
}

printf("%d\n", point);

return 0;
}
