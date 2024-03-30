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
   	while(t--)
   	{
   		int n,t,s;
   		cin  >> n >> s >> t;
   		n = n - s;
   		int ex = abs(n - t);
   		t -=ex;
   		s-=ex;
   		cout << max(s,t)+1 << endl;
   	}
   
    	
    	
	#ifdef PARTHO
		int end_time = clock();
		printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif

	return 0;
}
