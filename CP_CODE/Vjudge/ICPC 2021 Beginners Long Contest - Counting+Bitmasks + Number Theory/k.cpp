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

std::vector<pii> pos(10000);
std::vector<pll> v;
int nod(ll n){
	int cnt = 1;
	//ll cnt = 0;
	for(int i = 2; i * i <= n; i++){
		if(n % i == 0){
			int add = 1;
			while(n % i == 0){
				add += 2;
				n /= i;
			}
			cnt *= add;
		}
	}
	if(n > 1){
		cnt *= 3;
	}
	return cnt;
}
void gen(){

	for(ll i = 1; i * i <= 1e10; i++){
		ll d = nod(i);
		v.pb({d, i * i});
		if(i <= 10000){
			pos[i].ff = inf;
			pos[i].ss = -inf;
		}

	}

	sort(all(v));


	for(int i = 0; i < v.size(); i++){
		pos[v[i].ff].ff = min(pos[v[i].ff].ff, i);
		pos[v[i].ff].ss = max(pos[v[i].ff].ss, i);
	}

	return;
}
void solve(){
    
   	ll k, a, b;

   	sclll(k, a, b);
   	if(pos[k].ff == inf){
   		puts("0");
   		return;
   	}

   	ll l = pos[k].ff, r = pos[k].ss, mid;
   	ll res = 0;
   	int findx = -1, lindx = -1;

   	while(l <= r){
   		mid = l + (r - l) / 2;

   		if(v[mid].ss >= a) r = mid - 1, findx = mid;
   		else if(v[mid].ss < a) l = mid + 1, findx = mid + 1;
   	}
   	l = pos[k].ff, r = pos[k].ss, mid;
	while(l <= r){
		mid = l + (r - l) / 2;
		if(v[mid].ss > b) {
			r = mid - 1,  lindx = mid;
		}
		else if(v[mid].ss <= b) l = mid + 1, lindx = mid + 1;
   	}

   printf("%d\n", lindx - findx);

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