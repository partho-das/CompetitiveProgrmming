#include<stdio.h>

int main()
{
    int pro, quantity;
    double price;

    scanf("%d%d",&pro,&quantity);

    switch (pro)
    {
    case 1:
        price = quantity*4.00;
        break;
    case 2:
        price = quantity*4.50;
        break;
    case 3:
        price = quantity*5.00;
        break;
    case 4:
        price = quantity*2.00;
        break;
    case 5:
        price = quantity*1.50;
    }

    printf("Total: R$ %.2lf\n",price);


    return 0;
}
