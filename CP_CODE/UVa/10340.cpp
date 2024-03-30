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

   	string original,test;

   	while(cin >> original >> test)
   	{
   		int x = 0;
   		for(int i = 0;i<test.size();i++)
   		{
   			if(original[x]==test[i])
   				x++;
   		}
   		if(x==original.size())
   			printf("Yes\n");
   		else
   			printf("No\n");
   	}
   
    	
    	
	#ifdef PARTHO
		int end_time = clock();
		printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif

	return 0;
}
