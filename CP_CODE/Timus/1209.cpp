#include<stdio.h>
#include<math.h>
int main(){


	 #ifdef PARTHO
       freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
       freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
       //int start_time = clock();
  	#endif



       int test;
       scanf("%d",&test);
       while(test--)
       {/// soln:https://acm.timus.ru/forum/thread.aspx?id=30833&upd=636689140300960921
       	//or second soln:https://acm.timus.ru/forum/thread.aspx?id=42260&upd=637046564643628355
       		long long  n;
       		scanf("%lld",&n);

       		long long value = 8*n - 7;

       		double v = sqrt(value);
       		long long  v1 = sqrt(value);

       		if(v-v1 == 0)
       			printf("1");
       		else printf("0");
       		if(test)
       			printf(" ");
       }

       
    


	return 0;
}