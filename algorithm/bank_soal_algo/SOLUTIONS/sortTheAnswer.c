/*
Sort The Answer

Jojo and his classmates like to answer question not in sequence. This make their teacher confuse when checking their answer. So their teacher asked you to sort their answer by the smallest number to the largest, it is guranteed that all number only appear once. Because you don't have time to do it manually you have to make a program to read input from "​testdata.in​​" and output the sorted sequence of given answer in console. To make this problem easier try using struct.
Format Input
The first line contain an integer T represents the number of test cases. Each test case start with integer N represents how many answer there are. The next N-lines is formatted "A. X" where A is an integer represents the problem's number and X is a character represents the answer.
Format Output
The sorted answer for each test cases.
Constraints
1 <= T <= 20
1 <= N <= 100
1 <= A <= N
It is guaranteed that A is all distinct in a single test case. It is guaranteed that X is an uppercase character.

Sample Input​​ (testdata.in)
4
2
2. A
1. B
5
1. A
5. B
3. D
4. E
2. C
1
1. C
5
5. E
4. D
3. C
2. B
1. A

Sample Output​​ (standard output)
Case #1:
1. B
2. A
Case #2:
1. A
2. C
3. D
4. E
5. B
Case #3:
1. C
Case #4:
1. A
2. B
3. C
4. D
5. E
*/



#include <stdio.h>

typedef struct{
    int num;
    char ans;
}data;

int main(void){

    FILE *fp;

    fp = fopen("sortTheAnswer.in", "r");

    int cases;
    fscanf(fp, "%d\n", &cases);

    for (int tc = 0; tc < cases; tc++){
        int n; // number or answers
        fscanf(fp, "%d\n", &n);

        data answer[n];

        for(int i = 0; i < n; i++){
            fscanf(fp, "%d. %c\n", &answer[i].num, &answer[i].ans);
        }

        for (int i = 0; i < n-1; i++){
            for (int j = 0; j < n - i - 1; j++){
                if (answer[j].num > answer[j+1].num){
                    int tmp = answer[j].num;
                    answer[j].num = answer[j+1].num;
                    answer[j+1].num = tmp;

                    char temp = answer[j].ans;
                    answer[j].ans = answer[j+1].ans;
                    answer[j+1].ans = temp;
                }
            }
        }

        printf("Case #%d:\n", tc+1);
        for (int i = 0; i < n; i++){
            printf("%d. %c\n", answer[i].num, answer[i].ans);
        }
    }
}