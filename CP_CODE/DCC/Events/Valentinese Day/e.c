#include<stdio.h>
int arr[100200];
int main ()
{
   int i,j,n,ck = 0;

   scanf("%d",&n);

   for(i = 0;i<n;i++)
    scanf("%d",&arr[i]);

    for(i = 0;i<n;i++)
    {
        ck = 0;
        for(j = i+1;j<n;j++)
            if(arr[i] == arr[j])
            {
                arr[j] = 0;
                ck = 1;
            }
        if(ck == 1 )
            arr[i] = 0;

    }

    for(i = 0;i<n;i++ )
        if(arr[i] !=0)
        printf("%d\n",arr[i]);

return 0;
}
