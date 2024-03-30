#include<bits/stdc++.h>
using namespace std;

#define ll long long




int arr[300000];
bool negtive[200020];

int main()
{
	#ifdef PARTHO
		freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
    	freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
    	int start_time = clock();
    #endif
    	
    	// for(int i = 0;i<n;i++)
    	// {	
    	// 	if(i&1)
    	// 	arr[i] = -1;
    	// 	else arr[i] = 1; 
    	// 	//cout << arr[i] << " ";
    	// }
    	// for(int i = 0;i<n;i++)
    	// {
    	// 	mul = 1;
    	// 	for(int j = i;j<n;j++)
    	// 	{

    	// 		mul*=arr[j];

    	// 		if(mul<0)
    	// 			neg++;
    	// 		else pos++;
    	// 		//cout << mul << " ";
    	// 	}

    	// 	///cout << endl;
    	// }
     //    cout << neg << " "<< pos <<  endl;
   
   
    	int n;
    	cin >> n;
    	

    	long long mul = 1,neg = 0,pos = 0;
  
    	for(int i  = 0;i<n;i++)
    	{
    		cin >> arr[i];
    		if(arr[i]<0)
    		{
    			neg++;
    			negtive[i] = 1;
    		}

    	}

    	long long contain = (n*(n+1))/2;
    	cout << neg << contain << endl;
    	int sum = 0,left = neg;

    
    	cout << (contain/2) << " " << contain - sum << endl;
    	
	#ifdef PARTHO
		int end_time = clock();
		printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif

	return 0;
}
