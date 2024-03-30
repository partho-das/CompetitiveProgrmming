//Is the string is Palendeom or not.
#include<stdio.h>
#include<string.h>

int main()
{

	char str1[1000],str2[10000];
	int length,i,j = 0;

	printf("Enter the string\n");
	scanf("%s",str1);

	length = strlen(str1);
	for(i = length-1,j = 0;i>=0;i--,j++)
	{

		str2[j] = str1[i];
	}
	str2[j] ='\0';
	int cmp = strcmp(str2,str1);

	if(cmp==0)
		printf("Palendeom\n");
	else
		printf("Not Palendeom\n");


	return 0;
}
