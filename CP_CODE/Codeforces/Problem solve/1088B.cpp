#include<bits/stdc++.h>
using namespace std;





int main()
{
	#ifdef PARTHO
		freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
    	freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
    	int start_time = clock();
    #endif

   	int n,k,arr[100020];

   	cin >> n >> k;

   	for(int i = 0;i<n;i++)
   	{
   		cin >> arr[i];
   	}
   	sort(arr,arr+n);
   	int sum = 0,i = 0;
   	while(k--)
   	{	

   		if(i>=n)
   		{
   			printf("0\n");
   			continue;
   		}
   		arr[i]-=sum;
   		if(arr[i]<=0)
   		{
   			k++;
   			i++;
   			continue;
   		}
   		sum+=arr[i];
   		printf("%d\n",max(arr[i],0),i);
   		i++;

   	}
   
    	
    	
	#ifdef PARTHO
		int end_time = clock();
		printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif

	return 0;
}
