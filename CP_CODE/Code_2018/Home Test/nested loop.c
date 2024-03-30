#include<stdio.h>

int main()
{
    int year;

    scanf("%d",&year);

    if((year%4) == 0)
    {
        if((year%100) != 0)
            printf("%d this is a leap year\n",year);
        else
        {
            if((year%400) == 0)
                printf("%d this is a leap year \n",year);
            else
                printf("%d this is not a leap year\n",year);
        }
    }
    else
        printf("%d this not a leap year\n",year);

    return 0;
}
