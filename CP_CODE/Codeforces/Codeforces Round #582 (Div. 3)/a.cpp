#include<bits/stdc++.h>
using namespace std;
 
 
 
 
 
int main()
{
	#ifdef PARTHO
		freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
    	freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
    	int start_time = clock();
    #endif
 
   
 
    	int n,arr[200];
 
    	cin >> n;
 
    	int ev = 0,odd = 0;
    	for(int i = 0;i<n;i++)
    	{
    		cin >> arr[i];
    		if(arr[i]&1)odd++;
    		else ev++;
    	}
 
    	
 
    	cout << min(ev,odd) << endl;
 
 
 
	#ifdef PARTHO
		int end_time = clock();
		printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif
 
	return 0;
}