#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int main()
{
	 #ifdef PARTHO
        char file1[200] = "/home/partho/Desktop/CODEFORCES/IO/output.txt ";
        char file2[200] = "/home/partho/Desktop/CODEFORCES/IO/coutput.txt";
        char command[200] = "diff -y ";
        strcat(file1, file2);
        strcat(command, file1);
        system(command);
    #endif


	return 0;
}