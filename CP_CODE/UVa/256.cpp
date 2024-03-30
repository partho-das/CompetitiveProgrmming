
#include<bits/stdc++.h>
using namespace std;





int main()
{
	#ifdef PARTHO
		freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
    	freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
    	int start_time = clock();
    #endif


   		std::vector<string> v2{"00","01","81"},v4{"0000","0001","2025","3025","9801"},
   		v6{"000000","000001","088209","494209","998001"},
   		v8{"00000000","00000001","04941729","07441984","24502500","25502500","52881984","60481729","99980001"},cmd;
    	
    	int n,p,lp ;

    	int f = 0,s = 0;
    	// while(scanf("%d",&n) !=EOF) // Main mathord
    	// {
    	// 	//cmd.push_back(n);
    		
    	// 	// if(n==2)
    	// 	// {
    	// 	// 	lp = 100;
    	// 	// 	if(!v2.empty())
    	// 	// 		continue;

    	// 	// }	
    		
    	// 	// else if(n==4)
    	// 	// {

    	// 	// 	lp = 10000;
    	// 	// 	if(!v4.empty())
    	// 	// 		continue;
    	// 	// }
    	// 	// else if(n==6)
    	// 	// {

    	// 	// 	lp = 1000000;
    	// 	// 	if(!v6.empty())
    	// 	// 		continue;
    	// 	// }
    	// 	// else if(n==8)
    	// 	// {
    	// 	// 	lp = 100000000;
    	// 	// 	if(!v8.empty())
    	// 	// 		continue;
    	// 	// }
    			

    		

    	// 	// 	for(int i = 0;i<lp;i++)
    	// 	// 	{
    	// 	// 		int value  = i;
    	// 	// 		int x = 1,cnt  = 1;
    	// 	// 		f = 0,s = 0;
    	// 	// 		while(value)
    	// 	// 		{
    	// 	// 			if(cnt<=n/2)
    	// 	// 			{
    	// 	// 				f += value%10 * x;
    	// 	// 				x*=10;
    	// 	// 				value /=10; 
    	// 	// 				if(cnt==n/2)
    	// 	// 					x = 1;
    	// 	// 				cnt++;
    	// 	// 			}
    	// 	// 			else
    	// 	// 			{

    	// 	// 				s += value%10 * x;
    	// 	// 				x*=10;
    	// 	// 				value /=10; 

    	// 	// 			}


    	// 	// 		}

    	// 	// 		value = f+s;
    	// 	// 		value *=value;
    	// 	// 		if(value==i)
    	// 	// 		{
    	// 	// 			if(n==2)
    	// 	// 				v2.push_back(i);
    	// 	// 			if(n==4)
    	// 	// 				v4.push_back(i);
    	// 	// 			if(n==6)
    	// 	// 				v6.push_back(i);
    	// 	// 			if(n==8)
    	// 	// 				v8.push_back(i);

    	// 	// 		}


    	// 	// 	}
    	// 	// }

    	// 	// for(int i = 0;i<cmd.size();i++)
    	// 	// {
    	// 	// 	//cout << cmd[i] << endl;
    	// 	// 	int value = cmd[i];

    	// 	// 	if(value==2)
    	// 	// 	{
    	// 	// 		for(int j = 0;j<v2.size();j++)
    	// 	// 		{
    	// 	// 			// if(v2[j]==0)
    	// 	// 			// 	printf("00\n");
    	// 	// 			// else if(v2[j]==1)
    	// 	// 			// 	printf("01\n");
    	// 	// 			// else printf("%d\n",v2[j]);

    	// 	// 		}
    	// 	// 	}
    	// 	// 	else if(value==4)
    	// 	// 	{
    	// 	// 		// for(int j = 0;j<v4.size();j++)
    	// 	// 		// {
    	// 	// 		// 	if(v4[j]==0)
    	// 	// 		// 		printf("0000\n");
    	// 	// 		// 	else if(v4[j]==1)
    	// 	// 		// 		printf("0001\n");
    	// 	// 		// 	else printf("%d\n",v4[j]);

    	// 	// 		// }
    	// 	// 	}
    	// 	// 	else if(value==6)
    	// 	// 	{
    	// 	// 		// for(int j = 0;j<v6.size();j++)
    	// 	// 		// {
    	// 	// 		// 	if(v6[j]==0)
    	// 	// 		// 		printf("000000\n");
    	// 	// 		// 	else if(v6[j]==1)
    	// 	// 		// 		printf("000001\n");
    	// 	// 		// 	else if(v6[j] == 88209)
    	// 	// 		// 		printf("088209\n");
    	// 	// 		// 	else printf("%d\n",v6[j]);

    	// 	// 		// }
    	// 	// 	}
    	// 	// 	else if(value==8)
    	// 	// 	{
    	// 	// 		// for(int j = 0;j<v8.size();j++)
    	// 	// 		// {
    	// 	// 		// 	if(v8[j]==0)
    	// 	// 		// 		printf("00000000\n");
    	// 	// 		// 	else if(v8[j]==1)
    	// 	// 		// 		printf("00000001\n");
    	// 	// 		// 	else if(v8[j] ==4941729 )
    	// 	// 		// 		printf("04941729\n");
    	// 	// 		// 	else if(v8[j] == 7441984)
    	// 	// 		// 		printf("07441984\n");

    	// 	// 		// 	else printf("%d\n",v8[j]);

    	// 	// 		// }
    	// 	// 	}
    	// 	}
    	
    	// shortcut 



    	while(scanf("%d",&n) !=EOF)
    	{
	    	if(n==2)
	    	for(int i = 0;i<v2.size();i++)
	    		cout << v2[i] << endl;
	    	if(n==4)
	    		for(int i = 0;i<v4.size();i++)
	    		cout << v4[i] << endl;
	    	if(n==6)
	    		for(int i = 0;i<v6.size();i++)
	    		cout << v6[i] << endl;
	    	if(n==8)
	    		for(int i = 0;i<v8.size();i++)
	    		cout << v8[i] << endl;
    	}
	#ifdef PARTHO
		int end_time = clock();
		printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif

	return 0;
}
