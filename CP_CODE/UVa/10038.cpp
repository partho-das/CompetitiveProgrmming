#include<bits/stdc++.h>

using namespace std;

int arr[3020];

int main()
{

	#ifdef PARTHO
		freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
    	freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
    	int start_time = clock();
    #endif
	int n , ck = 0 ,value;

	while(scanf("%d",&n) !=EOF)
	{
		bool is[3020];
		memset(is,0,sizeof is);
		for(int i = 0;i<n;i++)
		{
			cin >> arr[i];
			
		}
		
		for(int i = 1;i<n;i++)
		{
			value = abs(arr[i] - arr[i-1] );
			if( value >= 1 and value < n)
			{

			  is[value] = 1;
			  
			}
			else
			{
				cout <<"Not jolly" << endl;
				ck = 1;
				break;
			}
			//cout << value << " ";
		}
		if(ck == 0)
		{
			for(int i = 1;i<n;i++)
			{
				if( !is[i] )
				{
					cout <<"Not jolly" << endl;
					ck = 1;
					break;
				}
				//cout << is[i] << " " << i <<"e ";
			}
			if(ck == 0)
			cout << "Jolly" << endl;
		}
		ck = 0;
		
	}
	return 0;
}

