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
const ll MOD =  1e9 + 7;
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

const int maxn = 5e4 + 100;
int isprime[maxn + 5];
vll primes;

void primesgen(){
	for(ll i = 3; i * i <= maxn; i += 2){
		if(!isprime[i]){
			for(ll j = i * i; j <= maxn; j += i){
				isprime[j] = 1;
			}
		}
	}

	primes.pb(2);
	for(int i = 3; i <= maxn; i += 2){
		if( !isprime[i] ) primes.pb(i);
	}
	//for(auto it : primes) cout << it << endl;

return;
}

ll solve(){
    
    ll n, m;

    scll(n, m);
    ll res = 1;

    if(!n) return 0;
    if(m)
    for(ll i = 0; i < primes.size() && primes[i] * primes[i] <= n; i++){
    	ll cnt = 0;
    	while(n % primes[i] == 0){
    		n /= primes[i];
    		cnt++;
    	}
    	cnt *= m;
    	//cout <<  1 - bigmod(i, cnt + 1) << endl;
    	//cout << cnt << " " << i << " " << endl;
    	
    	res =  (res * (( (1ll - bigmod(primes[i], cnt + 1)) * (bigmod( 1ll - primes[i], (ll)MOD - 2) % MOD) ) % MOD) ) % MOD;
    	//cout <<  primes[i] << " res = " << res << endl;
    }
    if(n > 1){
    	ll cnt = 1 * m;
    //cout << res << " " << ( ( 1 - bigmod(n, cnt + 1) ) *  (bigmod( 1ll - n, (ll)MOD - 2) % MOD) ) << endl;
    	//cout <<  1 - bigmod(n, cnt + 1) << endl;
    	res =  (res * (( ( 1 - bigmod(n, cnt + 1) ) *  (bigmod( 1ll - n, (ll)MOD - 2) % MOD) ) % MOD ) ) % MOD ;

    	//cout <<  bigmod(n, cnt + 1) << endl;
    	//cout <<  (( ( 1 - bigmod(n, cnt + 1) ) *  (bigmod( 1ll - n, (ll)MOD - 2) % MOD) ) % MOD ) << " " << res << endl;
    }
    res = (res + MOD) % MOD;


    return res;
}



int main() {
    #ifdef PARTHO
        freopen("/mnt/Stable/Dropbox/IO/input.txt","r",stdin);
        freopen("/mnt/Stable/Dropbox/IO/output.txt","w",stdout);
        int start_time = clock();
    #endif
    //FastIO;

    int test = 1, tc = 1;

    sc1(test);
    primesgen();
    while(test--){
        printf( "Case %d: %lld\n", tc++, solve());
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