#include<bits/stdc++.h>
 
using namespace std;
 
 
 
long long hc[200];
int main()
{
	#ifdef PARTHO
		freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
    	freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
    	int start_time = clock();
    #endif
    	
 
    	long long n,m,k,ck = 0;
 
    	int t;
 
    	cin >> t;
    	while(t--)
    	{
    		ck = 0;
    		cin >> n >> m >> k;

 
 
    		for(int i = 1;i<=n;i++)
    		{
    			
    			cin >> hc[i];
    			//cout << hc[i] << " ";
    		}
 
 
    		for(int i = 1;i<n;i++)
    		{
    			ck = 0;
    			int dis = abs(hc[i] - hc[i+1] );
    			if(hc[i] >= hc[i+1])
    				{
    					hc[i] -= dis;
    					m+=dis;
    					dis = 0;
 							int value = 0;

 							value = hc[i] - k;

 							if(value == 0)
 							{
	 							hc[i] -= k;
	    						m+=k;
	    						dis = k;
	    						cout <<"i = "<<i << " "<<  m << endl;
 							}
 							if(value < 0)
 							{
	 							
	    						m+=hc[i];
	    						dis = hc[i];
	    						hc[i] = 0;
	    						cout <<"i = "<<i << " "<<  m << endl;
 							}
 							if(value > 0)
 							{
	 							hc[i] -= k;
	    						m+=k;
	    						dis = k;
	    						cout <<"i = "<<i << " "<<  m << endl;
 							}

 							//cout <<i << " " << value << endl;
    					
 
    						continue; // dis == k
 
    					
    					
 
    				}
    				else
    				{
    					int rdis = hc[i+1] - (hc[i]+k);
 
    					//cout << hc[i+1 << " " << rdis << endl;;
 
    					if(m>=rdis)
    					{
    						m-=rdis;
    					}
    					else
    					{
    						ck = 1;

    						// cout << i << endl;

    						// // for(int j = 1;j<=n;j++)
    						// // 	cout << hc[j] << " ";
    						// cout << m << endl;
    						break;
    					}
    				}
 
    		}
 
    		if(ck==0)
    		{
    			cout << "YES" << endl;
    		}
    		else
    			cout << "NO" <<endl;
    		
 
 
    		
    	}
 
 
 
 
  
 
    return 0;
 
}