///Function(array as parameter)
#include<stdio.h>

void abc(int arr[][5])
{

   printf("abc %d\n",arr[0][3]);

}

int main()
{
    int arr[1][5] = {1,2,3,4,5};

    abc(arr);

   // printf("%d",arr[0][3]);

    /// printf("%d",arr[0]);

    return 0;
}

