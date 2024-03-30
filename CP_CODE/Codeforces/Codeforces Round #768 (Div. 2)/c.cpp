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
const int maxn = 1 << 16 + 5;
int used[maxn + 5];
void solve(){
    
    int n, k;
    sc2(n, k);

    if(n == 4 && k == 3){
    	puts("-1");
    	return;
    }

    for(int i = 0; i < maxn; i++){
    	used[i] = 0;
    }

   	vector<pii>res;

   	if(k != n - 1){
    	int left = n / 2 - 1;
   		

   		res.pb({k , n - 1});
   		used[n - 1] = 1;
   		used[k] = 1;

   		for(int i = n - 2; i >= 0 && left; i--){
   			int a = i, b = (n - 1) ^ i;
   			if(used[b]) b = 0;
   			else if(used[a]) a = 0;
   			if(a > b) swap(a, b);

   			res.pb({a, b});
   			used[a] = 1;
   			used[b] = 1;
   			left--;
   		}
   	}
   	else{
   		res.pb({n - 2, n - 1});
   		res.pb({1, n - 3});
   		res.pb({0, 2});
   		used[1] = 1;
   		used[n - 1] = 1;
   		used[n - 2] = 1;
   		used[n - 3] = 1;

   		int left = n / 2 - 3;

   		for(int i = n - 4; i >= 3 && left; i--){
   			int a = i, b = (n - 1) ^ i;
   			res.pb({a, b});
   			left--;
   		}


   	}
   	ll sum = 0;
   	for(auto it :res){
   		printf("%d %d\n", it.ff, it.ss);
   		sum += it.ff & it.ss;
   	}
   	//cout <<sum << endl;


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