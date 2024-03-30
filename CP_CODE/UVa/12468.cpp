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

   	int a,b;

   	while(1)
   	{
   		scanf("%d%d",&a,&b);
   		if(a == -1 && b == -1)
   			return 0;
   		/*if(a>b)
   			swap(a,b);
   		int value = abs(a-b);
   		value = min(value,abs(a+100-b));
*/
// or 
   		int value = abs(a-b);
   		value = min(value,100 - value);


   		cout << value << endl;
   	}
   
    	
    	
	#ifdef PARTHO
		int end_time = clock();
		printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif

	return 0;
}
