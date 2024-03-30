#include<stdio.h>

int main()
{
    int i;

    i = 1;

    hi:
        printf("%n",i,i);
        i++;
        if(i <= 5)
            goto hi;


    return 0;
}
