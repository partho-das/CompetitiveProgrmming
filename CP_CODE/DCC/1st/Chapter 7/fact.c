//calculating factorial of n using recursion.
#include<stdio.h>


int fact(int n)
{
	if(n<=1)
		return 1;
	else return n*fact(n-1);
}

int main()
{
	

	int n;

	scanf("%d",&n);

	int value = fact(n);

	printf("%d\n",value );




	return 0;
}