#include<stdio.h>

int main()
{
    FILE *fp;
    int n,m;
    char arr[100];

    fp = fopen("Newfile.txt","w");
    gets(arr);
    fprintf(fp,"%s",arr);
    fclose(fp);

    fp = fopen("Newfile.txt","r");
    fscanf(fp,"%[^\n]",arr);
    fclose(fp);

    fp = fopen("Newfile1.txt","w");
    fprintf(fp,"%s",arr);
    fclose(fp);


    return 0;
}
