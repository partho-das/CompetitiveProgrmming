#include<stdio.h>

int main()
{
    int age = 1,i,cnt = 0,ages = 0  ;
    double ava;


    while(age>-1)
    {
        scanf("%d",&age);
        if(age>-1)
        {
        cnt++;
        ages+=age;
        }
    }
    ava = (float)ages/cnt;
    printf("%.2lf\n",ava);

    return 0;
}
