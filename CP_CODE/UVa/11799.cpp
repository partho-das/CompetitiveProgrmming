#include<bits/stdc++.h>

using namespace std;


int main()
{



	int t,mx = 0,value;

	cin >> t;

	for(int i = 1;i<=t;i++)
	{
		mx = 0;

		int n;

		cin >> n;

		while(n--)
		{
			cin >> value;
			mx = max(mx,value);
		}
		   printf("Case %d: %d\n",i,mx);
	}



	return 0;
}