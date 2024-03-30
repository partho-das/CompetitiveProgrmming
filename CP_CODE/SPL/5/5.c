//5.Sum of an array.
#include<stdio.h>


int main()
{
    
    int arr[100],n,sum = 0;

    scanf("%d",&n);
    int i = 0;
    for(i = 0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        sum+=arr[i];
    }
    printf("Sum : %d\n",sum);


   



    return 0;
}