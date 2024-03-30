 #include<stdio.h>

int main()
{
    int a,b,c;

    scanf("%d%d",&a,&b);
   /*if(a>b)
   {
       c = a;
       a = b;
       b = c;
   }*/
    for( a ; a >= b ; a-- )
        printf("%d ",a);


    return 0;
}
