#include <bits/stdc++.h>
#include <stdio.h>

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
const int inf = 1e9;
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

const int maxn = 2e5;
int dp[maxn + 5], k, n, m;
string str;

int f(int pos){
	if(pos >= n){
		return 0;
	}

	int &ret = dp[pos];
	if(ret != -1) return ret;
	ret = inf;

	int add = 0;
	if(str[pos] == 'W'){
		if(str[pos + 1] != 'C') ret = f(pos + 1) + 1;
	}
	else{
		for(int i = 1; i <= m && pos + i <= n; i++){
			if(pos + i == n) {
				ret = 0;
				break;
			}
			if(str[pos + i] != 'C') ret = min(ret, f(pos + i));
		}

	}
	return ret;
}

void solve(){
	sc3(n, m, k);

	for(int i = 0; i <= n + 2; i++){
		dp[i] = -1;
	}
	cin >> str;

	int min_swim = inf;

	for(int i = 0; i < m && i <= n; i++){
		if(i == n){
			min_swim = 0;
			break;
		}
		if(str[i] != 'C')
			min_swim = min(min_swim, f(i));
	}

	if(min_swim <= k) puts("YES");
	else puts("NO");

	return;
}



int main() {
   
    //FastIO;
     #ifdef PARTHO
        freopen("C:\\Users\\parth\\Desktop\\IO\\input.txt","r",stdin);
        freopen("C:\\Users\\parth\\Desktop\\IO\\output.txt","w",stdout);
        int start_time = clock();
    #endif

    int test = 1;

    sc1(test);


    while(test--){
        solve();
    }
    // puts("HI");

    return 0;
}
///Before submit=>
///    *check for integer overflow,array bounds
///    *check for n=1

