#include<stdio.h>
#include<string.h>


 char words[2][40] = {
     "dog", "Hund",
     "No", "nein",
     "year", "Jahr",
     "child", "kind",
     "i", "ich",
     "drive", "fahren",
     "house", "Haus",
     "to", "zu",
     "",""
     };




int main()
{

    char english[10];

    int i;

    /*printf("Enter English Word ");

    gets(english);

    /// look up the word
     i = 0 ;

     /// search while null  string not yet encounter

     while(strcmp(words[i][0],""))
     {
         if(!strcmp(english,words[i][0]))
         {
             printf("German translation : %s",words[i][1]);
            //. printf("%d",i);

             break;
         }
         i++;
     }
    if(!strcmp(words[i][0],""))
        printf("NOT int dictionary \n");
        */


        printf("%s",words[5]);


    return 0;
}
