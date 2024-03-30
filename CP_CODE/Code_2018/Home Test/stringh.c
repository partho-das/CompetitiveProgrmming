#include<stdio.h>

int main()

{
    int px;
     scanf("%d",&px);
    char tx[px][30];
    int i,j,sum = 0,k;




    for(i = 0; i < px; i ++)

    {
        gets(tx[i]);
    }

    for(i = 0; i < px;i++)
    {
        sum = 0;
        for( j = 0;tx[i][j];j++ )
    {
        sum = sum + 1;
    }
         for(k = (sum-1) ;k >=0;k-- )
         {
            printf("%c",tx[i][k]);
    }
     printf("\n");
    }

    return 0;
}
