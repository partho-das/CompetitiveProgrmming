#include <bits/stdc++.h>
using namespace std;
 
//____________________________________________________________________________________________________________________________________
#define PI  2*acos(0.0)
#define pf  printf
#define sc  scanf
#define ff  first
#define ss  second
#define pb  push_back
typedef long long ll;
typedef unsigned long long ull;
typedef std::vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define sc1(n)         sc("%d",&n)
#define sc2(n, m)      sc("%d%d", &n, &m)
#define sc3(m, n, o)   sc("%d%d%d", &m, &n, &o)
#define scl(n)         sc("%lld", &n)
#define scll(n, m)     sc("%lld%lld", &n, &m)
#define sclll(n, m, o) sc("%lld%lld%lld", &n, &m, &o)
#define scf(f)         sc("%lf",&f);
#define pn(n)          pf("%d\n", n);
#define FOR(i,a,n)   for( int i = a; i < n; i++)
#define all(x) (x).begin(), (x).end()
#define FastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int MOD =  1e9 + 7;
const long double EPS = 1e-9;
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline double my_sqrt(T n) { double high = n + 5, low = 0, mid, ans; int cnt = 100; while(cnt--) { mid = low + (high - low) / 2; if(mid * mid <= n) ans = mid, low = mid; else high = mid; } return ans; }
template <class T> inline T bigmod(T b, T p){ if(p <= 0 || b == 0) return 1; ll x = b; if(p & 1) return (x * bigmod(b, p - 1)) % MOD; x = bigmod(b, p >> 1); return (x * x) % MOD;}
#ifdef PARTHO
#define dbg(x) cout << __LINE__ << " says: " << #x << " = " << x << "\n"
#else
#define dbg(x)
#endif
//____________________________________________________________________________________________________________________________________


int tc = 1;

bool checkVowel(char c)
{
 if(c=='A'||c=='I'||c=='O'||c=='U'||c=='E')
 {
  return 1;
 }
 return 0;
}
void solve()
{
  string s;
  cin>>s;
  int a[26]={0};
  int Ssize=s.size();

  printf("Case #%d: ", tc++);
  if(Ssize==1)
  {
   printf("%d\n", 0);
   return;
  }
  else{
   int check=0;
   for (int i = 0; i < Ssize-1; i++)
   {
    if (s[i]!=s[i+1])
    {
     check=1;
     break;
    }
   }
   if(check==0)
   {
    printf("%d\n",0);
    return;
   }
  }
  int v=0,c=0;
  for(int i=0;i<Ssize;i++)
  {
   a[s[i]-'A']++;
   if(checkVowel(s[i]))
   {
    v++;
   }
   else{
    c++;
   }
  }

  if(v==0&&c>0)
  {
   printf("%d\n", c);
   return;
  }
  else if(v>0&&c==0)
  {
   printf("%d\n", v);
   return;
  }
  int res=INT_MAX;
  for (int i = 0; i < 26; ++i)
  {
   if(a[i]>0)
   {
    int sum=0;
    for(int j=0;j<26;j++)
    {
     if(i!=j&&a[j]>0)
     {
      if(checkVowel(char(i+'A'))==1&&checkVowel(char(j+'A'))==1)
      {
       sum+=(2*a[j]);
      }
      else if(checkVowel(char(i+'A'))==1&&checkVowel(char(j+'A'))==0)
      {
       sum+=a[j];
      }
      else if(checkVowel(char(i+'A'))==0&&checkVowel(char(j+'A'))==0)
      {
       sum+=(2*a[j]);
      }
      else if(checkVowel(char(i+'A'))==0&&checkVowel(char(j+'A'))==1)
      {
       sum+=a[j];
      }
     }
    }
    res=min(res,sum);
   }
  }
 
  printf("%d\n", res);
}


int main() {
    #ifdef PARTHO
        freopen("/mnt/Stable/Dropbox/IO/input.txt","r",stdin);
        freopen("/mnt/Stable/Dropbox/IO/output.txt","w",stdout);
        int start_time = clock();
    #endif
    //FastIO;

    int test = 1;

    sc1(test);

    while(test--){
        solve();
    }
    #ifdef PARTHO
        int end_time = clock();
        printf("Time = %.4f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif

    return 0;
}
///Before submit=>
///    *check for integer overflow,array bounds
///    *check for n=1