#include<stdio.h>

int main()
{
    float salary, selles,ts;

    char name[1000];
    scanf("%s",name);
    scanf("%f%f",&salary,&selles);

     ts = salary+(selles*.15);

     printf("TOTAL = R$ %.2f\n",ts);


    return 0;
}
