// function that adds a character at the end of a string
#include <stdio.h>
#include <string.h>

char* addCharacter (char* str, char chr)
{
    str[strlen(str)] = chr;
    return str;
}

int main(void)
{
    char* str = "test"; // or char str[100] = "test"
    addCharacter(str, 'A');
    printf("%s\n", str);
}


