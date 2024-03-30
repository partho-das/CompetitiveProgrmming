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
#define FastIO ios::sync_w*ith_stdio(false); cin.tie(0); cout.tie(0);
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

map<int, pii>freq;
void solve(){
 
	int n;
	sc1(n);

	vi v(n);
	freq.clear();
	for(int i = 0; i < n; i++){
		int value;
		sc1(value);
		while( !(value & 1)){
			value = value >> 1;
		}
		//cout << value << endl;
		if(freq.find(value) == freq.end()){
			freq[value] = {1, 0};		
		}
		else freq[value].ff++;
	}

	for(int i = 0; i < n; i++){
		int value;
		sc1(value);
		while(value && (freq.find(value) == freq.end())){
			value = value >> 1;
		}
		if(value){
			freq[value].ss++;
		}
	}
	int ck = 1;
	for(auto it = freq.rbegin(); it != freq.rend(); it++){
		//cout << it->ff << " " << it->ss.ff << " " << it->ss.ss << endl;
		if(it->ss.ff <= it->ss.ss){
			int agent = it->ff, add = it->ss.ss - it->ss.ff;
			agent /= 2;
			while(agent && (freq.find(agent) == freq.end())){
				agent = agent >> 1;
			}
			//cout << agent << endl;
			if(agent){
				freq[agent].ss += add;
			}
		}
		else{
			ck = 0;
			break;
		}
	}

	puts(ck ? "YES" : "NO");


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
///Before subm*it=>
///    *check for integer overflow,array bounds
///    *check for n=1
