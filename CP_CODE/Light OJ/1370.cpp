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

const int maxn = 2e6;
int t = 1;
bitset<maxn + 5>isprime;

vector<int>rphi(maxn + 1, inf), phi(maxn + 5);

void gen(){
	for(int i = 3; i * i <= maxn; i += 2){
		if(!isprime[i])
		for(int j = i * i; j <= maxn; j += i){
			isprime[j] = 1;
		}
	}
	for(int i = 4; i <= maxn; i += 2){
		isprime[i] = 1;
	}

	for(int i = 1; i <= maxn; i++){
		phi[i] = i;
	}

	int cnt = 0;
	isprime[1] = 1;
	for(int i = 1; i <= maxn; i++){
		if(!isprime[i]){
			if(i >= 1e6)
			cnt++;
			//cout << i << endl;
			for(int j = i; j <= maxn; j += i){
				phi[j] = (phi[j] / i) * (i - 1);
			}
		}
	}
	phi[1] = 0;
	//cout << cnt << endl;

	// for(int i = 1; i <= maxn; i++){
	// 	cout << i << " : " << phi[i] << endl;
	// }
	for(int i = 1; i <= maxn; i++){
		cout << i << " : " << phi[i];
		cout << endl;
		if(!isprime[i]) cout << " (p) " ;
	}

	// for(int i = 0; i <= maxn; i++){
	// 	//cout << i << " : ";

	// 	for(auto it : rphi[i]){
	// 		cout << it << endl ;
	// 	}
	// 	//cout << endl;
	// }

	return;


}


void solve(){
    

    int n;
    sc1(n);

    vi v(n);

    set<int>allphi, unq;
    for(int i = 0; i < n; i++){
    	sc1(v[i]);
    }
    sort(all(v));
    reverse(all(v));
    
    int last = maxn + 1;
    ll res = 0;



    for(int i = 0 ; i < v.size(); i++){
    	//cout << v[i] << " " << last << endl;
    	for(int j = v[i]; j < last; j++){
    			allphi.insert(rphi[j]);
    	}

    	last = v[i];
    	ll now = *allphi.begin();
    	//cout << now << " " << v[i] << endl;
    	res += now;
    	//allphi.erase(now);
    }

    printf("Case %d: %lld Xukha\n", t++, res);

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

    gen();

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