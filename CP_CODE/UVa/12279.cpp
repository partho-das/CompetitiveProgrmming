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


    	int n,Case = 1;

    	while(1)
    	{
    		scanf("%d",&n);


    		if(n==0)
    			break;
    		int cnt = 0,zeros = 0,value;
    		while(n--)
    		{
    			scanf("%d",&value);
    			if(value==0)
    				zeros++;
    			else cnt++;
    		}

    		cnt = cnt - zeros;
    		printf("Case %d: %d\n",Case++,cnt);
    	}

   
   
    	
    	
	#ifdef PARTHO
		int end_time = clock();
		printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif

	return 0;
}
