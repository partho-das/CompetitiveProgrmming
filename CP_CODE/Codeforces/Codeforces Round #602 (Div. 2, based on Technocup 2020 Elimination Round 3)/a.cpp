#include <bits/stdc++.h>
using namespace std;

//macros
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

       int test;
       cin >> test;

       while(test--)
       {
          int a,b;

          int n;
          cin >> n;

          int mx = -1,mn =1e9+6;

          for(int i= 0;i<n;i++)
          {
            sc("%d%d",&a,&b);
            mx = max(a,mx);
            mn = min(mn,b);
          } 
          if(n==1) mx = mn;
          cout << max(0,(mx-mn)) << endl;
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
