#include<stdio.h>
#include<string.h>

char file_name[100];

void file_rename(char *new_name)
{
    strcpy(file_name,new_name);
    strcat(file_name,".txt");
}
 FILE *creat(char *mood)
 {
     FILE *fp;
     fp = fopen(file_name,mood);

     return fp;
 }

 void file_write(FILE *fp)
 {
     fprintf(fp,"%s\n",file_name);
 }
void file_print(FILE *fp)
{
    char arr[100];
    fscanf(fp,"%s",arr);
    puts(arr);
}
int main()
{
    FILE *fp;

    file_rename("myfile");

   fp = creat("r");
    file_print(fp);
   fclose(fp);



    return 0;
}
