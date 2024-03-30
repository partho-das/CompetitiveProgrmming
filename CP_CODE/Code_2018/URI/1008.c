#include<stdio.h>

int main()
{
    int number, hour;

    float Phour, salary;

    scanf("%d%d%f",&number,&hour,&Phour);

    salary = hour*Phour;
    printf("NUMBER = %d\n",number);
    printf("SALARY = U$ %.2f\n",salary);


    return 0;
}
