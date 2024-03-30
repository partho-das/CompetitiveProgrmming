//Sort the numbers from an array using function.

#include<stdio.h>


void sort(int *arr , int n)
{
	 int i, j,temp; 
   		for (i = 0; i < n-1; i++)       
  
       // Last i elements are already in place    
       for (j = 0; j < n-i-1; j++)  
           if (arr[j] > arr[j+1]){
           	temp = arr[j];
           	arr[j] = arr[j+1];
           	arr[j+1] = temp;

           } 
      

}
int main()
{
	

	
	int arr[1000],n,mx,i; // n = the size of the array
						


	scanf("%d",&n);

	for(i = 0;i<n;i++)
	{
		scanf("%d",&arr[i]);

	}

	sort(arr,n);
	for(i = 0;i<n;i++)
	{
		printf("%d ",arr[i] );

	}


	return 0;
} 