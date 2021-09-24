/*
Frequency

Jojo loves to give Bibi array of character. Because Bibi loves to make various of sentences, every array of character is divided into a single character. Now after dividing the array of character, Bibi is confuses because there are too many word. Help Bibi by printing the total of each character (Case insensitive = Upper Case and Lower Case are treated the same).
Format Input
The input will consist of several lines contains a lot of numbers in ​testdata.in file. Input starts with an integer T which indicates the total of testcase. The next T line consists multiple array of character. Multiple array length does not exceed 1000 characters and the characters only contain uppercase and lowercase letter.
Format Output
Output "Case #%d:" with 6 line total of each character with some formating (Character in Upper Case : total). Dont forget to print newline after testcase. Please refer the sample output for clarity.
Constraints
1 <= T <= 10

Sample Input​ (testdata.in)
3
ABCDE FGHIJ KLMNO PQRST UVWXYZ 
abcdefghij klmnopqrst uvwxyz 
AaBbCcDdEe FfGgHhIiJj

Sample Output​ (standard output)
Case #1:
A : 1, B : 1, C : 1, D : 1, E : 1
F : 1, G : 1, H : 1, I : 1, J : 1
K : 1, L : 1, M : 1, N : 1, O : 1
P : 1, Q : 1, R : 1, S : 1, T : 1
U : 1, V : 1, W : 1, X : 1, Y : 1
Z : 1

Case #2:
A : 1, B : 1, C : 1, D : 1, E : 1
F : 1, G : 1, H : 1, I : 1, J : 1
K : 1, L : 1, M : 1, N : 1, O : 1
P : 1, Q : 1, R : 1, S : 1, T : 1
U : 1, V : 1, W : 1, X : 1, Y : 1
Z : 1

Case #3:
A : 2, B : 2, C : 2, D : 2, E : 2
F : 2, G : 2, H : 2, I : 2, J : 2
K : 0, L : 0, M : 0, N : 0, O : 0
P : 0, Q : 0, R : 0, S : 0, T : 0
U : 0, V : 0, W : 0, X : 0, Y : 0
Z : 0

*/


#include <stdio.h>
#include <string.h>

int main(void){
    FILE *fp;

    fp = fopen("frequency.in", "r");

    if (fp != NULL){
        int cases;
        fscanf(fp, "%d\n", &cases);

        for (int tc = 0; tc < cases; tc++){
            char str[1001];
            fscanf(fp, "%[^\n]\n", str);

            int alpha[26] = {};

            for (int i = 0; i < strlen(str); i++){
                if (str[i] != ' ' && str[i] >= 97){
                    str[i] -= 32;
                }
                if (str[i] != ' '){
                    alpha[str[i]- 65]++;
                }
            }

            printf("Case #%d:\n", tc+1);

            for (int i = 0; i < 26; i++){
                if ((i+1) % 5 == 0 || i == 25){
                    printf("%c : %d\n", i+65, alpha[i]);
                }
                else{
                    printf("%c : %d, ", i+65, alpha[i]);
                } 
            }
            printf("\n");
        }
    }
}