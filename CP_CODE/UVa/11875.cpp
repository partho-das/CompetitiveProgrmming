#include<bits/stdc++.h>
using namespace std;

#define ll long long




int main()
{
    #ifdef PARTHO
        freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
        freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
        int start_time = clock();
    #endif

        
    int t,n,arr[12];
    cin >> t;
    for(int c = 1;c<=t;c++)
    {
        scanf("%d",&n);
        for(int i = 0;i<n;i++)
            scanf("%d",&arr[i]);
        n = n/2;

        printf("Case %d: %d\n",c,arr[n]);
    }
   
        
        
    #ifdef PARTHO
        int end_time = clock();
        printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif

    return 0;
}
