#include<bits/stdc++.h>
using namespace std;


int arr[120000];
int main()
{
//    freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
//    freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
//
    int n,k,tst;
    scanf("%d",&tst);
    while(tst--)
    {
        int cnt  = 0;


        scanf("%d%d",&n,&k);
        for(int i = 0;i<n;i++)
            scanf("%d",&arr[i]);
        int value = arr[k-1];

        for(int i = 0;i<n;i++)
        {
            if(value >arr[i])
            {
                cnt++;
            }
        }
        printf("%d\n",cnt+1);
    }


    return 0;
}
