#include<stdio.h>

int multi(int n,int m)
{
    int ans = 0;
    while(m--)
    {
        ans +=n;
    }
    return ans;
}

int abs(int a,int b)
{
    int sum  = add(a,b);

    if (sum<0)
        return -sum;
    else return sum;
}

int add(int a,int b)
{
    return a+b;
}


int main()
{
  int a,b;
  int product = 1;
  scanf("%d%d",&a,&b);
   //sum = abs(a,b);

  product =  multi(a,b);

  printf("%d",product);


    return 0;
}
