
#include<bits/stdc++.h>
using namespace std;





int main()
{
	#ifdef PARTHO
		freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
    	freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
    	int start_time = clock();
    #endif

   
    	
    	double n,p;


    	while(scanf("%lf%lf",&n,&p) !=EOF)
    	{
    		cout << p << n << endl;

    		double ans = pow(p,1.0/n);
    		
    		printf("%.0lf\n",ans);

    	}
	#ifdef PARTHO
		int end_time = clock();
		printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif

	return 0;
}
