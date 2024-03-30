#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e7+7;
#define ll long long

ll hx[10020];
ll base[6];
ll fn( int n ) {
    if( n <= 5 ) return base[n];
    if(~hx[n]) return hx[n]; 
    return hx[n] = ( fn(n-1) + fn(n-2)  + fn(n-3) + fn(n-4) + fn(n-5) + fn(n-6) )  % MOD;
}

int main()
{
	#ifdef PARTHO
		freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
    	freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
    	int start_time = clock();
    #endif

    int n, caseno = 0, cases;
    scanf("%d", &cases);
    while( cases-- ) {
        for(int i = 0; i < 6; i++) scanf("%lld", &base[i]), base[i] %= MOD;

        scanf("%d", &n);
  		memset(hx,-1,sizeof hx);
        printf("Case %d: %lld\n", ++caseno, fn(n));
    }

	#ifdef PARTHO
		int end_time = clock();
		printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif

	return 0;
}
