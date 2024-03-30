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
        
        int t;

        cin >> t;
        for(int c = 1; c <= t ;c++)
        {
            long long arr[4],n = 3;
            for(int i = 0;i<n;i++)
                cin >> arr[i];
            sort(arr,arr+n);
            
            if(arr[2]>= (arr[0]+arr[1])) printf("Case %d: Invalid\n",c);
            else if(arr[0]==arr[1] && arr[0] == arr[2])
            printf("Case %d: Equilateral\n",c);
            else if(arr[0]==arr[1] || arr[0] == arr[2] || arr[1] == arr[2])
                printf("Case %d: Isosceles\n",c);
            else printf("Case %d: Scalene\n",c);

        }
     
       
    
    // #ifdef PARTHO
    //     int end_time = clock();
    //     printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    // #endif

    return 0;
}
