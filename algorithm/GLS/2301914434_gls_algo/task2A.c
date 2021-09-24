#include <stdio.h>
#include <string.h>

typedef struct{
    char id[101];
    char name[101];
    char city[101];
    char gender[101];
    char car[101];
    char property[101];
}data;

char str[6][101] = {
    "id",
    "first_name",
    "city",
    "gender",
    "has_car",
    "has_property",
}; 

int main(void){
    FILE *fp;

    fp = fopen("customer_app_data.csv", "r");
    int index = 0;
    char trash[101];
    if (fp!=NULL){
        while (!feof(fp)){
            index++;
            fscanf(fp, "%s\n", trash);
        }
        fclose(fp);
    }

    index = index - 1; // because header needs to be thrown away

    fp = fopen("customer_app_data.csv", "r");

    if (fp !=NULL){
        data customer[index];

        // while scan

        int i = -1;  // Header needs to be thrown away
        while(!feof(fp)){
            if (i == -1){
                fscanf(fp, "%s\n", trash);
            }
            else{
                fscanf(fp,  "%[^;];%[^;];%[^;];%[^;];%[^;];%[^\n]\n", customer[i].id,customer[i].name,customer[i].city,customer[i].gender, customer[i].car,customer[i].property);
            }
            i++;   
        }

        printf("Query: ");

        char col_filter[100] = " ";
        char key[100];
        char value[100];

        int show = 0;

        scanf("SHOW %s", col_filter); 

        char c = getchar();

        if (c == ' '){
            scanf("WHERE %s equals %s", key, value);
        }
        else{
            show = 1;
        }

        // collumn filter
        int numquery = 1; 
      
        int star = 0;

        if (strcmp(col_filter, "*") == 0){
            star = 1;
        }
        for (int i = 0; i <strlen(col_filter); i++){
            if (star == 1){
                break;
            }
            if (col_filter[i] == ','){
                numquery++;
            }
        }
        
        int filter_index = 0;

        int arr[6] = {};

        if (star == 1){
            for (int i = 0; i < 6; i++){
                arr[i] = 1;
            }

            for (int i = 0; i < 6; i++){
                if (strcmp(str[i], key) == 0){
                    arr[i] = 0;
                }
            }
        }
        
        for (int i = 0; i < numquery; i++){
            if (star == 1){
                break;
            }
            char compare[101] = " ";
            int cmp_index = 0;
            while(col_filter[filter_index] != '\0' && col_filter[filter_index] != ','){
                compare[cmp_index] = col_filter[filter_index];
                cmp_index++;
                filter_index++;
            }
            filter_index++;

            for (int j = 0; j <6; j++){
                if(strcmp(compare,str[j]) == 0){
                    arr[j]++;
                }
            }
        }

        int keycode;
        for (int i = 0; i < 6; i++){
            if (strcmp(str[i], key) == 0){
                keycode = i;
            }
        }

        char info[101];

        printf("Result:\n");

        if (show == 1){
            char tmp[6][101];
            for (int i = 0; i < index; i++){
                strcpy(tmp[0], customer[i].id);
                strcpy(tmp[1], customer[i].name);
                strcpy(tmp[2], customer[i].city);
                strcpy(tmp[3], customer[i].gender);
                strcpy(tmp[4], customer[i].car);
                strcpy(tmp[5], customer[i].property);
                int coma = 0;
                for (int x = 0; x < 6; x++) {
                    if (arr[x] != 0){
                        if (coma == 0){
                            printf("%s: %s", str[x], tmp[x]);
                            coma++;
                        }
                        else
                            printf(", %s: %s", str[x], tmp[x]);
                    }
                }
                printf("\n");
            }
            return 0;
        }


        if (keycode == 0){
            char tmp[6][101];
            for (int i = 0; i <index; i++){
                if (strcmp(customer[i].id, value) == 0){

                    strcpy(tmp[0], customer[i].id);
                    strcpy(tmp[1], customer[i].name);
                    strcpy(tmp[2], customer[i].city);
                    strcpy(tmp[3], customer[i].gender);
                    strcpy(tmp[4], customer[i].car);
                    strcpy(tmp[5], customer[i].property);
                    int coma = 0;
                    for (int x = 0; x < 6; x++) {
                        if (arr[x] != 0){
                            if (coma == 0){
                                printf("%s: %s", str[x], tmp[x]);
                                coma++;
                            }
                            else
                                printf(", %s: %s", str[x], tmp[x]);
                        }
                    }
                    printf("\n");
                }
            }
        }
        else if (keycode == 1){
            char tmp[6][101];
            for (int i = 0; i <index; i++){
                if (strcmp(customer[i].name, value) == 0){

                    strcpy(tmp[0], customer[i].id);
                    strcpy(tmp[1], customer[i].name);
                    strcpy(tmp[2], customer[i].city);
                    strcpy(tmp[3], customer[i].gender);
                    strcpy(tmp[4], customer[i].car);
                    strcpy(tmp[5], customer[i].property);
                    int coma = 0;
                    for (int x = 0; x < 6; x++) {
                        if (arr[x] != 0){
                            if (coma == 0){
                                printf("%s: %s", str[x], tmp[x]);
                                coma++;
                            }
                            else
                                printf(", %s: %s", str[x], tmp[x]);
                        }
                    }
                    printf("\n");
                }
            }
        }
        else if (keycode == 2){
            char tmp[6][101];
            for (int i = 0; i <index; i++){
                if (strcmp(customer[i].city, value) == 0){

                    strcpy(tmp[0], customer[i].id);
                    strcpy(tmp[1], customer[i].name);
                    strcpy(tmp[2], customer[i].city);
                    strcpy(tmp[3], customer[i].gender);
                    strcpy(tmp[4], customer[i].car);
                    strcpy(tmp[5], customer[i].property);

                    int coma = 0;
                    for (int x = 0; x < 6; x++) {
                        if (arr[x] != 0){
                            if (coma == 0){
                                printf("%s: %s", str[x], tmp[x]);
                                coma++;
                            }
                            else
                                printf(", %s: %s", str[x], tmp[x]);
                        }
                    }
                    printf("\n");
                }
            }
        }
        else if (keycode == 3){
            char tmp[6][101];
            for (int i = 0; i <index; i++){
                if (strcmp(customer[i].gender, value) == 0){

                    strcpy(tmp[0], customer[i].id);
                    strcpy(tmp[1], customer[i].name);
                    strcpy(tmp[2], customer[i].city);
                    strcpy(tmp[3], customer[i].gender);
                    strcpy(tmp[4], customer[i].car);
                    strcpy(tmp[5], customer[i].property);

                    int coma = 0;
                    for (int x = 0; x < 6; x++) {
                        if (arr[x] != 0){
                            if (coma == 0){
                                printf("%s: %s", str[x], tmp[x]);
                                coma++;
                            }
                            else
                                printf(", %s: %s", str[x], tmp[x]);
                        }
                    }
                    printf("\n");
                }
            }
        }
        else if (keycode == 4){
            char tmp[6][101];
            for (int i = 0; i <index; i++){
                if (strcmp(customer[i].car, value) == 0){

                    strcpy(tmp[0], customer[i].id);
                    strcpy(tmp[1], customer[i].name);
                    strcpy(tmp[2], customer[i].city);
                    strcpy(tmp[3], customer[i].gender);
                    strcpy(tmp[4], customer[i].car);
                    strcpy(tmp[5], customer[i].property);

                    int coma = 0;
                    for (int x = 0; x < 6; x++) {
                        if (arr[x] != 0){
                            if (coma == 0){
                                printf("%s: %s", str[x], tmp[x]);
                                coma++;
                            }
                            else
                                printf(", %s: %s", str[x], tmp[x]);
                        }
                    }
                    printf("\n");
                }
            }
        }
        else if (keycode == 5){
            char tmp[6][101];
            for (int i = 0; i <index; i++){
                if (customer[i].property[0] == 'Y' && value[0] == 'Y'){

                    strcpy(tmp[0], customer[i].id);
                    strcpy(tmp[1], customer[i].name);
                    strcpy(tmp[2], customer[i].city);
                    strcpy(tmp[3], customer[i].gender);
                    strcpy(tmp[4], customer[i].car);
                    strcpy(tmp[5], customer[i].property);

                    int coma = 0;
                    for (int x = 0; x < 6; x++) {
                        if (arr[x] != 0){
                            if (coma == 0){
                                printf("%s: %s", str[x], tmp[x]);
                                coma++;
                            }
                            else
                                printf(", %s: %s", str[x], tmp[x]);
                        }
                    }
                    printf("\n");
                }
                else if (customer[i].property[0] == 'N' && value[0] == 'N'){

                    strcpy(tmp[0], customer[i].id);
                    strcpy(tmp[1], customer[i].name);
                    strcpy(tmp[2], customer[i].city);
                    strcpy(tmp[3], customer[i].gender);
                    strcpy(tmp[4], customer[i].car);
                    strcpy(tmp[5], customer[i].property);

                    int coma = 0;
                    for (int x = 0; x < 6; x++) {
                        if (arr[x] != 0){
                            if (coma == 0){
                                printf("%s: %s", str[x], tmp[x]);
                                coma++;
                            }
                            else
                                printf(", %s: %s", str[x], tmp[x]);
                        }
                    }
                    printf("\n");
                }
            }
        }
    }
}