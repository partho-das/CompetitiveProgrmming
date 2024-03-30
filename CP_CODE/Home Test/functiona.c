#include<stdio.h>

int main()
{
    int num1,num2,multiplication;

    printf("Enters two numbers: ");
    scanf("%d %d",&num1,&num2);

    multiplication = multiplyNumbers(num1, num2);

    printf("multiplication = %d",multiplication);

    return 0;
}

int multiplyNumbers(int a,int b)
{
    int result;
    result = a*b;
   // return result;
}
