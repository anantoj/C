/*
Ranking

Professor Jojo wants to make ranking for his students. He thinks that each student will take place equal to 1 + (number of students with strictly higher score than his or her). So, students with the same score will have the same rank. Help him determine the rank for each student.
Format Input
The input begins with an integer T indicating the number of test cases. In each test case, the first line contains a positive integer N, the number of students. The second line contains N integer A​i,​ the score of student i.
Format Output
For each test case, output the rank of each student.
Constraints
1 <= T <= 100
1 <= N <= 1000 0 <= A_i <= 100

Sample Input​ (standard input)
2
3
1 3 3
3
1 2 3

Sample Output​ (standard output)
Case #1: 3 1 1
Case #2: 3 2 1

*/

#include <stdio.h>

typedef struct{
    int score;
    int rank;
    int pos;
}data;

int main(void){
    int cases;
    scanf("%d", &cases);

    for (int tc = 0; tc < cases; tc++){
        int size;
        scanf("%d", &size);
        data arr[size];
        for (int i = 0; i < size; i++){
            scanf("%d", &arr[i].score);
            arr[i].rank = 1;
        }

        for (int i = 0; i < size;i++){
            for (int j = 0; j < size; j++){
                if (j==i) continue;
                else{
                    if (arr[i].score < arr[j].score)
                    arr[i].rank++;
                }
            }
        }

        printf("Case #%d:",tc+1);
        for (int i = 0; i < size; i++){
            printf(" %d", arr[i].rank);
        }
        printf("\n");

    }
}