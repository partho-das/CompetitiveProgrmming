#include<bits/stdc++.h>



using namespace std;

const int maxn = 2e4;

int main()
{
	#ifdef PARTHO
		freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
    	freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
    	int start_time = clock();
    #endif

    	int q ,n,ck = 0,stor = 0;

    	cin >> q ;


    	while(q--)
    	{
    		cin >> n;
    			//cout << n << endl;
    			stor = 0;
    		for(int i = 0;i<n;i++)
    		{

    			int value;
    				cin >> value;
    				//cout << value <<" stor  = " << stor <<" " << i<< endl;
    				if(i==0)
    					stor = value;
    				else
    				{
    					if(abs(value-stor) == 1 || ((stor == 1 )&& (value==n)) || ((stor == n )&& (value==1)) )
    					{
    						stor = value;
    						continue;
    					}
    					else
    					{
    						if(ck==0)
    						{
    							ck = 1;
    							printf("NO\n");
    						}

    					
    					}
    				}

    		}
    		
    		if(ck==0)
    		printf("YES\n");
    		ck = 0;
    	}


	return 0;
}