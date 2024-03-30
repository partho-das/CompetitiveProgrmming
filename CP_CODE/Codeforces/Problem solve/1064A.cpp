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

        int n = 3,arr[4];

        for(int i = 0;i<n ;++i)
            cin >> arr[i];
        sort(arr,arr+n);
     
        int mx = max( (arr[2]+1 - (arr[0]+arr[1])),0);

        cout << mx << endl;
    
    #ifdef PARTHO
        int end_time = clock();
        printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif

    return 0;
}
