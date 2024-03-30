#include<stdio.h>

int main()
{
    int n,arr[100300],re[100300],i,j;

    scanf("%d",&n);

    for(i = 0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
        {
            if(arr[i]==arr[j])
            arr[j]=(i+1);
        }
          break;
    }

    for(i = 0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }


    return 0;
}
