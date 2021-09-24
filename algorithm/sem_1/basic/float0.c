// Write a C program that accepts two item’s weight (floating points' values ) 
// and number of purchase (floating points' values) 
// and calculate the average value of the items

#include <stdio.h>

int main(void)
{
    float weight1;
    int item1;
    scanf("%f %d", &weight1, &item1);

    float weight2;
    int item2;
    scanf("%f %d", &weight2, &item2);

    float total = ((weight1 * item1) + (weight2 * item2)) / (item1 + item2);
    printf("Average Value = %f\n", total);
}