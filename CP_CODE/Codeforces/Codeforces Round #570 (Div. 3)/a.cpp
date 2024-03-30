#include <bits/stdc++.h>

using namespace std;

int main()
{
	#ifdef PARTHO
		freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
    	freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
    	int start_time = clock();
    #endif
    	int q;

    	cin >> q;


    	while(q--)
    	{
    		int n,mi = 10000000,mx = 0,k,value,b = 0;
    		scanf("%d%d",&n,&k);

    		for(int i = 0;i<n;i++)
    		{
    			scanf("%d",&value);
    			mi = min(mi,value);
    			mx = max(mx,value);
    		}

    		b = mi+k;
    		value = b;
    		value = max(0,value-1000);

    		//cout << k << " "<< mi << " "<< mx << endl;
    		while(1)
    		{
    			//cout << abs(mi-b) << " abs = " <<  abs(mx-b) << endl;
    			if(b<value)
    			{
    				//cout << abs(mi-b) << " abs = " <<  abs(mx-b) << endl;
    				printf("-1\n" );
    				break;	

    			}
    			if(abs(mi-b)<=k && abs(mx-b)<=k )
    			{
    				//cout << abs(mi-b) << " abs = " <<  abs(mx-b) << endl;
    				printf("%d\n",b );
    				break;	

    			}
    			else
    			{
    				b--;
    			}

    		}
    	}


	#ifdef PARTHO
		int end_time = clock();
		printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif

	return 0;
}
