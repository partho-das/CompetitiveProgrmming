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

        while(t--)
        {
            int n,arr[22];

            cin >> n;
            int mn = 1e9,mx = -100;
            for(int i  = 0;i<n;i++)
            {
                scanf("%d",&arr[i]);
                mx = max(mx,arr[i]);
                mn = min(mn,arr[i]);
            }

            cout << (mx-mn)*2 << endl;

        }
    	
   
   
    	
    	
	#ifdef PARTHO
		int end_time = clock();
		printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif

	return 0;
}
