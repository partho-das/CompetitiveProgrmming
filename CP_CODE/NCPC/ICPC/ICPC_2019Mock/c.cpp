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
     
     long long test;
     cin >> test;
    TEST(test)
     {
        std::map<string, int> mp;
       ll n;
       cin >> n;
      string str,stor;
      int mx = 0;
      FOR(i,n)
      {
        cin >> str;
        if(mp.find(str) !=mp.end())
        {
          mp[str]++;
          if(mx<mp[str])
          {
            mx = mp[str];
            stor= str;   
          }
        }
        else
        {
            mp[str] = 1;
          if(mx<mp[str])
          {
            mx = mp[str];
            stor= str;
          }
        }
      } 

      printf("Case %d: ",c);
      cout << stor << endl;
       
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
