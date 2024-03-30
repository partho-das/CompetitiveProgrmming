#include<bits/stdc++.h>
using namespace std;



const int maxn = 2e5+10;
char str[maxn];

int main()
{
	#ifdef PARTHO
		freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
    	freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
    	int start_time = clock();
    #endif

    	int t;
    	
    	cin >> t;
    	getchar();
    	while(t--)
    	{
    		gets(str);
    		
    		
    		int cnt = 0,len = strlen(str);
    		for(int i = 0;i<len;i++)
    			cout << str[i] << endl;
    		for(int i = len - 1;i>=0;i--)
    		{
    			int r = i,agent = 1,bin = 0 ;

    			for(int l = i;r-l<100 && l>=0;l--)
    			{
    				//cout << l << " " << i << endl; 
    				bin+=(str[l]-'0')*agent;
    				//cout <<bin << endl;

    				agent = agent<<1;
    				if(r-l+1 == bin)
    				{
    					cnt++;
    					cout << bin <<" " << l << " "<< r << endl;

    				}
    					
    				// else if(r-l+1>bin)
    					//break;

    				//cout <<bin << endl;

    			}
    		}

    		cout << cnt << endl;

    	}
   
   
    	
    	
	#ifdef PARTHO
		int end_time = clock();
		printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif

	return 0;
}
