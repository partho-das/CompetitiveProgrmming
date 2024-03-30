#include<stdio.h>

int main()

{
    double money;

    int test[12];

    scanf("%lf",&money);

    test[0] = money/100;
    money = money%100.0;

    test[1] = money / 50;
    money = money % 50.0;

    test[2] = money / 20;
    money = money % 20;

    test [3] = test / 10;
    money = money % 10;

    test[4] = money / 5;
    money = mone % 5;

    test[5] = money / 2;
    money = money % 2;

    test[6] = money/1;
    money = money%1;

    test[7] = money / .50;
    money = money % .50;

    test[8] = money / .25;
    money = money % .25;

    test[9] = money / .10;
    money = money % .10;

    test[10] = money / .05;
    money = money % .05;

    test[11] = money / .01;


    return 0;
}
