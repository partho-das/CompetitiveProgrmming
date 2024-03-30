#include<stdio.h>
#include<string.h>
int main()

{
    char st1[80],st2[80];
    int i;
    printf("Enter the first string ");
    gets(st1);
    printf("Enter the second string ");
    gets(st2);

    ///see how long is the first string is.
    printf("%s %d char long\n",st1, strlen(st1));

    ///see how long is the second string is.
    printf("%s %d char long \n",st2,strlen(st2));

    ///compare the string s
    i = strcmp(st1,st2);

    if(!i)
        printf("seme\n");

    else if(i<0)
        printf("First string is less then second \n");

    else
        printf("First string is getter then the second\n");

      //  concatenate st2 to end of str1 if the there is enough room

    if (strlen(st1)+strlen(st2) < 80 )
    {
        strcat(st2,st1);
        printf("%s\n",st2);
    }
    ///copy st2 to st1

    strcpy(st2,st1);
    printf("%s%s\n",st2,st1);

    return 0;
}
