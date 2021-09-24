#include <stdio.h>
#include <string.h>

int main(void){
    char str[6][101] = {
        "id",
        "first_name",
        "city",
        "gender",
        "has_car",
        "has_property",
    };

    char col_filter[100] = " ";
    char key[100] = " ";
    char value[100] = " ";
    // scanf("SHOW %s WHERE %s equals %s", col_filter,key,value); getchar();

    scanf("SHOW %s", col_filter); 

    char c = getchar();

    if (c == ' '){
        scanf("WHERE %s equals %s", key, value);
    }

    
    
    
    printf("%s %s %s", col_filter, key, value);
   
    
}