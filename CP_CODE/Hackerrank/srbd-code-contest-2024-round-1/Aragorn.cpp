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

const int maxn = 1e2;
ll n;
ll dp[maxn + 5][maxn + 5][maxn + 5], k, tc = 1;
vector<ll>v(105);

ll f(int pos, int rem, int valrem){
	if(pos >= n){
		// cout << " " << pos << " " << valrem <<  endl;
		return (rem == 0 && valrem == 0);
	}
	ll &ret = dp[pos][rem][valrem];

	if(ret != -1) return ret;
	ret = 0;
	ll remval = (((rem + (v[pos] % k) ) % k) + k + k) % k;
	// cout << remval << endl;
	ll a = f(pos + 1, rem, valrem);
	ll b = f(pos + 1, remval, valrem - 1);

	// cout << pos << " " << a << " " << b << endl;

	return ret = (a + b) % MOD;
}


void solve(){
    scl(n);

    for(int i = 0; i < n; i++){
    	scl(v[i]);
    }

    ll res = 0;
    for(int i = 1; i <= n; i++){
    	k = i;
    	for(int x = 0; x <= n + 2; x++){
    		for(int y = 0; y <= k + 2; y++){
    			for(int z = 0; z <= k + 2; z++){
    				dp[x][y][z] = -1;
    			}
    		}
    	}
    	res = (res + f(0, 0, k)) % MOD;
    	// break;
    }
   	printf("Case %lld: %lld\n", tc++, res);
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


