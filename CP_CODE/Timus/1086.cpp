#include<stdio.h>

const int maxn = 2e5;


int cnt = 0;
void primegen(int* primex,int *store)
{
	for(int i = 2;i*i<= maxn ;i++)
	{ if(primex[i]==0)
		{
			for(int j = i+i;j <= maxn; j+=i)
			{
				primex[j] = 1;
				
			}
		}
		
	}
}
int main(){


	 #ifdef PARTHO
       freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
       freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
       //int start_time = clock();
  	#endif
       int primex[maxn+5];
		int store[maxn];
       primegen(primex,store);
       int x = 1;
       for(int i = 2;i<maxn;i++)
       {
       		if(primex[i] == 0){
       			store[x++] = i;
       		}
       }

       int k;
       scanf("%d",&k);
       while(k--)
       {
       	int n;
       	scanf("%d",&n);
       	printf("%d\n",store[n]);
       }
       
    


	return 0;
}