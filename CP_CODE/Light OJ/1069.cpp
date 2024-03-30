#include<stdio.h>
#include<math.h>

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
		int from,to,sum = 0,enter_exit = 10,door_open_colse = 9;
		scanf("%d%d",&to,&from);
		sum+=enter_exit+door_open_colse; // aita leagbei.
		///lift ashe je smomoy lage
		sum += abs(from-to)<<2;
		//groud ba zero te jete somoylagbe (to-0) == to
		sum += to*4;

		printf("Case %d: %d\n",x,sum);
	}      
  return 0;
  }