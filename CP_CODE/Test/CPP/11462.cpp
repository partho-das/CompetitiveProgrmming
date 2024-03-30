#include<bits/stdc++.h>

using namespace std;
 int n,arr[2000300];
int main()
{

    

 
    while(1)
    {
        scanf("%d",&n);

        if(n==0)
            break;
        for(int i = 0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }
        sort(arr,arr+n);
        for(int i = 0;i<n;i++)
        {
            if(i==n-1)
            printf("%d",arr[i]);
        else
            printf("%d ",arr[i]);
        }
        puts("");


    }
    return 0;
}