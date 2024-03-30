#include<stdio.h>



int main(){


	 #ifdef PARTHO
       freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
       freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
       //int start_time = clock();
  	#endif

	int n,m;
	scanf("%d%d",&n,&m);
	int sum = n+m -1;

	printf("%d %d\n",sum-n,sum-m);


	return 0;
}