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
unordered_map<string,int> mep;

int cnt = 0;
string gen(map<string,int> &mep,string str,int x)
{
  for(int i = 0;i<4;i++)
  {
    char ch = str[i];
    for(int j = 0;j<10;j++)
    {
        str[i] = '0'+j;
        if(mep.find(str) == mep.end())
        {
            cnt++;
            mep[str] = x;
            return str;
        }
        str[i] = ch;
    }
  }

  return str;
  
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

          int n;
          string str;
          map<string,int> mep;

          std::vector<string> v;
          int cnt = 0;
          cin >> n;

          for(int i = 0;i<n;i++)
          {
            cin >> str;
             v.pb(str);
             mep[str] = i;
          }
          std::vector<string> pv;
          for(int i = 0;i<n;i++)
          {
              if(mep[v[i]] != -1)
              {
                pv.pb(v[i]);
                mep[v[i]] = -1;
              }
              else
              {
                pv.pb(gen(mep,v[i],i));
                cnt++;
              }
          }


          cout << cnt << endl;

          for(auto it : pv)
            cout << it << endl;

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
