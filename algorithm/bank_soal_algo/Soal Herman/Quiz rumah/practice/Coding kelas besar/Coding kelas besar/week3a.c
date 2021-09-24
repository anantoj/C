#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  float val1, val2; char op; int val;
 // printf("\n Type val1 operator val2 \n");
//  scanf("%f %c %f", &val1, &op, &val2);
//  switch(op)
//  {
//        case('+'): printf(" = %f\n", val1 + val2); break;
//      	case('-') : printf(" = %f\n", val1 - val2); break;
//      	case('*') : printf(" = %f\n", val1 * val2); break;
//      	case('/') : printf(" = %f\n", val1 / val2); break;
//      	default :   printf(" unknown operator!\n");
//   	}
//
//   if(op=='+') printf(" = %f\n", val1 + val2);
//   else if(op=='-') printf(" = %f\n", val1 - val2);
//   else if(op=='*') printf(" = %f\n", val1 * val2);
//   else if(op=='/') printf(" = %f\n", val1 / val2);
//   else printf("unknown operator");
   
   //*******different used of case
   
   do{
		printf("1. for drink \n2. for food\n0. exit\n");
        printf("Insert Your choice : ");
		scanf("%d",&val);
		
		switch (val)
		{
		    case 1 : printf("\n all about drink\n"); break;
		    case 2 : printf("\n all about food\n"); break;
		    case 0 : break;
			default : printf("wrong choices\n");break;
		}
		printf("\n");
	}while (val!=0);
  system("PAUSE");
  return 0;
}
