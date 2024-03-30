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

    	int test;

    	scanf("%d",&test);

    	for(int c = 1;c<=test;c++)
    	{
    		int mx = 0,value;
    		string str;
    		std::vector<string> webbox;
    		for(int i = 0;i<10;i++)
    		{
    			cin >> str >> value;
    			if(value>mx)
    			{
    				mx = value;
    				webbox.clear();
    				webbox.push_back(str);
    			}
    			else if (value==mx)
    			webbox.push_back(str);

    		}


    		printf("Case #%d:\n",c);
    		for(auto it : webbox)
    			cout << it << endl;
    	}
   
   
    	
    	
	#ifdef PARTHO
		int end_time = clock();
		printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif

	return 0;
}
