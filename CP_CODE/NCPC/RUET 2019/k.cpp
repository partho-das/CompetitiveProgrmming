
#include<bits/stdc++.h>
using namespace std;





int main()
{
	#ifdef PARTHO
		freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
    	freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
    	int start_time = clock();
    #endif

   		int t;
   		cin >> t;
   		for(int k = 1;k<=t;k++)
   		{
   			printf("Case %d: ",k );
   				int n;
   				cin >> n;

   			int mx = n-1,mn = log2(n);


   			cout << mx << " " << mn << endl;


   		}
    	
    	
	#ifdef PARTHO
		int end_time = clock();
		printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif

	return 0;
}
