#include <stdio.h>

typedef struct{
    char name[50];
    int age;
}DATA;

int main(void){
    FILE *fp;   

    DATA data[10];

    fp = fopen("data.txt", "r"); // open to write

    if (fp == NULL){
        printf("FAIL to open file\n");
    }
    else{
        printf("Success open file\n");
        // fprintf(fp,"TEST\nTEST\n");
        // char str[100];
        // fgets*str,4,fp);
        // printf("%s\n", str);
        int index = 0;
        while (!feof(fp)){
            fscanf(fp, "%[^#]#%d\n", data[index].name, &data[index].age);
            index++;
        }       
        for (int i = 0; i < index; i++){
            printf("NAME: %s || AGE: %d\n", data[i].name, data[i].age);
        }
        fclose(fp);
    }
    return 0;
}