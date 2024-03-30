#include<stdio.h>

struct student
{
	char name[100];
	int roll;
	int mark;
};

int main()
{
	
	struct student stu[11];
	int n = 0,sum = 0;
	float ave = 0;
	for(int i = 0;i<10;i++)
	{
		scanf("%s%d%d",&stu[i].name,&stu[i].roll,&stu[i].mark);
		sum+= stu[i].mark;
		n++;
	}

	ave = (float)sum/n;
	printf("\t\tName\t\tRoll\n");
	for(int i = 0;i<10;i++)
	{
		printf("  %10s %10d\n",stu[i].name,stu[i].roll);
		
	}

	printf("Average = %.2f\n",ave );



}