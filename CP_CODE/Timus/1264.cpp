#include<stdio.h>



int main(){


	 #ifdef PARTHO
       freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
       freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
       //int start_time = clock();
  	#endif

	int n,m;
	scanf("%d%d",&n,&m);
	m++;
	long long result = n*m;

	printf("%lld\n",result);


	return 0;
}