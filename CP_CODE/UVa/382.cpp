#include<bits/stdc++.h>

using namespace std;


int expo(int b,int p)
{
	if(p == 0)
		return 1;
	else
	{
		if(p&1)
			return b*expo(b,p-1);
		else {
			int temp = expo(b,p/2);
			return temp*temp;
		}
	}
}

int main()
{

	


	int n;
	printf("PERFECTION OUTPUT\n");
	while(1)
	{
		cin >> n;
		if(n==0)
			break;
		int sum =  0;
    	for(int i = 1;i<n;i++)
    	{
    		if(n%i==0)
    			sum+=i;

    	}
    	if(n==sum)
    		printf("%5d  PERFECT\n",n);
    	else if(n>sum)
    		printf("%5d  DEFICIENT\n",n);
    	else if(n<sum)
    		printf("%5d  ABUNDANT\n",n);

	}
	printf("END OF OUTPUT\n");

	return 0;
}
