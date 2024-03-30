//Fibonacci Number using function. 
#include<stdio.h>
int fib(int n)
{
	if(n==0)
		return 0;
	if(n==1)
		return 1;
	return fib(n-1)+fib(n-2);
}
int main()
{
	
	int n,i,value; 

	scanf("%d",&n);

	for( i = 0;i<=5;i++)
	{
		 value = fib(i);

		printf("%d ", value);
	}
	return 0;
}

	