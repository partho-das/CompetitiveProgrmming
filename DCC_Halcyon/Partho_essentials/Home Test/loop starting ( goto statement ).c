#include<stdio.h>
int main()
{
    int a;
    a = 1;

    start:
        printf("%d ", a--);

        if (a <= 7)
            goto start;

    return 0;
}
