//printg an array in revers ourder using pointer
#include<stdio.h>


int main()
{
    
    int arr[100],n,*ptr;

    scanf("%d",&n);
    int i = 0;
    for(i = 0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }


    ptr = arr;
    for(i = n-1;i>=0;i--)
    {
        printf("%d ",ptr[i]);
    }

    



    return 0;
}