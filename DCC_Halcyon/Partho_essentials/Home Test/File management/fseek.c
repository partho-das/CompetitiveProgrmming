#include<stdio.h>

int main()
{
    FILE *fp;
    char str[100];

    fp  = fopen("new.txt","w");
    fprintf(fp,"sharif");
    fclose(fp);

    fp  = fopen("new.txt","r");
    fseek(fp,2,0);
    fseek(fp,2,1);
    fseek(fp,-1,2);
    fscanf(fp,"%s",str);
    puts(str);
    fseek(fp,-2,1);
    fscanf(fp,"%s",str);
    puts(str);
    fclose(fp);


    return 0;
}
