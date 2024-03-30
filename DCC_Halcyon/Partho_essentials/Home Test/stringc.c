#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main()
{
    char command[0],temp[80];

    int i,j;

    for(; ; )
    {

        printf("Operation? ");

        gets(command);

    /// see if user wants to stop
    if(!strcmp(command,"quit"))
        break;

    printf("Enter the first number :");
    gets(temp);


    i  = atoi(temp);

    printf("enter the second number :");
    gets(temp);
    j = atoi(temp);

    ///noe ,perform the operation
    if(!strcmp(command,"add"))
        printf("%d\n",i+j);
    else if(!strcmp(command, "subtrct"))
    printf("%d\n",i - j);
    else if(!strcmp(command, "divide"))
    {
        if(j)
    printf("%d\n",i/j);
    }
    else if(!strcmp(command, "multiply"))
        printf("%d\n",i*j);

    else printf("unknown command .\n");
}

    return 0;
}
