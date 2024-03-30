#include <bits/stdc++.h>
using namespace std;



int pos[100500];
int main()
{

	
		#ifdef PARTHO
		freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
    	freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
    	int start_time = clock();
    	#endif
    	int n,arr[100500],t, ck = 0,mx = -1,srt[100500];


    	
    		cin >> n;
    		for(int i = 0;i<n;i++)
    		{
    			cin >> arr[i];
    			srt[i] = arr[i];
    			mx = max(mx,arr[i]);
    			pos[arr[i]]  = i;
    			//cout << pos[arr[i]] << endl;
    		}

    		sort(srt,srt+n);

    		int mxp = pos[mx];
    		int pos2 = mxp-1,pos1 = mxp+1;
    		//cout << pos2 << " " << pos1 << endl;

    		
    		for(int i = n-1;i>=0;i--)
    		{
    			if(srt[i]==mx )
    				continue;
    			
    				
    				if(pos[srt[i]] > mxp)
    				{
    					//cout << srt[i]<<" " <<pos[srt[i]] << endl;
    					if(pos[srt[i]]==pos1 && i<n)
    					{
    						pos1++;
    					}
    					else
	    					{
	    						cout <<"NO " << endl;
	    						return 0;
	    					}
    				}
    				else
    				{
	    				if(pos[srt[i]] < mxp)
	    				{
	    					
	    					if(pos[srt[i]]==pos2 && i>=0)
	    					{
	    						//cout <<"hi" << endl;
	    						pos2--;
	    					}
	    					else
	    					{
	    						cout <<"NO" << endl;
	    						return 0;
	    					}
	    				}

    				}
    			

    		}
    		cout << "YES" << endl;




    	


    
    	


    	

   
 
		#ifdef PARTHO
		int end_time = clock();
		printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    	#endif
 
	
 
	return 0;
}