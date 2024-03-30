#include<stdio.h>



int main(){


	 #ifdef PARTHO
       freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
       freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
       //int start_time = clock();
  	#endif
       int a,b,n;

       long long res;

       scanf("%d%d%d",&n,&a,&b);

       res = (2*n)*(a*b);

       printf("%lld\n",res);


	return 0;
}