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
    	for(int c = 1;c<=t;c++)
    	{
    		int l,w,h;

    		cin >> l >> w >> h;


    		printf("Case %d: ",c);
    		

    		if(l>20||w>20||h>20)
    			printf("bad\n");
    		else printf("good\n");



    	}
   
   
    	
    	
	#ifdef PARTHO
		int end_time = clock();
		printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif

	return 0;
}
