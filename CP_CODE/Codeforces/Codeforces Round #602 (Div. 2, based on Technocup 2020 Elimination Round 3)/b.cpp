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
 
const int maxn = 1e6;
bool taken[maxn];
int arr[maxn];
 std::vector<int> v,print;
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
            int n;
            int ck = 0;
            sc("%d",&n);
            memset(taken,0,sizeof(int)*(n+6) );
           
            for(int i = 0;i<n;i++)
            {
              sc("%d",&arr[i]);
              taken[arr[i]] = 1;
            }
            for(int i = n;i>=1;i--)
            {
              if(!taken[i])
                v.pb(i);
            }
          
               print.pb(arr[0]);
              int last = arr[0];
              for(int i = 1;i<n;i++)
              {
                if(arr[i]==last)
                {
                  int indx = v.size();
                    if(v[indx-1]>= last)
                    {
                      ck = 1;
                      break;
                    }
                    else
                    {
                      print.pb(v[indx-1]);
                      if(v.size())
                       v.pop_back();
                    }
                 
                }
                else
                {
                  last = arr[i] ;
                  print.pb(last);
                }
              }
              if(!ck)
              { 
                  for(int i = 0;i<print.size();i++)
                  printf("%d ",print[i]);
                  puts("");
              }
              else puts("-1");
            
            v.clear();
            print.clear();
           
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