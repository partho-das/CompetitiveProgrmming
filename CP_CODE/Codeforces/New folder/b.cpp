#include<bits/stdc++.h>
using namespace std;


int arr[20000];
int main()
{
	#ifdef PARTHO
		freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
    	freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
    	int start_time = clock();
    #endif


    	int n,l,r;
    	cin >> n >> l >> r;
    	l--;
    	l = 1<<l;

    	//cout << l << endl;
    	int sum = 0;
    	for(int i = 0;i<n;i++)
    		{
    			arr[i] = l;
    			l = l/2;
    			if(!l)
    				l = 1;
    			sum +=arr[i];
    		}
    		cout << sum << " ";

    	r--;
    	int num = 1 << r; 
    	//cout << num << endl;

    	sum = 0;
    	
    		 r = 1;
    	for(int i = 0;i<n;i++)
    		{
    			arr[i] = r;
    			if(r >= num)
    				r = num;
    			else
    				r = r*2;
    			sum +=arr[i];
    		}
    		cout << sum << endl;


	#ifdef PARTHO
		int end_time = clock();
		printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif

	return 0;
}
