#include <stdio.h>

// create board
char boardwhite[8][8];
char boardblack[8][8];

int main(void){

    int cases;
    scanf("%d", &cases);

    for (int tc = 0; tc < cases; tc++){
        
        // clear board for white and black
        for (int i = 0; i< 8; i++){
            for (int j = 0; j <8; j++){
                boardwhite[i][j] = '-';
            }
        }
        for (int i = 0; i< 8; i++){
            for (int j = 0; j <8; j++){
                boardblack[i][j] = '-';
            }
        }

        int steps;
        scanf("%d", &steps); getchar();

        char white[3];
        char black[3];
        scanf("%s %s", white, black);

        int row, col;
        
        // find white start coordinates
        row = '8' - white[1];
        col = white[0] - 65;

        // possible moves array
        int moves[2][8] = {
            {-2,-2,2,2,-1,-1,1,1}, // i
            {-1,1,-1,1,-2,2,-2,2}  // j
        };
        
        // mark white start coordinates
        boardwhite[row][col] = 'W';

        // find possible moves for white
        for (int step = 0; step < steps; step++){
            for (int i = 0; i < 8; i++){
                for(int j = 0; j < 8; j++){
                    
                    if (boardwhite[i][j] == 'W'){
                        // mark possible moves
                        if(i >= 2 &&  i <= 5){
                            if (j >= 2 && j <= 5){
                                // all possible
                                for (int y = 0; y < 8; y++){
                                    boardwhite[i+moves[0][y]][j+moves[1][y]] = '*';
                                }
                            }else if (j< 2){
                                if (j == 0){
                                    // j -1  and - 2 not possible
                                    for (int y = 0; y < 8; y++){
                                        if (moves[1][y] > -1) boardwhite[i+moves[0][y]][j+moves[1][y]] = '*';
                                    }
                                }
                                else{
                                    // j -2 not possible
                                    for (int y = 0; y< 8; y++){
                                        if (moves[1][y] > -2) boardwhite[i+moves[0][y]][j+moves[1][y]] = '*';
                                    }
                                }
                            }else if (j > 5){
                                if (j == 7){
                                    // j +1 and + 2 not possible
                                    for (int y = 0; y< 8; y++){
                                        if (moves[1][y] < 1) boardwhite[i+moves[0][y]][j+moves[1][y]] = '*';
                                    }
                                }
                                else{
                                    // j + 2 not possible
                                    for (int y = 0; y< 8; y++){
                                        if (moves[1][y] < 2) boardwhite[i+moves[0][y]][j+moves[1][y]] = '*';
                                    }
                                }
                            }
                        }else if (i < 2){
                            if (i == 0){
                                if (j >= 2 && j <= 5){
                                // i - 1 and -2 not possible
                                    for (int y = 0; y< 8; y++){
                                        if (moves[0][y] > -1) boardwhite[i+moves[0][y]][j+moves[1][y]] = '*';
                                    }
                                }else if (j< 2){
                                    if (j == 0){
                                        // j -1  and - 2 not possible i - 1 and -2 not possible
                                        for (int y = 0; y< 8; y++){
                                            if (moves[0][y] > -1 && moves[1][y] > -1) boardwhite[i+moves[0][y]][j+moves[1][y]] = '*';
                                        }
                                    }
                                    else{
                                        // j -2 not possible i - 1 and -2 not possible
                                        for (int y = 0; y< 8; y++){
                                            if (moves[0][y] > -1 && moves[1][y] > -2) boardwhite[i+moves[0][y]][j+moves[1][y]] = '*';
                                        }
                                    }                                    
                                }else if (j > 5){
                                    if (j == 7){
                                        // j +1 and + 2 not possible i - 1 and -2 not possible
                                        for (int y = 0; y< 8; y++){
                                            if (moves[0][y] > -1 && moves[1][y] < 1) boardwhite[i+moves[0][y]][j+moves[1][y]] = '*';
                                        }
                                    }
                                    else{
                                        // j + 2 not possible i - 1 and -2 not possible
                                        for (int y = 0; y< 8; y++){
                                            if (moves[0][y] > -1 && moves[1][y] < 2) boardwhite[i+moves[0][y]][j+moves[1][y]] = '*';
                                        }
                                    }
                                }
                            }
                            else{
                                if (j >= 2 && j <= 5){
                                // i - 2 not  possible                            
                                    for (int y = 0; y< 8; y++){
                                        if (moves[0][y] > -2) boardwhite[i+moves[0][y]][j+moves[1][y]] = '*';
                                    }                              
                                }else if (j< 2){
                                    if (j == 0){
                                        // j -1  and - 2 not possible i - 2 not  possible
                                        for (int y = 0; y< 8; y++){
                                            if (moves[0][y] > -2 && moves[1][y] > -1) boardwhite[i+moves[0][y]][j+moves[1][y]] = '*';
                                        }
                                    }
                                    else{
                                        // j -2 not possible i - 2 not  possible
                                        for (int y = 0; y< 8; y++){
                                            if (moves[0][y] > -2 && moves[1][y] > -2) boardwhite[i+moves[0][y]][j+moves[1][y]] = '*';
                                        }
                                    }                                    
                                }else if (j > 5){
                                    if (j == 7){
                                        // j +1 and + 2 not possible i - 2 not  possible
                                        for (int y = 0; y< 8; y++){
                                            if (moves[0][y] > -2 && moves[1][y] < 1) boardwhite[i+moves[0][y]][j+moves[1][y]] = '*';
                                        }
                                    }
                                    else{
                                        // j + 2 not possible i - 2 not  possible
                                        for (int y = 0; y< 8; y++){
                                            if (moves[0][y] > -2 && moves[1][y] < 2) boardwhite[i+moves[0][y]][j+moves[1][y]] = '*';
                                        }
                                    }
                                }
                            }
                        } else if (i > 5){
                            if (i == 7){
                                if (j >= 2 && j <= 5){
                                // i +1 and +2 not possible
                                    for (int y = 0; y< 8; y++){
                                        if (moves[0][y] < 1) boardwhite[i+moves[0][y]][j+moves[1][y]] = '*';
                                    }
                                }else if (j< 2){
                                    if (j == 0){
                                        // j -1  and - 2 not possible i + 1 and +2 not possible
                                        for (int y = 0; y< 8; y++){
                                            if (moves[0][y] < 1 && moves[1][y] > -1) boardwhite[i+moves[0][y]][j+moves[1][y]] = '*';
                                        }
                                    }
                                    else{
                                        // j -2 not possible i + 1 and +2 not possible
                                        for (int y = 0; y< 8; y++){
                                            if (moves[0][y] < 1 && moves[1][y] > -2) boardwhite[i+moves[0][y]][j+moves[1][y]] = '*';
                                        }
                                    }                                    
                                }else if (j > 5){
                                    if (j == 7){
                                        // j +1 and + 2 not possible i +1 and +2 not possible
                                        for (int y = 0; y< 8; y++){
                                            if (moves[0][y] < 1 && moves[1][y] < 1) boardwhite[i+moves[0][y]][j+moves[1][y]] = '*';
                                        }
                                    }
                                    else{
                                        // j + 2 not possible i + 1 and +2 not possible
                                        for (int y = 0; y< 8; y++){
                                            if (moves[0][y] < 1 && moves[1][y] < 2) boardwhite[i+moves[0][y]][j+moves[1][y]] = '*';
                                        }
                                    }
                                }
                            }
                            else{
                                if (j >= 2 && j <= 5){
                                // i + 2 not  possible
                                    for (int y = 0; y< 8; y++){
                                        if (moves[0][y] < 2) boardwhite[i+moves[0][y]][j+moves[1][y]] = '*';
                                    }
                                }else if (j< 2){
                                    if (j == 0){
                                        // j -1  and - 2 not possible i + 2 not  possible
                                        for (int y = 0; y< 8; y++){
                                            if (moves[0][y] < 2 && moves[1][y] > -1) boardwhite[i+moves[0][y]][j+moves[1][y]] = '*';
                                        }
                                    }
                                    else{
                                        // j -2 not possible i + 2 not  possible
                                        for (int y = 0; y< 8; y++){
                                            if (moves[0][y] < 2 && moves[1][y] > -2) boardwhite[i+moves[0][y]][j+moves[1][y]] = '*';
                                        }
                                    }                                   
                                }else if (j > 5){
                                    if (j == 7){
                                        // j +1 and + 2 not possible i + 2 not  possible
                                        for (int y = 0; y< 8; y++){
                                            if (moves[0][y] < 2 && moves[1][y] < 1) boardwhite[i+moves[0][y]][j+moves[1][y]] = '*';
                                        }
                                    }
                                    else{
                                        // j + 2 not possible i + 2 not  possible
                                        for (int y = 0; y< 8; y++){
                                            if (moves[0][y] < 2 && moves[1][y] < 2) boardwhite[i+moves[0][y]][j+moves[1][y]] = '*';
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }

            
            if (step < steps -1){
                for (int i = 0; i < 8; i++){
                    for (int j = 0; j < 8;j++){
                        // change all marked moves into "start" positions for next loop
                        if (boardwhite[i][j] == '*'){
                            boardwhite [i][j] = 'W';
                        }
                        // change all "start" positions in the loop to marked moves
                        else if (boardwhite[i][j] == 'W'){
                            boardwhite[i][j] = '*';
                        }
                    }
                }
            }
            else{
                for (int i = 0; i < 8; i++){
                    for (int j = 0; j < 8;j++){
                        // change all "start" positions in the loop to marked moves (for last loop)
                        if (boardwhite[i][j] == 'W'){
                            boardwhite[i][j] = '*';
                        }
                    }
                }
            }  
        }

        // find black start coordinates
        row = '8' - black[1];
        col = black[0] - 65;

        // mark black start coordinates
        boardblack[row][col] = 'B';

        // find possible moves for black (same as white)
        for (int step = 0; step < steps; step++){
            for (int i = 0; i < 8; i++){
                for(int j = 0; j < 8; j++){
                    
                    if (boardblack[i][j] == 'B'){
                        // mark possible moves
                        if(i >= 2 &&  i <= 5){
                            if (j >= 2 && j <= 5){
                                // all possible
                                for (int y = 0; y < 8; y++){
                                    boardblack[i+moves[0][y]][j+moves[1][y]] = '*';
                                }
                            }else if (j< 2){
                                if (j == 0){
                                    // j -1  and - 2 not possible
                                    for (int y = 0; y < 8; y++){
                                        if (moves[1][y] > -1) boardblack[i+moves[0][y]][j+moves[1][y]] = '*';
                                    }
                                }
                                else{
                                    // j -2 not possible
                                    for (int y = 0; y< 8; y++){
                                        if (moves[1][y] > -2) boardblack[i+moves[0][y]][j+moves[1][y]] = '*';
                                    }
                                }
                            }else if (j > 5){
                                if (j == 7){
                                    // j +1 and + 2 not possible
                                    for (int y = 0; y< 8; y++){
                                        if (moves[1][y] < 1) boardblack[i+moves[0][y]][j+moves[1][y]] = '*';
                                    }
                                }
                                else{
                                    // j + 2 not possible
                                    for (int y = 0; y< 8; y++){
                                        if (moves[1][y] < 2) boardblack[i+moves[0][y]][j+moves[1][y]] = '*';
                                    }
                                }
                            }
                        }else if (i < 2){
                            if (i == 0){
                                if (j >= 2 && j <= 5){
                                // i - 1 and -2 not possible
                                    for (int y = 0; y< 8; y++){
                                        if (moves[0][y] > -1) boardblack[i+moves[0][y]][j+moves[1][y]] = '*';
                                    }
                                }else if (j< 2){
                                    if (j == 0){
                                        // j -1  and - 2 not possible i - 1 and -2 not possible
                                        for (int y = 0; y< 8; y++){
                                            if (moves[0][y] > -1 && moves[1][y] > -1) boardblack[i+moves[0][y]][j+moves[1][y]] = '*';
                                        }
                                    }
                                    else{
                                        // j -2 not possible i - 1 and -2 not possible
                                        for (int y = 0; y< 8; y++){
                                            if (moves[0][y] > -1 && moves[1][y] > -2) boardblack[i+moves[0][y]][j+moves[1][y]] = '*';
                                        }
                                    }                                    
                                }else if (j > 5){
                                    if (j == 7){
                                        // j +1 and + 2 not possible i - 1 and -2 not possible
                                        for (int y = 0; y< 8; y++){
                                            if (moves[0][y] > -1 && moves[1][y] < 1) boardblack[i+moves[0][y]][j+moves[1][y]] = '*';
                                        }
                                    }
                                    else{
                                        // j + 2 not possible i - 1 and -2 not possible
                                        for (int y = 0; y< 8; y++){
                                            if (moves[0][y] > -1 && moves[1][y] < 2) boardblack[i+moves[0][y]][j+moves[1][y]] = '*';
                                        }
                                    }
                                }
                            }
                            else{
                                if (j >= 2 && j <= 5){
                                // i - 2 not  possible                            
                                    for (int y = 0; y< 8; y++){
                                        if (moves[0][y] > -2) boardblack[i+moves[0][y]][j+moves[1][y]] = '*';
                                    }                              
                                }else if (j< 2){
                                    if (j == 0){
                                        // j -1  and - 2 not possible i - 2 not  possible
                                        for (int y = 0; y< 8; y++){
                                            if (moves[0][y] > -2 && moves[1][y] > -1) boardblack[i+moves[0][y]][j+moves[1][y]] = '*';
                                        }
                                    }
                                    else{
                                        // j -2 not possible i - 2 not  possible
                                        for (int y = 0; y< 8; y++){
                                            if (moves[0][y] > -2 && moves[1][y] > -2) boardblack[i+moves[0][y]][j+moves[1][y]] = '*';
                                        }
                                    }                                    
                                }else if (j > 5){
                                    if (j == 7){
                                        // j +1 and + 2 not possible i - 2 not  possible
                                        for (int y = 0; y< 8; y++){
                                            if (moves[0][y] > -2 && moves[1][y] < 1) boardblack[i+moves[0][y]][j+moves[1][y]] = '*';
                                        }
                                    }
                                    else{
                                        // j + 2 not possible i - 2 not  possible
                                        for (int y = 0; y< 8; y++){
                                            if (moves[0][y] > -2 && moves[1][y] < 2) boardblack[i+moves[0][y]][j+moves[1][y]] = '*';
                                        }
                                    }
                                }
                            }
                        } else if (i > 5){
                            if (i == 7){
                                if (j >= 2 && j <= 5){
                                // i +1 and +2 not possible
                                    for (int y = 0; y< 8; y++){
                                        if (moves[0][y] < 1) boardblack[i+moves[0][y]][j+moves[1][y]] = '*';
                                    }
                                }else if (j< 2){
                                    if (j == 0){
                                        // j -1  and - 2 not possible i + 1 and +2 not possible
                                        for (int y = 0; y< 8; y++){
                                            if (moves[0][y] < 1 && moves[1][y] > -1) boardblack[i+moves[0][y]][j+moves[1][y]] = '*';
                                        }
                                    }
                                    else{
                                        // j -2 not possible i + 1 and +2 not possible
                                        for (int y = 0; y< 8; y++){
                                            if (moves[0][y] < 1 && moves[1][y] > -2) boardblack[i+moves[0][y]][j+moves[1][y]] = '*';
                                        }
                                    }                                    
                                }else if (j > 5){
                                    if (j == 7){
                                        // j +1 and + 2 not possible i +1 and +2 not possible
                                        for (int y = 0; y< 8; y++){
                                            if (moves[0][y] < 1 && moves[1][y] < 1) boardblack[i+moves[0][y]][j+moves[1][y]] = '*';
                                        }
                                    }
                                    else{
                                        // j + 2 not possible i + 1 and +2 not possible
                                        for (int y = 0; y< 8; y++){
                                            if (moves[0][y] < 1 && moves[1][y] < 2) boardblack[i+moves[0][y]][j+moves[1][y]] = '*';
                                        }
                                    }
                                }
                            }
                            else{
                                if (j >= 2 && j <= 5){
                                // i + 2 not  possible
                                    for (int y = 0; y< 8; y++){
                                        if (moves[0][y] < 2) boardblack[i+moves[0][y]][j+moves[1][y]] = '*';
                                    }
                                }else if (j< 2){
                                    if (j == 0){
                                        // j -1  and - 2 not possible i + 2 not  possible
                                        for (int y = 0; y< 8; y++){
                                            if (moves[0][y] < 2 && moves[1][y] > -1) boardblack[i+moves[0][y]][j+moves[1][y]] = '*';
                                        }
                                    }
                                    else{
                                        // j -2 not possible i + 2 not  possible
                                        for (int y = 0; y< 8; y++){
                                            if (moves[0][y] < 2 && moves[1][y] > -2) boardblack[i+moves[0][y]][j+moves[1][y]] = '*';
                                        }
                                    }                                   
                                }else if (j > 5){
                                    if (j == 7){
                                        // j +1 and + 2 not possible i + 2 not  possible
                                        for (int y = 0; y< 8; y++){
                                            if (moves[0][y] < 2 && moves[1][y] < 1) boardblack[i+moves[0][y]][j+moves[1][y]] = '*';
                                        }
                                    }
                                    else{
                                        // j + 2 not possible i + 2 not  possible
                                        for (int y = 0; y< 8; y++){
                                            if (moves[0][y] < 2 && moves[1][y] < 2) boardblack[i+moves[0][y]][j+moves[1][y]] = '*';
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if (step < steps -1){
                for (int i = 0; i < 8; i++){
                    for (int j = 0; j < 8;j++){
                        if (boardblack[i][j] == '*'){
                            boardblack[i][j] = 'B';
                        }
                        else if (boardblack[i][j] == 'B'){
                            boardblack[i][j] = '*';
                        }
                    }
                }
            } 
            else{
                for (int i = 0; i < 8; i++){
                    for (int j = 0; j < 8;j++){
                        if (boardblack[i][j] == 'B'){
                            boardblack[i][j] = '*';
                        }
                    }
                }
            }   
        }
        
        // check if knights can meet
        int flag = 0;
        for (int i = 0; i< 8; i++){
            for (int j = 0; j <8; j++){
                if (boardwhite[i][j] == '*' && boardblack[i][j] == '*'){
                    flag = 1;
                }
            }
        }

        // output
        if (flag == 1){
            printf("Case #%d: YES\n", tc+1);
        }
        else{
            printf("Case #%d: NO\n", tc+1);
        }
    }
}