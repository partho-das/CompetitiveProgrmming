/*#include<stdio.h>

 int main ()
{
    int n;
    scanf("%d",&n);
    printf("\nYou entered an %d number\n", n&1 ? 1 : 2);
    return 0;
}*/
#include<stdio.h>

int main()
{
    int YEAR;
    scanf("%d",&YEAR);

    if((YEAR&3 == 0 && YEAR%100 != 0 ) || YEAR%400 == 0) printf("%d this is a leap Year\n",YEAR);
    else printf("%d this is a not Year\n",YEAR);

    return 0;
}







