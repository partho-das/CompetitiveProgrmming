#include<bits/stdc++.h>

using namespace std;

int main()
{
    int i,arr[10100],n,sum = 0,j,value,sumc,cpy,ck = 0;

    scanf("%d",&n);
    for(i = 0;i<n;i++)
    {
    scanf("%d",&arr[i]);
    sum+=arr[i];
    }
    value = sum;
    sumc = sum;
   sort(arr,arr+n);
//   for(i = 0;i<n;i++)
//   printf("%d ",arr[i]);
   for(i = n-1;i>=0;i--)
   {
       // printf("%d ",arr[i]);
       cpy = sqrt(arr[i]);
       ck = 0;
       for( j = 2;j<=cpy;j++)
       {

        sum = sumc;
        if(arr[i]%j == 0)
        {

        sum = sum -arr[i];
        sum = sum +(arr[i]/j);
        sum = sum - (arr[0]);
        sum = sum +(arr[0]*j);
        ck = 1;
       }
       if(value>sum)
        value = sum;


       }
       if(ck == 1)
        break;  printf("%d",arr[i]);
   }

    printf("%d\n",value);
    return 0;
}
