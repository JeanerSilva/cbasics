#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
typedef void (*pfnMessage)(const char*,float fResult); //function pointer to point display message
typedef float (*pfnCalculator)(float,float); //function pointer to point arithmetic function

typedef struct S_sArithMaticOperation  //structure of fuction pointer
{
 float iResult;
 pfnMessage DisplayMessage;
 pfnCalculator ArithmaticOperation; 
} sArithMaticOperation;
 
float Addition(float a, float b) { return (a + b); }
float Subtraction(float a, float b) { return (a - b); }
float Multiplication(float a, float b) { return (a*b); }
float Division(float a, float b) { return (a/b); }
  
void Message(const char *pcMessage, float fResult)
{
 printf("\n\n  %s = %f\1n\n\n\n",pcMessage,fResult);
}
 
void PerformCalculation(float x, float y, sArithMaticOperation *funptr,const char *pcMessage )
{
    float result = funptr->ArithmaticOperation(x,y);  //Call function as per the user choice
    funptr->DisplayMessage(pcMessage,result); //Display the Messgae
}
 
int main(void)
{
 char szMessage[32] = {0};
 int iChoice = 0;
 float fData1 = 0.0f;
 float fData2 = 0.0f;
 sArithMaticOperation *psArithmaticOperation = NULL;
 psArithmaticOperation = malloc(sizeof(sArithMaticOperation));
 
 if (psArithmaticOperation == NULL) { return -1; }
 
 psArithmaticOperation->DisplayMessage = &Message;
 
 while(1)
 {
 printf("\n\n  1.Add \n\
  2.Sub \n\
  3.Mul \n\
  4.Div \n\n\n");
 printf("  Enter the operation Choice = ");
 scanf("%d",&iChoice);
 
 switch(iChoice)
 {
    case 1 : printf("\n  Enter the numbers : ");
        scanf("%f",&fData1);
        printf("\n  Enter the numbers : ");
        scanf("%f",&fData2);
        psArithmaticOperation->ArithmaticOperation = &Addition;
        strcpy(szMessage,"Addition of two Number = ");
    break;
    
    case 2 : 
        printf("\n  Enter the numbers :");
        scanf("%f",&fData1);
        printf("\n  Enter the numbers :");
        scanf("%f",&fData2);
        psArithmaticOperation->ArithmaticOperation = &Subtraction;
        strcpy(szMessage,"Subtraction of two Number = ");
    break;
    
    case 3 : 
        printf("\n  Enter the numbers :");
        scanf("%f",&fData1);
        printf("\n  Enter the numbers :");
        scanf("%f",&fData2);
        psArithmaticOperation->ArithmaticOperation = &Multiplication;
        strcpy(szMessage,"Multiplication of two Number = ");
    break;
    
    case 4 : 
        printf("\n  Enter the numbers :");
        scanf("%f",&fData1);
        printf("\n  Enter the numbers :");
        scanf("%f",&fData2);
        psArithmaticOperation->ArithmaticOperation = &Division;
        strcpy(szMessage,"Division of two Number = ");
    break;
    
    default :
    printf(" \n Invalid Choice :\n\n");
    exit(0);
 }
 
 PerformCalculation(fData1,fData2,psArithmaticOperation,szMessage);
 
 }
 
 free(psArithmaticOperation);
 
 return 0;
}