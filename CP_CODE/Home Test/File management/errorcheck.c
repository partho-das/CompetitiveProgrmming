#include<stdio.h>

int main()
{
    FILE *fp;
    int ch;
    fp = fopen("new.txt","w");
   ch = getc(fp);
    if(ferror(fp))
        printf("error found partho\n");
        else
        printf("%c\n",ch);

        clearerr(fp);

        if(ferror(fp))
        printf("error found partho\n");
        else
        printf("%c\n",ch);


    fclose(fp);
    return 0;
}

