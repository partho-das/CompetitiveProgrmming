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

    	int n;
    	cin >> n;
    	printf("Lumberjacks:\n");
    	while(n--)
    	{
    		int ck = 0,srt = 0,stor,value;
    		for(int i = 0;i<10;i++)
    		{
    			scanf("%d",&value);
    			//cout << value << " ";
    			
    			if(i==0)
    			{
    				stor = value;
    				continue;
    			}
    			else if(i==1)
    			{
    				if(value>stor)
    				srt = 1;
    				else srt = 2;
    				stor = value;
    			}
    			else
    				{
    					if(srt == 1 && value>stor)
    						stor = value;
    					else if(srt == 2 && stor>value)
    						stor = value;
    					else 
    					{
    						stor = value;
    						ck = 1;
    					}

    				}
    			//	cout << "stro  = " << stor << " i = " << i << " ck =  "<< ck << endl;

    		}

    	
    		
    		if(ck == 1)
    			puts("Unordered");
    		else puts("Ordered");
    	}
   
   
    	
    	
	#ifdef PARTHO
		int end_time = clock();
		printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif

	return 0;
}
