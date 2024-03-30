#include<bits/stdc++.h>
using namespace std;





int main()
{
	#ifdef PARTHO
		freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
    	freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
    	int start_time = clock();
    #endif

    	int t;

    	cin >> t;

    	while(t--)
    	{
    		int str,inte,exp;

    		cin >> str>> inte >> exp;
    		int def;
    		int res = 0;
    		if(str>inte)
    		{
    			//cout <<"HI" << endl;
    			def = str - inte;
    			//cout << def<< endl;
    			if(def>exp)
    				res = exp+1;
    			else{
    				inte+=def;
    				exp-=def;
    				exp = (exp+1)/2;
    				res = def+exp;
    			}
    		}
    		else
    		{
    			def = inte - str;
    			if(def>=exp)
    				res = 0;
    			else
    			{
    				str+=def;
    				exp-=def;
    				res=(exp+1)/2;
    			}

    		}

    		cout << res << endl;
    	}
   
   
    	
    	
	#ifdef PARTHO
		int end_time = clock();
		printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif

	return 0;
}
