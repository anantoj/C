/*
Busy

Jojo, as a businessman, is very busy. Sometimes, he has more than 1 agendas in a period of time, thus he can't fulfill it. As his friend, you want to help him check whether he can fulfill all agendas or not. To make it easier, the time will be in the form of positive integer.
Format Input
The input begins with an integer T indicating the number of test cases. In each test case, there is an integer N indicating the number of agendas. In the next N lines, there are 2 integers ai and bi, indicating the starting and ending of the agenda. You may assume that a​i​ <= a​i+1.​
Format Output
For each test case, output YES if Jojo can fulfill all agenda, otherwise output NO.
Constraints
1 <= T <= 10
1 <= N <= 10 000
1 <= a​i​ < b​i​ <= 100 000

Sample Input​​ (standard input)
2
3 
1 5 
5 20 
31 60 
2 
1 5 
4 10

Sample Output​​ (standard output)
Case #1: YES 
Case #2: NO
*/

#include <stdio.h>

int main(void){
    int cases;
    scanf("%d", &cases);

    for (int tc = 0; tc <cases; tc++){
        int agenda;
        scanf("%d", &agenda);

        int start, finish;

        int busy = 0;

        int arr[100001] = {};

        for (int i = 0; i < agenda; i++){
            scanf("%d %d", &start, &finish);

            for (int j = start; j < finish; j++){
                if (arr[j] != 1){
                    arr[j] = 1;
                }
                else{
                    busy = 1;
                    break;
                } 
            }
            
        }

        if (busy == 0){
            printf("Case #%d: YES\n", tc+1);
        }
        else{
            printf("Case #%d: NO\n", tc+1);
        }
    }
}