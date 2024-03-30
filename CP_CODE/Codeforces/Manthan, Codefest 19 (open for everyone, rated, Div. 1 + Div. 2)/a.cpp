
#include<bits/stdc++.h>
using namespace std;

int fib(int n,int a,int b)
{
	if(n==0)
		return a;
	if(n==1)
		return b;

	return fib(n-1,a,b)^fib(n-2,a,b);
}



int main()
{
	#ifdef PARTHO
		freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
    	freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
    	int start_time = clock();
    #endif

    		int n , a,b;

    		int t;

    		cin >> t;

    		while(t--)
    		{
    			cin >> a >> b >> n;

    			if(n%3==0)
    				cout << a << endl;
    			else if(n%3==1)
    				cout << b << endl;
    			else if(n%3==2)
    				cout << (a^b) << endl;
    		}


   



	#ifdef PARTHO
		int end_time = clock();
		printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif

	return 0;
}
