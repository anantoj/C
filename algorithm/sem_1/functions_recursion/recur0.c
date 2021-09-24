#include <stdio.h>

void display(int a){
    printf("%d ",a);
    if (a < 5) display(a+1);
    printf("%d ",a);
    // if (a == 5) printf("\n");
    // else display(a+1);
}

int main(void){
    display(1);

    printf("\n");
    return 0;
}
