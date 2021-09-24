#include <stdio.h>
#include <stdlib.h>

int main()
{
  int age, year;
  printf("Insert Age : ");
  scanf("%d",&age);
  // cara 1 : if else , dan nested if, focus else
  if(age >= 18 && age<=70)
  { printf("You can apply driving licence\n");}
  else
  {	if (age<18 )
  		printf("You can appy after %d years\n",18-age);
  	else
		printf("you are not allowed to apply \n");
  }

  // cara 2: if else, dan nested if focus if
  if(age >= 18)
  { if( age<=70) prinf("allowed\n");
    else printf("not allowed\n");
	}
  else printf("You can appy after %d years\n",18-age);
  
  //cara 3 : else if
  if(age >= 18 && age<=70)
  { printf("You can apply driving licence\n");}
  else if (age<18 )
  	printf("You can appy after %d years\n",18-age);
  else
	printf("you are not allowed to apply \n");

  
  system("PAUSE");	
}
