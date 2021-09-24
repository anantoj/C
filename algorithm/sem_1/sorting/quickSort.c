#include <stdio.h>
#include <string.h>

void swap(char *a,  char *b) { 
    char tmp = *a; 
    *a = *b; 
    *b = tmp; 
}
int partition(char str[], int low , int high){
    char pivot = str[high];
    int i = (low -1);

     for (int j = low; j <= high- 1; j++){
        if (str[j] < pivot){
            i++;
            swap(&str[i], &str[j]);
        }
     }
     swap(&str[i+1], &str[high]);
     return(i+1);
}
void quickSort(char str[], int low, int high){
    if (low < high){
        int pi = partition(str,low, high);
        quickSort(str, low, pi - 1); 
        quickSort(str, pi + 1, high);    
    }
}
int main(void){
    char str[101] = "HELLO";
    quickSort(str, 0, strlen(str)-1);
    printf("%s\n", str);
    return 0;
}