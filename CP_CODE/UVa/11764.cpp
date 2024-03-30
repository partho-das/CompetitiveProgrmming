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

   	int t,value,n,pri,hi,low;

   	scanf("%d",&t);
   	for(int c = 1;c<=t;c++)
   	{
   		hi = 0,low = 0;
   		scanf("%d",&n);
   		for(int i = 0;i<n;i++)
   		{
   			scanf("%d",&value);
   			if(i==0)
   				pri = value;
   			else
   			{
   				if(value>pri)
   				hi++;
   				else if(value<pri)
   					low++;
   				pri = value;
   			}
   		}

   		printf("Case %d: %d %d\n",c,hi,low);
   	}
   
    	
    	
	#ifdef PARTHO
		int end_time = clock();
		printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif

	return 0;
}
