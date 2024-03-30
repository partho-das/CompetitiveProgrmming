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

        int t1,t2,k1,k2,team[3000],n;

        cin >> t1 >> t2 >> k1 >> k2 >> n;



        for(int i = 0;i<(t1+t2);i++)
        {
        	if(i>=t1)
        	{
        		team[i] = k2;
        	}
        	else
        	{
        		team[i] = k1;
        	}

        }
        int memmber = t1+t2;
        sort(team,team+(t1+t2));
        int mn = n,mx = 0,sum = n;
        for(int i = memmber-1;i>=0;i--)
        {
        	sum-=(team[i]-1);
        }
        sum = max(sum,0);
         mn = sum;
        sum = n;

        for(int i = 0;i<memmber;i++)
        {
        	sum-=team[i];
    
        	if(sum>=0)
        		mx++;
        	else break;
        	
        }
       
        cout << mn << " "<< mx << endl; 


   
   		
    	
    	
	#ifdef PARTHO
		int end_time = clock();
		printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif

	return 0;
}
