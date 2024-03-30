#include<stdio.h>

int main()

{
    int day,month,year;
    scanf("%d",&day);
    year = day/365;

    day = day%365;

    month = day/30;

    day = day%30;

    printf("%d ano(s)\n%d mes(es)\n%d dia(s)\n",year,month,day);

    return 0;
}

