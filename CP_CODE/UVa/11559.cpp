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

    	
    int n,week,hotel,budget;

    while(scanf("%d%d%d%d",&n,&budget,&hotel,&week) !=EOF)
    {
        int mn = 1e9+7;
        int sum,cost,free,ck = 0;
         mn = budget+1;
        for(int i = 0;i<hotel;i++)
        {   
            ck = 0;
            cin >> cost;
            for(int j = 0;j<week;j++)
            {
                scanf("%d",&free);

                if(free>=n)
                    ck = 1;
            }
            if(n*cost<=budget && ck == 1)
                mn = min(mn,n*cost);
        }

        if(mn != budget+1)
            printf("%d\n",mn);
        else puts("stay home");
    }
   
    	
    	
	#ifdef PARTHO
		int end_time = clock();
		printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif

	return 0;
}
