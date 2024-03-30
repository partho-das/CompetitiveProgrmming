#include<stdio.h>

int main()
{
    char ar,us;
    int row,col,i,sum = 0;

    scanf("%d%d",&row,&col);

    for(i = 0;i<(row*col);i++)
    {

                scanf("%*",us);
            scanf("%c",&ar);

            if(ar=='C'||ar=='M'||ar=='Y')
                sum++;

    }
    if(sum==0)
        printf("#Black&White\n");


    else
       printf("#Color\n");

    return 0;
}
