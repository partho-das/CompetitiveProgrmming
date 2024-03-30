//Find the leargest number from an array using function.

#include<stdio.h>


int findmx(int *arr, int n)
{
	int mx = arr[0];
	for(int i = 0;i<n;i++)
	{
		if(arr[i]>mx)
			mx = arr[i];
	}
	return mx;
}
int main()
{


	
	int arr[1000],n,mx; // n = the size of the array
						// mx = is using for stroing the largest value.  



	scanf("%d",&n);

	for(int i = 0;i<n;i++)
	{
		scanf("%d",&arr[i]);

	}

	mx = findmx(arr,n);

	printf("The largest number is =  %d\n" , mx );


	return 0;
} 