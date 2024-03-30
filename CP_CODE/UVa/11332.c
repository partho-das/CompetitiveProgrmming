#include<stdio.h>

int main()
{
   char arr[20];

   int value = 0,mod,i,fst,sec;

   while(1)
   {
       value = 0;
   scanf("%s",arr);
    if(arr[0]=='0')
        break;
   for(i=0;arr[i];i++)
   {
       value+= (arr[i]-'0');
   }

   while(1)
   {
   fst = value/10;
   sec = value%10;
   value = fst+sec;
   if(value/10==0)
    break;
    }
   printf("%d\n",value);

   }

    return 0;
}
