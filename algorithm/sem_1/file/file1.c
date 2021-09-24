#include <stdio.h>

typedef struct{
    char name[50];
    char number[50];
    char address[50];
}STUDENT;

int main(void){
    FILE *fp;
    
    fp = fopen("data.txt", "r");

    STUDENT students[10];

    if (fp == NULL){
        printf("FAIL\n");
    }
    else{
        printf("SUCCESS\n");
        int index = 0;
        while(!feof(fp)){
            fscanf(fp, "%[^#]#%[^#]#%[^\n]\n", students[index].name, students[index].number, students[index].address);
            index++;
        }

        for (int i = 0; i < index; i++){
            printf("NAME: %s\n", students[i].name);
            printf("PHONE NUMBER: %s\n", students[i].number);
            printf("ADDRESS: %s\n", students[i].address);
            printf("\n");
        }

        fclose(fp);
    }
}