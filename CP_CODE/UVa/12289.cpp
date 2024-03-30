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

   	int t;

   	cin >> t;

   	while(t--)
   	{
   		string str;
   		cin >> str;

   		if(str.size() == 3)
   		{
   			if((str[0] == 'o' && str[1] == 'n') ||
   			 (str[0] == 'o' && str[2] == 'e') ||
   			  (str[1] == 'n' && str[2] == 'e'))
   				printf("1\n");
   			else{
   				printf("2\n");
   			}
   		}
   		else
   		{
   			printf("3\n");
   		}
   	}
   
    	
    	
	#ifdef PARTHO
		int end_time = clock();
		printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif

	return 0;
}
