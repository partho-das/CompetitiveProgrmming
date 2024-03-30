#include<bits/stdc++.h> 

int main()
{
    long long arr;
    int test ;

    scanf("%d",&test);
    while(test--)
         { 
            scanf("%lld",&arr);
            arr = (sqrt(1+(8*arr))-1)/2;
            printf("%lld\n",arr);
        
        }
  return 0; 
}