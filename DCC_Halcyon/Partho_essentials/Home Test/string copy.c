/// Pranto standard
#include<stdio.h>
#include<string.h>
//#include<strtoke


int main()
{
    int ln  = 0;
    char s[10000];
    for(int i = 0; i<5; i++){
        scanf("%s",s+ln);/// s+ln==(srting input starts from ln)
        while(s[ln]) ln++;///calculating string lenth
    }
    printf("%s %d\n", s,ln);
    return 0;
}

///OR Causal
/**#include<stdio.h>

int main()
{

    char ar[20] = "amar",arc[20] = "nam";

    int i = 0,sz;
    //scanf("%s",ar);

    for(i = 0;ar[i];i++);
    sz = i;
    for(i= 0;arc[i];i++)
    ar[i+sz]= arc[i];
    ar[i+sz]= arc[i];
    printf("%s",ar);


    return 0;
}*/


