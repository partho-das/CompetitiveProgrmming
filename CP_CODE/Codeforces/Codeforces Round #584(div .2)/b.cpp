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

    	int n;
    	string str;
    	std::vector<pair <int ,int>> time;
    	cin >> n >> str;

    	for(int i = 0;i<n;i++)
    	{
    		int x,y;
    		cin >> x >> y;
    		time.push_back({x,y});
    	}
    	int mx = 0;
    	for(int i = 0;i<10000;i++)
    	{
    		int cnt = 0;
    		for(int j = 0;j<n;j++)
    		{
    			if(time[j].second==i)
    			{
    				if(str[j]=='0')
    					str[j]='1';
    				else str[j] = '0';
    				time[j].second+=time[j].first;
    			}
    			if(str[j] == '1')
    				cnt++;
    		}
    		mx = max(mx,cnt);
    		if(mx==n)
    			break;
    		//cout << str << endl;
    	}


    	cout << mx << endl;

        
   
   
    	
    	
	#ifdef PARTHO
		int end_time = clock();
		printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif

	return 0;
}
