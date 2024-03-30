#include<stdio.h>


#define ll long long

int main()
{

   #ifdef PARTHO
       freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
       freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
       //int start_time = clock();
    #endif

  int test,x;
  scanf("%d",&test);

  for(x = 1;x <= test; x++)
  { 
    int n,sum = 0,value,i;
    scanf("%d",&n);
    for(i = 0;i<n;i++)
    {
      scanf("%d",&value);
      if(value<0)
        continue;
      else sum+=value;
    }
    printf("Case %d: %d\n",x,sum );
  }      
  return 0;
  }