
#include<bits/stdc++.h>
using namespace std;



int arr[150003];


int main()
{
	#ifdef PARTHO
		freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
    	freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
    	int start_time = clock();
    #endif

   
   	int t,mi,cnt = 0;

   	cin >> t;

   	while(t--)
   	{
   		cnt = 0;
   		int n;

   		cin >> n;

   		for(int i = 0;i<n;i++)
   		cin >> arr[i];
   		mi = arr[n-1];


   		for(int i = n-1;i>=0;i--)
   			{
   				if(arr[i]<=mi)
   				{
   					mi = arr[i];
   				}
   				if(arr[i]>mi)
   					cnt++;

   			}
   			cout << cnt << endl;

   	}
    	

	#ifdef PARTHO
		int end_time = clock();
		printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif

	return 0;
}
