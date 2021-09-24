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
    if (arr[xcor-1][ycor-1] == 'X' || arr[xcor-1][ycor-1] == 'O')
    {
        printf("\nINVALID COORDINATE\n");
    }
    else if (counter % 2 == 0)
    {
      arr[xcor-1][ycor-1] = 'X';
      counter++;
    }
    else
    {
        arr[xcor-1][ycor-1] = 'O';
        counter++;
    }
    
  }
    while (win != 1);
}