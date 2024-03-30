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
 
       int test;
 
       cin >> test;
       while(test--)
       {
          int n,m;
          int arr[1022];
          sc("%d%d",&n,&m);
          pair<int,int> mx {1e9,0},smx = {1e9-1,0};
          ll sum  = 0;
          for(int i  = 1;i<=n;i++)
          {
            sc("%d",&arr[i]);
            sum+=arr[i];
 
            if(mx.ff>=arr[i])
            {
              smx.ff = mx.ff;
              smx.ss = mx.ss;
              mx.ff = arr[i];
              mx.ss = i;
            }
            else if(smx.ff>=arr[i])
            {
              smx.ff = arr[i];
              smx.ss = i;
            }
 
          }
          if(m<n || n <=2)
          {
            printf("-1\n");
          }
          else
          {
            sum*= 2;
            int need = m-n;
  
            sum+= (need*(mx.ff+smx.ff));
            cout << sum << endl;
            for(int i  = 1;i<=n;i++)
            {
              int first = i,second = i+1;
              if(second>n) second = 1;
              if(first>n) first = 1;
 
              cout << first << " " << second << endl;
 
            }
 
            for(int i = 0;i<need;i++)
            {
              cout << mx.ss << " " << smx.ss << endl;
            }
 
          }
 
 
 
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