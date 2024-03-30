#include<stdio.h>
#include<string.h>


int main(){


	 #ifdef PARTHO
       freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
       freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
       //int start_time = clock();
  	#endif
       

       int n;
       scanf("%d",&n);
       char str[100];
       scanf("%s",str);
       int k = strlen(str);
       long long fact = 1;
     	for(int i = 0;1;i++)
       		{
       				if(n-k*i <=0)
       					break;
       				fact *= n-k*i;
       		}
       printf("%lld\n",fact);


	return 0;
}