//compare two string  variable and calculatig the length of the sting 

#include<stdio.h>
#include<string.h>

int main()
{
	 
	
	char str1[1000],str2[10000];
	int length;

	printf("Enter the first string\n");
	scanf("%s",str1);
	printf("Enter the second string\n");
	scanf("%s",str2);

	length = strlen(str1); // calculating the length of str1
	printf("The length of the first string is : %d\n",length);

	length = strlen(str2); // calculating the length of str2
	printf("The length of the second string is : %d\n",length);

	int cpm = strcmp(str1,str2);// copying a string to another string  variable

	if(cpm==0)
		printf("string : %s and string %s [Are Same] \n",str1,str2 );
	else printf("string : %s and string : %s [Are Not Same] \n",str1,str2 );


	return 0;
}