#include<bits/stdc++.h>
 
using namespace std;
 
 
 

int main()
{
	#ifdef PARTHO
		freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
    	freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
    	int start_time = clock();
    #endif
    	
 
    	long long n,ne = 0,z = 0;

        cin >> n;
        int arr[100300];
        long long cost = 0; 

        for(int i = 0;i<n;i++)
        {
            cin >> arr[i];
            if(arr[i]<0)
                ne++;


            if(arr[i] < 0 )
                {
                    cost += -(arr[i]) + 1;
                }
                else if(arr[i] == 0 )
                {
                    z = 1;
                    cost++;
                }
                else
                    cost += arr[i]-1;
        }

        int x = ne>>1;

        cost -= 4*x;
        ne -= x*2;

        if(ne && z)
            cost-=2;

        cout << cost << endl;

         


       
  
 
    return 0;
 
}