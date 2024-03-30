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

    	string str;
    	int n = 0;

    	cin >> n;

    	int cnt = 1e8+7;
    	int mx = 0;
    	

    	while(n&&cnt)
    	{
    		int work = n,muli = 1;
    		while(work)
    		{
    			muli*=work%10;
    			work/=10;
    		}
    		
    	}

    	cout << mx << endl;
   		
   
    	
    	
	#ifdef PARTHO
		int end_time = clock();
		printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif

	return 0;
}
