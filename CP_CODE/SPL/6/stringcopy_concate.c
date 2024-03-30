//copying a string to another string  variable and concat two strings
#include<stdio.h>
#include<string.h>

int main()
{
	 

	char str1[1000],str2[10000],str3[1000] = "Dhaka city college";
	int length;

	printf("Enter the string\n");
	scanf("%s",str1);


	strcpy(str2,str1); // copying a string to another string  variable

	printf("The copied string  : %s\n",str2);


	strcat(str1,str3);
	printf("After concat str1 = %s",str1);


	return 0;
}