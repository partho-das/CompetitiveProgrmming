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

ll t = 1, n, dp[20][20][2][2][2];
char str[20];

ll f(int i, int j, int azero, int psmall, int fb){
	if(i > j){
		if(azero) return 0;
		if(psmall) return 1;
		if(fb) return 0;
		return 1;
	}

	ll &ret = dp[i][j][azero][psmall][fb];
	if(ret != -1) return ret;

	ret = 0;

	int lim = 9;
	if(!psmall) lim = str[i] - '0';

	for(int l = 0; l <= lim; l++){
		if(l == 0){
			if(azero) ret += f(i + 1, j, azero, 1, 0);
			else{
				ret += f(i + 1, j - 1, azero, psmall | l < lim , l > (str[j] - '0') | (fb && (l ==  (str[j] - '0')) ));
			}
		}
		else{
			ret += f(i + 1, j - 1, 0, psmall | l < lim,  l > (str[j] - '0') | (fb && (l ==  (str[j] - '0')) ));
		}
	}

	return ret;

}
void solve(){


	ll a, b;
	scll(a, b);

	if(a > b) swap(a, b);
	sprintf(str,"%lld", b);

	memset(dp, -1, sizeof dp);
	n = strlen(str);
	ll res = f(0, n - 1, 1, 0, 0);

	if(a){
	
		sprintf(str,"%lld", a - 1);
		memset(dp, -1, sizeof dp);

		n = strlen(str);
		res = res - f(0, n - 1, 1, 0, 0);
	}

	if(a == 0) res++;
	printf("Case %lld: %lld\n", t++, res);

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
