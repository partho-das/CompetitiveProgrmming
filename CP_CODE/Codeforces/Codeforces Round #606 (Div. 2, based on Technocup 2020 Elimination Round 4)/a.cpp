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

std::vector<ll> v;
ll maxn = 1e9;
int gen()
{
    for(int i = 1;i<=9;i++)
    {
      ll n = i;
      for(;n<=maxn;)
      {
          v.pb(n);
          n = n*10+i;
      }
    }

    return 0;
}



int main(){

  #ifdef PARTHO
       freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
       freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
       int start_time = clock();
  #endif

       gen();


       
       int test;

       cin >> test;

       while(test--)
       {
          int n;
          cin >> n ;
          int cnt = 0;
          for(int i = 0;i<v.size();i++)
          {
              if(n>=v[i])
              {
               // cout << v[i] << endl;
                cnt++;
              }
          }
         cout << cnt << endl;
       }



      
       

    
  #ifdef PARTHO
       int end_time = clock();
       printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
  #endif
  return 0;
}


