#include <bits/stdc++.h>
using namespace std;


//____________________________________________________________________________________________________________________________________

#define PI  2*acos(0.0)
#define ll  long long
#define pf  printf
#define sf  scanf
#define ff  first
#define ss  second
#define mp  make_pair
#define pb  push_back
#define vi  std::vector<int>
#define pi  pair<int , int>
#define vll vector<long long>
#define pll pair<long long , long long>
#define sc(n)       sf("%d",&n);
#define scf(f)      sf("%f",&f);
#define FOR(i,a,n)  for(int i = a; i < n; i++)
#define TEST(test)  for(int cse = 1; cse <= test; cse++)
//____________________________________________________________________________________________________________________________________

//vi v;
int cnt = 0;
long long prime_factor(ll n){
    ll i;
    for( i = 2;i*i<=n;i++)
    {
      if(n%i == 0)
      { 
        if(i&1) return i;
          while(n%i==0) 
            {
                if((n/i) &1 ) return n/i;
                n = n/i;
            }
      }
    }
    if(n!=1)
      if(n&1) return n;
    
  return 0;

}

int main(){

  #ifdef PARTHO
       freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
       freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
       int start_time = clock();
  #endif

    int test;
    cin >> test;
    TEST(test)
    {

       ll n,ck = 0;
       scanf("%lld",&n);

       if(n&1)
       {
        printf("Case %d: Impossible\n",cse);
         continue;
       }
      else
          ck = prime_factor(n);

       if(!ck)
        printf("Case %d: Impossible\n",cse);
        else printf("Case %d: %lld %lld\n",cse,ck,n/ck);
      
    }

  #ifdef PARTHO
       int end_time = clock();
       printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
  #endif
  return 0;
}


///Before submit=>
///    *check for integer overflow,array bounds
///    *check for n=1
