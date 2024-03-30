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

    	string str;
    	int Case = 1;
    	while(1)
    	{
    		cin >> str;

    		

    		if(str == "#")
    			break;

    		printf("Case %d: ",Case++ );
    		
    			if (str == "HELLO")
    			printf("ENGLISH\n");
    			else if (str == "HOLA")
    			printf("SPANISH\n");
    			else if (str == "HALLO")
    			printf("GERMAN\n");
    			else if (str == "BONJOUR")
    			printf("FRENCH\n");
    			else if (str == "CIAO")
    			printf("ITALIAN\n");
    			else if (str == "ZDRAVSTVUJTE")
    			printf("RUSSIAN\n");
				else 
    			printf("UNKNOWN\n");

    	
    	}

   
   
    	





    	
	#ifdef PARTHO
		int end_time = clock();
		printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif

	return 0;
}
