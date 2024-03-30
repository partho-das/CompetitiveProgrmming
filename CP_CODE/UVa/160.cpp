
#include<bits/stdc++.h>
using namespace std;



bool arr[100];
int stor[100];

void gen(int n)
{
	for(int i = n;i>=0;i--)
	{
		if(arr[i] )
		{
			while(n%i == 0)
			{
				stor[i]++;
				n = n/i;
			}
		}
	}
}

int main()
{
	#ifdef PARTHO
		freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
    	freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
    	int start_time = clock();
    #endif
    	int ck = 0,n;
   	 for(int i = 2;i<100;i++)
   	 {
   	 	for(int j = 2;j<i;j++)
   	 	{
   	 		if(i%j == 0) ck = 1;
   	 	}

   	 	if(ck == 0)
   	 		arr[i] = 1;
   	 	ck = 0;
   	 }


   	while(1)
   	{

   		cin >> n;
   		memset(stor,0,sizeof stor);
   		if(n==0)
   			return 0;

   		for(int i = 2;i<=n;i++)
   		{
   			gen(i);
   		}
   		int cnt = 0;
   		printf("%3d! =",n );
   		for(int i = 0;i<=n;i++)
   		{
   			if(arr[i])
   			{
   				cnt++;
   				if(cnt%16==0)
   				{
   					cnt = 0;
   					printf("\n      ",stor[i]);
   				}
   				printf("%3d",stor[i]);
   			}
   		}
   		cout << endl;
   	}



	#ifdef PARTHO
		int end_time = clock();
		printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif

	return 0;
}
