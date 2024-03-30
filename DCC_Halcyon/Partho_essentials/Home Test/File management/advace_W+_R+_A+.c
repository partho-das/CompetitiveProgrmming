#include<stdio.h>

int main()
{

    FILE *fp,*fp1;
    char str[100];

    fp = fopen("new.txt","r+");
    fp1 = fopen("new.txt","r+");


    fscanf(fp1,"%s",str);
    printf("%s",str);

    fprintf(fp,"hi\0");
        fclose(fp);

    fclose(fp);
    fclose(fp1);





}
