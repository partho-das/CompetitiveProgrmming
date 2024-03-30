#include<stdio.h>

int main()

{
    char count[][10]= {"hiihihih"};
    int i ,sum = 0;

    //gets(count[0]);


    for(i = 0; count[0][i];i++)
        sum =  sum + 1;
    printf("%d",sum);

    return 0 ;
}
