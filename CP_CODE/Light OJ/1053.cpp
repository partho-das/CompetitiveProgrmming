#include<stdio.h>


#define ll long long

void swap(ll *a, ll *b)
{
	ll temp = *a;*a = *b;*b = temp;
}

int main()
{

	 #ifdef PARTHO
       freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
       freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
       //int start_time = clock();
  	#endif

       int test,x,temp;
       scanf("%d",&test);
       for( x = 1;x<=test;x++)
       {
       		ll a,b,c;

       		scanf("%lld%lld%lld",&a,&b,&c);
       		
       		 if(a<b)
       		 swap(&a,&b);
       		 if(b<c) swap(&b,&c);
       		 if(a<b) swap(&a,&b);

       		a = a*a;
       		b = b*b;
       		c = c*c;
       		printf("Case %d: ",x);
       		if(a == b+c)
       			puts("yes");
       		else puts("no");

       }

  return 0;
  }