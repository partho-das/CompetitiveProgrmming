#include <bits/stdc++.h>
using namespace std;

//____________________________________________________________________________________________________________________________________

#define PI  2*acos(0.0)
#define pf  printf
#define sf  scan
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
#define sc(n)       scanf("%d",&n);
#define scf(f)      scanf("%f",&f);
#define FOR(i,a,n)  for(int i = a; i < n; i++)
#define TEST(test)  for(int cse = 1; cse <= test; cse++)
#define all(x) (x).begin(), (x).end()
#define fap(x) cout << __LINE__ << " says: " << #x << " = " << x << "\n"
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define mst(arr, n) memset(arr, n, sizeof arr)
const ll INF = 2000000000000000000LL;
const int inf = 0x3f3f3f3f;
const long double EPS = 1e-9;
const ll MOD = 1e9 + 7;
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
//____________________________________________________________________________________________________________________________________

struct cont
{
   int pos;
   int cmd;
   char ch;

   cont() {};
   cont(int _cmd, int _pos, char _ch){
      pos = _pos;
      cmd = _cmd;
      ch = _ch;
   }
};
int dp[100][100], n, m;
string stra, strb;

int f(int i, int j)
{
   if(i == n)
   {
     // cout << i << " " << j << endl;
      dp[i][j] = m - j;
      return  dp[i][j];
   }
   if(j == m) return dp[i][j] = n - i;
   if(dp[i][j] != -1) return dp[i][j];
   
   int ans = inf;
   if(stra[i] == strb[j]) ans = f(i + 1, j + 1);
   else
   {
     ans = min(1 + f(i + 1, j + 1), 1 + f(i, j + 1)); // replace //insert
     ans = min(1 + f(i + 1, j), ans); // delete
   }
   return dp[i][j] = ans;
}

std::vector<cont> v;
void path(int i, int j, int rpos)
{
   string str;
   cont var;
   if(i == n)
   {
    //cout << " " << " " << " hi" << endl;
      for(; j < m; j++)
      {   
         var = {2,rpos, strb[j]};
         v.pb(var);
      }
      return;
   }
   if(j == m)
   {
      for(; i < n; i++)
      {
         var = {3,rpos++, stra[i]};
         v.pb(var);
         str.clear();
      }
      return;
   }


   if(stra[i] == strb[j]) path(i + 1, j + 1, rpos + 1);
   else
   {
      int a = dp[i + 1][j + 1], b = dp[i][ j + 1 ], c = dp[i + 1][j];
      //cout << i << " " << j << endl;
      // fap(a);
      // fap(b);
      // fap(c);

      if(a <= b && a <= c) 
      {   
         var = {1,rpos, stra[i]};
         v.pb(var);
         path(i + 1, j + 1, rpos + 1);
      }
      else if(b <= a && b <= c)
      {
        //cout << "0k" << strb[j]<< endl;
         var = {2,rpos, strb[j]};
         v.pb(var);
         path(i, j + 1, rpos); 
      } 
      else
      {
         var = {3,rpos, stra[i]};
         v.pb(var);
         path(i + 1, j, rpos + 1);
      }
   }

   return;



}


int main()
{
#ifdef PARTHO
    freopen("/mnt/Stable/Dropbox/IO/input.txt","r",stdin);
    freopen("/mnt/Stable/Dropbox/IO/output.txt","w",stdout);
   int start_time = clock();
#endif
//FastIO


int ck = 0;
while(cin >> strb >> stra)
{
   if(stra[0] == '#' || strb[0] == '#') break;
   if(ck == 1) cout << endl;
   memset(dp, -1, sizeof dp);
   n = stra.size(), m = strb.size();
   for(int i = 0; i <= m; i++) dp[n][i] = inf;
   for(int i = 0; i <= n; i++) dp[i][m] = inf;
   f(0,0);
   path(0, 0, 1);


// for(int i = 0; i <= stra.size(); i++)
// {
//    for(int j = 0; j <= strb.size(); j++)
//       cout << dp[i][j] << " ";
//    cout << endl;
// }


  for(int i = 0; i < v.size(); i++)
      if(v[i].cmd == 1)
      {
         printf("C%c", v[i].ch );
         if(v[i].pos <= 9) cout << "0" << v[i].pos;
         else cout << v[i].pos;
      }
      else if(v[i].cmd == 2)
      {
         printf("D%c", v[i].ch);
         if(v[i].pos <= 9) cout << "0" << v[i].pos;
         else cout << v[i].pos;
      }
      else
      {  
       printf("I%c",v[i].ch );
       if(v[i].pos <= 9) cout << "0" << v[i].pos;
       else cout << v[i].pos;
      }
      cout << 'E' << endl;

      v.clear();
      //ck = 1;
}





// #ifdef PARTHO
//    int end_time = clock();
//    printf("Time = %.4f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
// #endif

    return 0;
}
///Before submit=>
///    *check for integer overflow,array bounds
///    *check for n=1



