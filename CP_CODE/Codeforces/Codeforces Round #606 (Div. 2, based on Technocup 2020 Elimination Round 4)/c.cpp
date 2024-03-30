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
          string str;

          cin >> str;
          int cnt = 0;
          std::vector<int> v;
          for(int i = 0;i<str.size();i++)
          {
              if(i+4<str.size())
              {
                if(str[i] == 't' && str[i+1] == 'w' 
                  && str[i+2]=='o' && str[i+3] == 'n' && str[i+4] == 'e')
                {
                  cnt++;
                  v.pb(i+2+1);
                  str[i+2+1] = 'w';
                  i+=4;
                  continue;
                }
              }
              if(i+2<str.size())
              if(str[i]=='o' && str[i+1] == 'n' && str[i+2] == 'e')
              {
                cnt++;
                v.pb(i+2);
                str[i+1] = 'o';
              }
              else if(str[i]=='t' && str[i+1] == 'w' && str[i+2] == 'o')
              {
                cnt++;
                str[i+1] = 't';
                v.pb(i+2);
              }
          }
          cout << cnt << endl;

          if(cnt)
          {
            for(auto it : v)
              cout << it << " ";
            
          }
          cout << endl;
       }
    
  #ifdef PARTHO
       int end_time = clock();
       printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
  #endif
  return 0;
}


