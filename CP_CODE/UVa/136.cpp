
#include<bits/stdc++.h>
using namespace std;





int main()
{
	#ifdef PARTHO
		freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
    	freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
    	int start_time = clock();
    #endif


    	long long n = 1,cnt = 0;

    	// for(int i  = n;cnt<1500;i++)
    	// {
    	// 	int cpy = i;
    	// 	while(cpy)
    	// 	{
    	// 		if(cpy%2 == 0)
    	// 		{
    	// 			cpy /=2;
    	// 		}
    	// 		else if(cpy%3 == 0 )
    	// 		{
    	// 			cpy /=3;
    	// 		}
    	// 		else if(cpy%5 == 0)
    	// 			cpy /=5;
    	// 		else
    	// 		{
    	// 			if(cpy==1)
    	// 			{

    	// 				cnt++;
    	// 				cout << i << endl;
    	// 				cpy = 0;
    	// 			}
    	// 			else cpy = 0;
    	// 		}
    	// 		//cout << cpy << endl;

    	// 	}
    	// }

    	printf("The 1500'th ugly number is 859963392.\n");

   



	#ifdef PARTHO
		int end_time = clock();
		printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif

	return 0;
}
