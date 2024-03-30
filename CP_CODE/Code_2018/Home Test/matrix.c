#include<stdio.h>

int main()
{
    printf("The Writer Of This Program:-Partho Protim Das.\nInstitute:-DCC(CSE). Batch:-21\nSection:-B\n\n");
    printf("NOTE:-For ADDING OR Subtract Of Two Matrix \nThe Dimensions Number Of Both Matrix Has To Be Same\nAnd For Multiplication \nThe Numbers Of First Matrix Column And The Numbers Of The Second Matrix Row\n\Has To Be Same\nEnjoy :)\n\n");
    int m, n,r,s,mul[100][100],k,c,key;
   // printf("Enter The Dimension Of First Matrix \nSeparate Them By Using Space OR Enter\n");
    while(printf("Enter The Dimension Of First Matrix \nSeparate Them By Using Space OR Enter(EX:1 2 For 1x2 matrix) \n"),scanf("%d%d",&m,&n)!= EOF)
{
    int a[m][n], x[m][n];
    int i = 0 , j = 0 ;
        printf("Enter The Value Of First Matrix\n");
    for( i = 0; i < m; i ++ )
    {
        for(j = 0;j < n;j ++ )
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("Enter The Dimension Of Second  Matrix\nSeparate Them By Using Space OR Enter(EX:3 2 For 3x2 matrix) \n");
    scanf("%d%d",&r,&s);
            int b[r][s];
            printf("Enter The Value Of Second Matrix\n");
    for( i = 0; i < r; i ++ )

    {
        for(j = 0;j < s;j ++ )
        {
            scanf("%d",&b[i][j]);
        }
    }

    printf("What you want to do ? ");
    printf("Press 1 For ADD Press 2 For Subtract Press 3 For Multiplication\n");
    scanf("%d",&key);


    if(key == 1){

    if(m == r && n == s){
        printf("\nSum Of The Two matrix :\n");
    for(i = 0; i < m; i++ )
    {
        for(j = 0; j < n; j++)
        x[i][j] = a[i][j] + b[i][j];
    }
     for(i = 0; i < m; i++ )
    {
        for(j = 0; j < n; j++)
        printf("%d ",x[i][j]);
         printf("\n");
    }
        printf("\n");
    }
     else if(m != r || n != s)
     {
         printf("Please Enter The Dimension Correctly \nOr Read The Notation From First Of This Program\n\n");
     }
    }
    else if(key == 2){
        printf("\nSum Of The Two matrix :\n");
        if(m == r && n == s){
         for(i = 0; i < m; i++ )
    {
        for(j = 0; j < n; j++)
        x[i][j] = a[i][j] - b[i][j];

    }
    for(i = 0; i < m; i++ )
    {
        for(j = 0; j < n; j++)
        printf("%d ",x[i][j]);

        printf("\n");
    }
         printf("\n");
    }
     else if(m != r || n != s)
     {
         printf("Please Enter The Dimension Correctly \nOr Read The Notation From First Of This Program");
     }
    }

    else if (key == 3)
        {
        printf("\nSum Of The Two matrix :\n");
        if(n == r)
        {

        for( i = 0; i < m; i ++ )
        {

            for(j = 0;j < s;j ++ )
            {
                c = 0;
                for (k = 0 ; k < r  ; k++) {
                c = c + (a[i][k]*b[k][j]);
                }
                mul[i][j] = c;
            }
    }
    for( i = 0; i < m; i ++ )
        {
            for(j = 0;j < s;j ++ )
                printf("%d ",mul[i][j]);

                printf("\n");
        }
         printf("\n");
    }
    else
        printf("Please Enter The Dimension Correctly \nOr Read The Notation From First Of This Program");
        }

     printf("NOTE:-For Stop This program Press Ctrl+Z.When Your Job Gets Done \nOr you can continue By typing The values\n_ _Partho\n\n");
}

    printf("Thanks For using My program..Partho\nIf You Want Give Any Feedback ==> partho.prothim7@gmail.com\nThank you");
   return 0;
}
