/*
Convert To Small

Lili is a little girl, little girls love little numbers especially those strictly under 10. She found big numbers that she wants to reduce to small numbers. She needs your help reducing these numbers into small numbers.
She reduces a number by changing it into the sum of its digits, but sometimes this is not good enough for her. Sometimes after she reduce a number once, it is still bigger than 10. She only likes numbers that are smaller than 10.
For example, she find a number 383, she converts it to 14, this is still bigger than 10, so she converts it to 5, which she considers as a little number as it is smaller than 10.
Because she's still a little girl, she needs you to do the grown up stuff and help her figure out the small number she will get as the result after a series of conversion.
Format Input
The first line of the input contains one integer T, the number big numbers Lili found. The next T lines contains integers X​i,​ the i-th big number.
Format Output
Print T lines, each line is the i-th result of each conversion from big number to small number.
Constraints
1 <= T <= 1000
1<=X​i​ <=1000000000

Sample Input 1​​ (standard input)
3
383
8 
2000000

Sample Output 1​​ (standard output)
Case #1: 5
Case #2: 8
Case #3: 2

Sample Input 2 (standard input)
5
66987 
348075 
34985 
8289 
700384

Sample Output 2 (standard output)
Case #1: 9
Case #2: 9
Case #3: 2
Case #4: 9
Case #5: 4
*/

#include <stdio.h>

int main(void){
    int cases;
    scanf("%d", &cases);

    for (int tc = 0; tc < cases; tc++){
        int num;
        scanf("%d", &num);

        int sum = 0;

        sum = num;

        while (sum > 10){
            sum = 0;
            while (num > 0){
                int digit = num % 10;
                sum += digit;
                num /= 10;
            }

            if (sum > 10){
                num = sum;
            }
        }

        printf("Case #%d: %d\n", tc+1, sum);
    }
}