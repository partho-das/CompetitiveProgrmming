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
template <class T> inline double my_sqrt(T n) { double high = n, low = 0, mid, ans; int cnt = 100; while(cnt--) { mid = low + (high - low) / 2; if(mid * mid <= n) ans = mid, low = mid; else high = mid; } return ans; }
template <class T> inline T bigmod(T b, T p){ if(p <= 0 || b == 0) return 1; if(p & 1) return (b * bigmod(b, p - 1)) % MOD; ll x = bigmod(b, p >> 1); return (x * x) % MOD;}
#ifdef PARTHO
#define dbg(x) cout << __LINE__ << " says: " << #x << " = " << x << "\n"
#else
#define dbg(x)
#endif
//____________________________________________________________________________________________________________________________________

int maxn = 100;

vector<string>parches(20), nearby(105);
char str[10];
int dp[105][ (1 << 15) + 5], checker[16][105]; 
int n, m;

int f(int pos, int mask){
    if(mask == (1 << n) - 1) return 1;
    if(pos >= m){
        return 0;
    }

    int &ret = dp[pos][mask];
    if(ret != -1) return ret;

    ret = 0;

    for(int i = 0; i < n; i++){
        if( (mask & (1 << i))) continue;
        if(checker[i][pos]){
            ret = (ret + f(pos + 1, mask | (1 << i))) % MOD;
        }
    }
    ret = (ret + f(pos + 1, mask)) % MOD;
    return ret;
}


void solve(){

    sc1(n);

    getchar();
    for(int i = 0; i < n; i++){
        scanf("%s", str);
        parches[i] = str;
    }
    sc1(m);

    for(int i = 0; i < m; i++){
        scanf("%s", str);
        nearby[i] = str;
    }
    for(int i = 0; i < n; i++){
        for(int k = 0; k < m; k++){
            int ck = 1;
            for(int j = 0; j < 4; j++){
                if(parches[i][j] != nearby[k][j] && parches[i][j] != '?'){
                    ck = 0;
                    break;
                }
            }
            checker[i][k] = ck;
        }
    }
    memset(dp, -1, sizeof dp);
    int res = f(0, 0);

    printf("%d\n", res);
}

int main() {
    #ifdef PARTHO
        freopen("/home/partho/Desktop/Code/IO/input.txt","r",stdin);
        freopen("/home/partho/Desktop/Code/IO/output.txt","w",stdout);
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
