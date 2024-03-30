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

   
   int n,arr[55];
   int cnt = 01;
   while(1)
   {
   		scanf("%d",&n);
   		if(n==0)
   			break;
   		int sum = 0;
   		for(int i = 0;i<n;i++)
   		{
   			cin >> arr[i];
   			sum+=arr[i];
   		}
   		int div = sum/n;
   		sum = 0;
   		for(int i = 0;i<n;i++)
   		{
   			sum += max(0,arr[i]-div);
   		}

		printf("Set #%d\nThe minimum number of moves is %d.\n\n",cnt,sum);
	
   		cnt++;
   }
    	
    	
	#ifdef PARTHO
		int end_time = clock();
		printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif

	return 0;
}
