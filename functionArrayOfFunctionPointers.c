//https://aticleworld.com/use-of-function-pointer-in-c/


#include <stdio.h>
#include <stdlib.h>
 
int AddTwoNumber(int iData1 ,int iData2)
{
  return (iData1 + iData2);
}

int SubTwoNumber(int iData1 ,int iData2)
{
  return (iData1 - iData2);
}

int MulTwoNumber(int iData1 ,int iData2)
{
  return (iData1 * iData2);
}
 

int main(int argc, char *argv[]) {
 
 int iAddValue = 0, iSubValue = 0, iMulValue = 0;

 int (*apfArithmatics [3])(int,int) = {AddTwoNumber,SubTwoNumber,MulTwoNumber}; //Declaration of array of function pointer

 iAddValue = (*apfArithmatics [0])(20,10);  //Calling the Add function using index of array
 iMulValue = (*apfArithmatics [2])(20,10);  //Calling the multiply function using index of array
 iSubValue = (*apfArithmatics [1])(20,10);  //Calling the subtract function using index of array
 
 printf("\n\nAddition of two number = %d\n\n",iAddValue);
 printf("\n\nsubtraction of two number = %d\n\n",iSubValue);
 printf("\n\nmultiplication of two number = %d\n\n",iMulValue);
 
 return 0;
}