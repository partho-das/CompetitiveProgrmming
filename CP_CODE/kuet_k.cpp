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

    	for(int c = 1;c<=t;c++)
    	{
    		int s,b;

    		cin >> s;
    		cin >> b;

    		int alls = 0;
    		for(int i = 0;i<7;i++)
    		{
    			int value;
    			cin >> value;
    			alls+=value;
    			
    		}

    		s-=alls;
    		printf("Case %d: %d\n",c,s);
    	}

   
   
    	
    	
	#ifdef PARTHO
		int end_time = clock();
		printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif

	return 0;
}
