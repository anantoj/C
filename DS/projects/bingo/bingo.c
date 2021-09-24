#include <stdio.h>

int main(void)
{
    char arr[3][3] =
    { 
        {'-','-','-',},
        {'-','-','-',},
        {'-','-','-',},
    };
    int win = 0;
    int counter = 2;
    do
    {
        printf("XO Table\n=-=-=-=-=-\n");
        printf("\n\t  1 2 3\n");
        for (int i = 0; i < 3; i++)
        {
            printf("\t%d ", i+1);
            for (int j = 0; j < 3; j++)
            {
                printf("%c " , arr[j][i]);
            }
            printf("\n");
        }
        int xcor;
        int ycor;
        printf("Insert X-Coordinate: ");
        scanf("%d", &xcor);
        printf("Insert Y-Coordinate: ");
        scanf("%d", &ycor);
        if (counter % 2 == 0)
        {
            if (arr[xcor-1][ycor-1] == '-'){
                arr[xcor-1][ycor-1] = 'X';
            }
            else{
                printf("INVALID COORDINATE\nPRESS ENTER TO CONTINUE..."); getchar(); getchar();
                counter--;
            }
        }
        else
        { 
            if (arr[xcor-1][ycor-1] == '-'){
                arr[xcor-1][ycor-1] = 'O';
            }
            else{
                printf("INVALID COORDINATE\nPRESS ENTER TO CONTINUE..."); getchar(); getchar();
                counter--;
            }
        }
        counter++;


        int x_check = 0;
        int o_check = 0;

        if (win == 0){
            for (int i = 0; i < 3; i++){
                x_check = 0;
                o_check = 0;
                for (int j = 0; j < 3; j++){
                    if (arr[i][j] == '-'){
                        break;
                    }
                    else{
                        if (arr[i][j] == 'X')
                            x_check++;
                        else if (arr[i][j] == 'O')
                            o_check++;
                    }
                }
                if (x_check == 3 || o_check == 3){
                    win = 1;
                    break;
                }       
            }
            if (win == 1 && x_check == 3){
                printf("X WINS!\n");
            }
            else if (win == 1 && o_check == 3){
                printf("O WINS!\n");
            }
        }

        if (win == 0){
            for (int i = 0; i < 3; i++){
                x_check = 0;
                o_check = 0;
                for (int j = 0; j < 3; j++){
                    if (arr[j][i] == '-'){
                        break;
                    }
                    else{
                        if (arr[i][j] == 'X')
                            x_check++;
                        else if(arr[i][j] == 'O')
                            o_check++;
                    }
                }
                if (x_check == 3 || o_check == 3){
                    win = 1;
                    break;
                }       
            }
            if (win == 1 && x_check == 3){
                printf("X WINS!\n");
            }
            else if (win == 1 && o_check == 3){
                printf("O WINS!\n");
            }
        }

        if (win == 0){
            x_check = 0;
            o_check = 0;
            for (int i = 0; i < 3; i++){
                for (int j = 0; j < 3; j++){
                    if (i == j){
                        if (arr[i][j] == 'X')
                            x_check++;
                        else if (arr[i][j] == 'O')
                            o_check++;
                    }
                }
            }

            if (x_check == 3 || o_check == 3){
                win = 1;
            }  
            if (win == 1 && x_check == 3){
                printf("X WINS!\n");
            }
            else if (win == 1 && o_check == 3){
                printf("O WINS!\n");
            }
        }
        
        if (win == 0){
            x_check = 0;
            o_check = 0;
            for (int i = 0; i < 3; i++){
                for (int j = 0; j < 3; j++){
                    if (i + j == 2){
                        if (arr[i][j] == 'X')
                            x_check++;
                        else if (arr[i][j] == 'O')
                            o_check++;
                    }
                }
            }

            if (x_check == 3 || o_check == 3){
                win = 1;
            }  
            if (win == 1 && x_check == 3){
                printf("X WINS!\n");
            }
            else if (win == 1 && o_check == 3){
                printf("O WINS!\n");
            }
        }
    }while (win != 1);
    for (int i = 0; i < 3; i++)
        {
            printf("\t%d ", i+1);
            for (int j = 0; j < 3; j++)
            {
                printf("%c " , arr[j][i]);
            }
            printf("\n");
        }
}
