#include<stdio.h>



int main(){


	 #ifdef PARTHO
       freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
       freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
       //int start_time = clock();
  	#endif
       

      int n;
      long long sum = 0,ck = 0;

      scanf("%d",&n);
      if(n<0) ck = 1, n = n*-1;
     
      sum = n*(n+1)/2;
      if(ck) sum--,sum = sum*=-1;
      if(n==0) sum = 1;
      printf("%lld\n",sum);

	return 0;
}