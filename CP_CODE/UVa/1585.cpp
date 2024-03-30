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

   	
   	char str[100];
   	int value[100];

  	int t ;
  	cin >> t;

  	while(t--)
  	{
  		cin >> str;
   		int len = strlen(str);
   		memset(value,0,sizeof value);
   		int sum = 0;
   		if(str[0] == 'O')value[0] = 1,sum+=value[0];
   		for(int i = 1;i<len;i++)
   		{
   			if(str[i] == 'O')
   				value[i]= value[i-1]+1;
   			sum+=value[i];
   		}

   		cout << sum << endl;


   }
   
    	
    	
	#ifdef PARTHO
		int end_time = clock();
		printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif

	return 0;
}
