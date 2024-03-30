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

        
   int n,arr[200];
   cin >> n;

   for(int i= 0;i<n;i++)
   {
   	cin >> arr[i];
   }
   int left = n,cnt=0;
   sort(arr,arr+n);
   for(int i= 0;i<n;i++)
   {
   		int value = arr[i],ck = 0;
   		if(value != 1e9+7)
   		for(int j = i;j<n;j++)
   		{
	   		if(arr[j]%value==0)
	   		{
	   			arr[j] = 1e9+7;
	   			ck = 1;
	   		}

   		}

   		if(ck == 1)
   		{
   			
   			cnt++;
   		}
   		
   }

   cout << cnt << endl;
   


   
    	
    	
	#ifdef PARTHO
		int end_time = clock();
		printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif

	return 0;
}
