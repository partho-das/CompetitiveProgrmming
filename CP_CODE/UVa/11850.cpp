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

    	int test;
    	cin >> test;
    	for(int c = 1;c<=test;c++)
    		{
    			int n,k,p;
    			scanf("%d%d%d",&n,&k,&p);
    			k+=p;
    			k %=n;
    			if(!k)
    				k = n;
    			printf("Case %d: %d\n",c,k);
    		}

   
   
    	
    	
	#ifdef PARTHO
		int end_time = clock();
		printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif

	return 0;
}
