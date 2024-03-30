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


      int n;

      string str;
      cin >> n;
      cin >> str;
      std::vector<int> v;
      
      if(count(all(str),'B')&1 && count(all(str),'W') & 1)
      {
        cout << -1 << endl;
        return 0;
      }

      if(count(all(str),'W') & 1)
      {
        for(char &c : str)
          if(c == 'W')
          c = 'B';
          else c = 'W';
      }
      vi res;

      for(int i = 0;i+1<(int)str.size();i++)
      {
          if(str[i] == 'W')
          {
            res.pb(i+1);
            if(str[i+1] == 'W')str[i]= str[i+1] = 'B',i++;
            else swap(str[i],str[i+1]);
          }
      }

      cout << res.size() << endl;
      for(int it : res) cout << it << " " ;
        cout << endl;




    
  #ifdef PARTHO
       int end_time = clock();
       printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
  #endif
  return 0;
}


