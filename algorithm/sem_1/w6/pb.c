#include <stdio.h>
#include <string.h>

typedef struct{
    char name[21];
    char gender[21];
    char div[21];
    int status; //0 = idle, -1 = resigned, 1 = working, 2 = retire
}info;

int main(void){
    int n;
    scanf("%d", &n); getchar();
   
    info employ[10000];

    int index = 1; // real index

    for (int p = 0; p < n; p++){

        int process;

        scanf("%d", &process); getchar();

        // add a working employee
        if (process == 1){ 
            char strName[21];
            char strGender[21];
            char strDiv[21];

            scanf("%[^\n]s", strName); getchar();
            scanf("%[^\n]s", strGender); getchar();
            scanf("%[^\n]s", strGender); getchar();

            int sameName = 0;

            // search for an existing employee (working or retired) with SAME NAME
            for (int i = 0; i < index-1; i++){
                if ( /* employ[i].status == 2 ||*/  employ[i].status == 1){
                    if (strcmp(strName, employ[i].name) == 0){
                        sameName = 1; // indicate there is a someone with a same name
                        break;
                    }
                }
            }

            // add employee to array
            
            int foundResign = 0;

            // if name is validated
            if (sameName == 0){
                // find any resigned spot in the array
                for (int i = 0; i < index-1; i++){
                    if(employ[i].status == -1){ // if resigned status is found
                        strcpy(employ[i].name, strName);
                        strcpy(employ[i].gender, strGender);
                        strcpy(employ[i].div, strDiv);
                        employ[i].status = 1;
                        foundResign = 1; // resigned spot has been filled
                        break;
                    }
                }
            }

            // if no resigned spot and name is validated
            if (foundResign == 0 && sameName == 0){
                strcpy(employ[index-1].name, strName);
                strcpy(employ[index-1].gender, strGender);
                strcpy(employ[index-1].div, strDiv);
                employ[index-1].status = 1;
                index++;
            }
        
            // don't forget to increment index
           
        }
        else if (process == 2){
            int x, y;
            scanf("%d %d", &x, &y);
            // swap
            if (employ[x-1].status == 1 && employ[y-1].status == 1){
                info tmp = employ[x-1];
                employ[x-1] = employ[y-1];
                employ[y-1] = tmp;
            }
        }
        else if (process == 3){
            int x;
            scanf("%d", &x);
            employ[x-1].status = -1; // aka resigned
        }
        else if (process == 4){
            int x;
            scanf("%d", &x);
            employ[x-1].status = 2;
        }
    }

    for (int i = 0; i < index-1; i++){
        if (employ[i].status == 1){
            printf("%s\n", employ[i].name);
        }
    }
}