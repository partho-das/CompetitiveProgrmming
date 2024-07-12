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

vector<pii>res;
bool is_res(string str, int n){
	// str = "10101";
	stringstream ss;
	ss << str;
	int val;
	ss >> val;
	int n_digit = log10(n) + 1;
	for(int a = 1; a <= 10000; a++){
		int a_digit = n_digit * a;
		int b = a_digit - str.size();
		// cout << a_digit << " " << b << " an " << a * n << endl;
		if(b >= 1){
			if( b < a * n && b <= 10000 && (a * n - b) == val){
				res.pb({a, b});
			}
		}
	}
	return 0;
}
void solve(){

	int n;
	sc1(n);

	string str = to_string(n);

	str = str + str + str + str + str + str + str;
	int cnt = 0;

	for(int i = 1; i <= 7; i++){
		cnt += is_res(str.substr(0, i), n);
	}

	cout << res.size() << endl;
	for(auto it : res){
		cout << it.ff << " " << it.ss << endl;
	}
	res.clear();
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

