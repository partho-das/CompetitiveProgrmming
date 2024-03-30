#include<stdio.h>

int main()
{
    int arr[10][10];
    int i,j,x = 0,y = 0;

    for(i = 0;i<10;i++)
    {
        for( j = 0;j<10;j++)
    {
        arr[i][j] = x;
        ++x;
    }
    y+=10;
    x= y;
    }

    for(i = 0;i<10;i++) for( j = 0;j<10;j++)
        if(j==9)
        printf("%d\n",arr[i][j]);
    else
        printf("%d ",arr[i][j]);

    return 0;
}
