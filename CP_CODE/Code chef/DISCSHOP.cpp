#include <bits/stdc++.h>
using namespace std;

//macros_______________________________________________________________________________________________________________________________
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
#define FOR(i,a,n)    for(int i = a; i < n; i++)
#define TEST(test)  for(int c = 1; c <= test; c++)
//____________________________________________________________________________________________________________________________________

int calculate(int n){

  int agent = 1,mn = n;
  int num,last = 0;

  int sum = 0;
  while(n)
  {
      num = n%10;
      n = n/10;
      sum = n*agent+last;
      mn = min(mn,sum);
      last += num*agent;
      agent*=10;

  }


  return mn;
}

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
          int n ;
          sc("%d",&n);

          cout << calculate(n) << endl;


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
