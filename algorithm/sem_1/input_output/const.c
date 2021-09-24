// calculates the volume of a sphere from a given radius
// CARE: use int.0 in all int/int calculations ESPECIALLY if it is bracketed TO BE SAFE



#include <stdio.h>

const float pi = 3.14159265358979323846264338327950288419716939937510;

int main(void)
{
    float rad;
    printf("Input radius: ");
    scanf("%f", &rad);

    float vol =  (4.0/3) pi *(rad * rad * rad); // 4.0 is very IMPORTANT (typecasting)

    printf("%f\n", vol);
}