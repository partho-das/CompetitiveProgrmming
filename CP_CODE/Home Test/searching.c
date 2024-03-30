#include<stdio.h>

int main()
{
   int b,cs = 1;

   while(scanf("%d",&b)!=EOF)
   {


    int a[b];
    int sc,i,ax;


    for(i = 0; i<b ;i++)
    {
        scanf("%d",&a[i]);
    }
      scanf("%d",&sc);
    for( i = 0 ; i<b ; i++)
    {
        if(a[i] == sc)
            break;
    }

    if( b == i )
        printf("case %d : no\n",cs);
    else
      printf("Case %d : %d",cs,i+1);
      cs ++;
   }

    return 0;
}
