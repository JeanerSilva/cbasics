//https://stackoverflow.com/questions/559581/casting-a-function-pointer-to-another-type

#include <stdio.h>
#include <stdlib.h>

int AddTwoNumber(int iData1, int iData2)
{
    return (iData1 + iData2);
}

int main(int argc, char *argv[])
{
    int iRetValue = 0;
    int (*pfAddTwoNumber)(int, int) = NULL; //Declaration of function pointer

    pfAddTwoNumber = AddTwoNumber;     //initialise the function pointer
    iRetValue = (*pfAddTwoNumber)(10, 20); //Calling the function using function pointer

    printf("\n\nAddition of two number = %d\n\n", iRetValue);

    return 0;
}