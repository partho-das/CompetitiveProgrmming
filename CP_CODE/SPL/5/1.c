//1.Sum and average of an array
#include<stdio.h>


int main()
{
    
    int arr[1000],n,sum = 0;
    float ave = 1;

    scanf("%d",&n);
    int i = 0;
    for(i = 0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        sum+=arr[i];
    }


    printf("Here is all the elements of this array : \n");
    for(i = 0;i<n;i++)
    {
       printf("%d ",arr[i]);
    }
    printf("\n");

    printf("The Sum : %d\n",sum);
    ave = (float)sum/n;
    printf("The Average : %d\n",ave);




    return 0;
}