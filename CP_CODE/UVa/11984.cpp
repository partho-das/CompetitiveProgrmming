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
    	scanf("%d",&t);

    	for(int c = 1;c<=t;c++)
    	{
    		float cel,fah;

    		cin >> cel >> fah;

    		float fahsum = cel*9.0/5+32;
    		fahsum+=fah;

    		cel = (fahsum-32)* 5.0/9 ;

    		

    		printf("Case %d: %.2f\n",c,cel);

    	}

   
   
    	
    	
	#ifdef PARTHO
		int end_time = clock();
		printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif

	return 0;
}
