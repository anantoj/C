#include <stdio.h>

void swap (char *a, char *b){
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(void){
    char str[100] = "Helo";
    
    swap(&str[0], &str[3]);

    printf("%s\n", str);
}