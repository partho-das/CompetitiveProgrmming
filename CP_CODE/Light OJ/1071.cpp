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
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int MOD =  1e9 + 7;
const long double EPS = 1e-9;
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline double my_sqrt(T n) { double high = n + 5, low = 0, mid, ans; int cnt = 100; while(cnt--) { mid = low + (high - low) / 2; if(mid * mid <= n) ans = mid, low = mid; else high = mid; } return ans; }
template <class T> inline T bigmod(T b, T p){ if(p <= 0 || b == 0) return 1; ll x = b; if(p & 1) return (x * bigmod(b, p - 1)) % MOD; x = bigmod(b, p >> 1); return (x * x) % MOD;}
template <class T> inline string to_string(const pair<T,T> &p) {
    return "{" + to_string(p.first) + "," + to_string(p.second) + "}";  
}
#ifdef PARTHO
#define dbg(x) cout << __LINE__ << " says: " << #x << " = " << x << "\n"
#else
#define dbg(x)
#endif
//____________________________________________________________________________________________________________________________________

const int maxn = 100;
int n, m, dp[2 * maxn + 5][maxn + 5][maxn + 5], grid[maxn + 5][maxn + 5], t = 1;

int f(int move, int r1, int r2){

    int c1 = move - r1, c2 = move - r2;

    if( r1 == n - 1 && c1 == m - 1 && r1 == r2 && c1 == c2) return grid[r1][c1];
    if(r1 >= n || r2 >= n || c1 >= m || c2 >= m) return 0;
    if( r1 == r2 && c1 == c2) return 0;

    int &ret = dp[move][r1][r2];
    if(ret != -1) return ret;
    ret = 0;
    ret = max(ret, f(move + 1, r1, r2) + grid[r1][c1] + grid[r2][c2]);
    ret = max(ret, f(move + 1, r1, r2 + 1) + grid[r1][c1] + grid[r2][c2]);
    ret = max(ret, f(move + 1, r1 + 1, r2) + grid[r1][c1] + grid[r2][c2]);
    ret = max(ret, f(move + 1, r1 + 1, r2 + 1) + grid[r1][c1] + grid[r2][c2]);
    return ret;
}
void solve(){
    
   
    sc2(n, m);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            sc1(grid[i][j]);
        }
    }

    memset(dp, -1, sizeof dp);
    printf("Case %d: %d\n", t++, f(1, 0, 1) + grid[0][0]);



    return;
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