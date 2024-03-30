#include <bits/stdc++.h>
using namespace std;
 
//____________________________________________________________________________________________________________________________________
mt19937 rng(114514);
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

const int maxn = 2e5, maxn2 = 1 << 15;
string loved_currency[maxn];
int dp[maxn2 + 5];
char S[65];
vi on_position;

void solve(){
    
    int n, m, p, casecnt = 5;

    sc3(n, m, p);

    FOR(i, 0, n){
        scanf("%s", S);
        loved_currency[i] = S;
    }

    ll mx = -1, mxvalue = -1;
    string str(m, '0');
    while(casecnt--){
        
        on_position.clear();
        memset(dp, 0, sizeof dp);

        int indx = (rng())% n;

        for(int i = 0; i < m; i++){
            if(loved_currency[indx][i] == '1'){
                on_position.pb(i);
            }
        }
        p = on_position.size();
        for(int i = 0; i < n; i++){
            ll mask = 0;
            for(int j = 0; j < p; j++){
                if(loved_currency[i][ on_position[j]] == '1'){
                    
                    mask |= (1 << j);
                }
            }
            dp[mask]++;
        }

        for(int i = 0; i < p; i++){
            for(int mask = 0; mask < (1 << p); mask++){
                if( !(mask & (1 << i)) ){
                     dp[mask] += dp[mask | (1 << i)];
                }
            }
        }
        for(int i = 0; i < (1 << p); i++){
            if(__builtin_popcount(i) > mxvalue && dp[i] >= ((n + 1) / 2)){
                mxvalue = __builtin_popcount(i);
                mx = i;
                FOR(l, 0, m) S[l] = '0';
                for(int i = 0; i < p; i++){
                    if(mx & (1 << i)) {
                        S[ on_position[i] ] = '1';
                    }
                }
            }
        }

    }
        puts(S);
    
    


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

    //sc1(test);

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