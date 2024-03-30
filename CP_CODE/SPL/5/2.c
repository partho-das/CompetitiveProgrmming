//2.Largest element in array.
#include<stdio.h>


int main()
{
    int arr[100],n,mx = 0;

    scanf("%d",&n);
    int i = 0;
    for(i = 0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    mx = arr[0];
    for(i = 0;i<n;i++)
    {
        if(arr[i]>mx)
            mx = arr[i];
    }

    printf("The Largest Element: %d\n",mx);



    return 0;
}