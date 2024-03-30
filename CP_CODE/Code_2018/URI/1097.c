#include<stdio.h>

int main()
{
    int i,j= 7;


    for(i = 1 ; i<10;i+= 2)
    {

        for(j = j;j>=(i+4);j--)

        {
            printf("I=%d J=%d\n",i,j);
        }
        j = i+4+4;
    }

    return 0;
}
