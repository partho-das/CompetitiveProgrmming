#include<stdio.h>

int main()
{
    double salary,extra;

    scanf("%lf",&salary);

    if( salary >=0 && salary <= 400 )
    {
        extra = salary*.15;
        printf("Novo salario: %.2lf\n",(salary+extra));


        printf("Reajuste ganho: %.2lf\n",extra);
        printf("Em percentual: 15 %%\n");

    }
    else if(salary >= 400.01 && salary <= 800.00 )
    {
        extra = salary*.12;
         printf("Novo salario: %.2lf\n",(salary+extra));

        printf("Reajuste ganho: %.2lf\n",extra);
        printf("Em percentual: 12 %%\n");
    }
    else if(salary >= 800.01 && salary <= 1200.0)
    {
        extra = salary*.10;
        printf("Novo salario: %.2lf\n",(salary+extra));

        printf("Reajuste ganho: %.2lf\n",extra);
        printf("Em percentual: 10 %%\n");
    }
    else if(salary >= 1200.01 && salary <= 2000.0)
    {
        extra = salary*.07;
        printf("Novo salario: %.2lf\n",(salary+extra));

        printf("Reajuste ganho: %.2lf\n",extra);
        printf("Em percentual: 7 %%\n");
    }
    else if(salary>2000)
    {
        extra = salary*.04;
        printf("Novo salario: %.2lf\n",(salary+extra));

        printf("Reajuste ganho: %.2lf\n",extra);
        printf("Em percentual: 4 %%\n");
    }

    return 0;
}
