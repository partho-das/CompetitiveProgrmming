
#include<bits/stdc++.h>
using namespace std;





int main()
{
	#ifdef PARTHO
		freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
    	freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
    	int start_time = clock();
    #endif

    char str[2000];

    	while(gets(str))
    	{
    		
	    	for(int i = 0;i<strlen(str);i++)
	    	{
	    		str[i]-=7;
	    	}


	    	cout << str << endl;
    	}

    	
    	   



	#ifdef PARTHO
		int end_time = clock();
		printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif

	return 0;
}
