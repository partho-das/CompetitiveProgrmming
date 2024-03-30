#include<stdio.h>

int main()
{
    char ar[10]="hello";


    int i = 0;

    for(i = 0;i<5;i++)
    {
        printf("%c%%[^ ]",ar[i]);
    }


    return 0;
}
