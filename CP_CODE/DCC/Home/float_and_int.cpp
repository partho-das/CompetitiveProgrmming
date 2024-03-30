#include<stdio.h>

int main()
{

	
	int a;
	float n,b;

	scanf("%f",&n);

	a = n;
	b = n-a;

	printf("Integer part = %d\n",a);
	printf("Floating part =  %f\n",b);
	return 0;
}

#include <stdio.h>
int main()
{
	#ifdef PARTHO
		freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
    	freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
    #endif
int n, i;
printf("Enter an integer: ");
scanf("%d", &n);
for(i=1; i<=5; ++i)
{
printf("%d * %d = %d \n", n, i, n*i);
}
return 0;
}