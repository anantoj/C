// converts binary to integer / long

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char c[100];

    printf("Input binary: ");
    scanf("%s", c);
    char *ptr_end;
    long  bin = strtol(c,NULL,2);

    printf("%ld\n", bin);
}