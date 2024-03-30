#include<bits/stdc++.h>
using namespace std;

#include<tr1/unordered_map>

int main()
{
	#ifdef PARTHO
		freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
    	freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
    	int start_time = clock();
    #endif

    	int t;
    	scanf("%d",&t);
    	for(int c = 1;c<=t;c++)
    	{
    		
    		int arr[100];

    		tr1::unordered_map<int,int> cnt;

    		
    		int n, value;
    		scanf("%d",&n);
    		for(int i = 0;i<n;i++)
    		{
    			scanf("%d",&value);
    			cnt[value]++;		
    		}
    		

    		int sum = 0;
    		for(auto it : cnt)
    		{
    			//cout << it.second << " " << ;
    			sum+=((it.second+it.first)/(it.first+1))*(it.first+1);
    		}

    		printf("Case %d: %d\n",c,sum);
    	}

	#ifdef PARTHO
		int end_time = clock();
		printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif
   
 

	return 0;
}
