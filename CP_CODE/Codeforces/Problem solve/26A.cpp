//https://codeforces.com/problemset/problem/26/A
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


bool prime[3020];

bool primeck(int n)
{
    if(n==1 || n == 0) return 0;
  for(int i = 2;i<n;i++)
    if(n%i == 0) return 0;
  return 1;
}
void prime_gen(int n = 3000)
{
    FOR(i,n) prime[i] = primeck(i);
}

int main(){

   #ifdef PARTHO
       freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
       freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
       int start_time = clock();
   #endif

  prime_gen();
  // for(int i = 0;i<=3000;i++)
  // {
  //   if(prime[i]) cout << i << endl;
  // }
   
   int n;

   cin >> n;
  int mxnt = 0;
   for(int i = 1;i<=n;i++)    
      {
          int cnt = 0;
          for(int j  = 1;j<=i;j++)
          {
              if(i%j==0 && prime[j])
                cnt++;
          }
          if(cnt==2)
           mxnt++;
      }

      cout << mxnt << endl;

  #ifdef PARTHO
       int end_time = clock();
       printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif
    return 0;
}


///Before submit=>
///    *check for integer overflow,array bounds
///    *check for n=1
