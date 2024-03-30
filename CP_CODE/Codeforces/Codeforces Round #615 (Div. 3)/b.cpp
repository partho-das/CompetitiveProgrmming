#include <bits/stdc++.h>
using namespace std;
 
 
//____________________________________________________________________________________________________________________________________
 
#define PI  2*acos(0.0)
#define pf  printf
#define sf  scanf
#define ff  first
#define ss  second
#define mp  make_pair
#define pb  push_back
typedef long long ll;
typedef unsigned long long ull;
typedef std::vector<int> vi;
typedef vector<long long> vll ;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define sc(n)       sf("%d",&n);
#define scf(f)      sf("%f",&f);
#define FOR(i,a,n)  for(int i = a; i < n; i++)
#define TEST(test)  for(int cse = 1; cse <= test; cse++)
 
#define all(x) (x).begin(), (x).end()
#define fap(x) cout << __LINE__ << " says: " << #x << " = " << x << "\n"
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0); 
const ll INF = 2000000000000000000LL;
const int inf = 0x3f3f3f3f;
const long double EPS = 1e-9;
//____________________________________________________________________________________________________________________________________
 
 
 
 
int main(){
 
  #ifdef PARTHO
       freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
       freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
       int start_time = clock();
  #endif
   FastIO;


   int test;

   cin >> test;

   while(test--)
   {
      int n,x,y,ck = 0;


      std::vector< pair<int,int> > v;
      cin >> n;
      for(int i = 0 ; i < n;i++)
      {
        cin >> x >> y;
        v.pb({x,y});
      }

      sort(all(v));


      // for(auto it : v)
      //   cout << it.ff << " " << it.ss << endl;


      x = 0, y = 0;
      string str;
      for(int i = 0; i < v.size() ;i++)
      {
        x = v[i].ff - x, y = v[i].ss - y;

        if(x<0 || y < 0) 
          {
            ck = 1;
            break; 
          }

          while(x--)
            str+='R';
          while(y--)
            str+='U';
          x = v[i].ff;
          y = v[i].ss;
    }


      if(ck) cout << "NO" << endl;
      else 
        cout << "YES" << endl << str << endl;
  }



 
  
  #ifdef PARTHO
       int end_time = clock();
       printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
  #endif
  return 0;
}