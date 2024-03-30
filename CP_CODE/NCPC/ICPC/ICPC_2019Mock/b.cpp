#include <bits/stdc++.h>
using namespace std;


#define PI  2*acos(0.0)
#define ll  long long
#define pf  printf
#define sc  scanf
#define ff  first
#define ss  second
#define mp  make_pair
#define pb  push_back
#define vi  std::vector<int>
#define pi  pair<int , int>
#define vll vector<long long>
#define pll pair<long long , long long>
#define FOR(i,n)    for(int i = 0; i < n; i++)
#define TEST(test)  for(int c = 1; c <= test; c++)



int main(){

   #ifdef PARTHO
       freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
       freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
       int start_time = clock();
   #endif
       ll test,n,m,summ,sumn;

      

      cin >> test;

      TEST(test)
      {
          sumn = summ = 0;
          ll first,second;
          cin >> n >> m;
          //cout << n << m << endl;
          for(long long i = 0;i<n;i++)
          {
            sc("%lld",&first);
            sumn+=first;
          }
           for(long long i = 0;i<m;i++)
          {
            sc("%lld",&second);
            sumn+=second;
          }

          first = max(first,second);
          sumn-=first;

          printf("Case %d: %lld\n",c,sumn);
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
