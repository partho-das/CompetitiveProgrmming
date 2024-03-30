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

void solve(){
    
    int  n, m;

    sc2(n, m);


    vi a(n + m), b(m), spcal;
    set<int> au;
    FOR(i, 0, n) {
    	sc1(a[i]);
    	au.insert(a[i]);
    }
    int indx = n;
    FOR(i, 0, m) {
    	sc1(b[i]);
    	if(au.find(b[i]) != au.end()) spcal.pb(b[i]);
    	a[indx++] = (b[i]);
    }


    sort(all(a));

    int x = 0, y;
   	while( x < m + n && a[x] < 0)x++;
   	y = x;
   	x--;

   	int r = -inf, cnt = 0, l, res = 0;
   	while(x >= 0){
   		//if(x < 0 || x >= m + n) cout << "HI" << endl;
   		if(au.find( a[x] ) == au.end()){
   		//cout << x << endl;
   			if(!cnt){
   				x--;
   				continue;
   			}
   			else{
   				r = a[x], l = r - (cnt - 1);
   				int add = upper_bound(all(spcal), l - 1) - spcal.begin();
   				int high = upper_bound(all(b), r) - b.begin(), low = lower_bound(all(b), l) - b.begin(); 
   				add += high - low;
   				res = max(res, add);


   				l = a[x], r = l + cnt - 1;
   				add = upper_bound(all(spcal), l - 1) - spcal.begin();
   			//cout << add << endl;
   				high = upper_bound(all(b), r) - b.begin(), low = lower_bound(all(b), l) - b.begin(); 
   				add += high - low;
   				res = max(res, add);
   			}
   		}
   		else{
			l = a[x], r = l + cnt;
			// int add = upper_bound(all(spcal), l - 1) - spcal.begin();
			// int high = upper_bound(all(b), r) - b.begin(), low = lower_bound(all(b), l) - b.begin(); 
			// add += high - low;
			// res = max(res, add);
			cnt++;
			au.erase(a[x]);
   		}
   		x--;
   	} 
   	//cout << res << endl;
   	x = y;
   	int mres = res;
   	res = 0;
   	cnt = 0;
   	while(x < n + m){
   		if(au.find( a[x] ) == au.end()){
   			if(!cnt){
   				x++;
   				continue;
   			}
   			else{
   				l = a[x], r = l + cnt - 1;
   				int add = spcal.size() - (lower_bound(all(spcal),r + 1) - spcal.begin());
   			//cout << add << endl;
   				int high = upper_bound(all(b), r) - b.begin(), low = lower_bound(all(b), l) - b.begin(); 
   				add += high - low;
   				res = max(res, add);


   				r = a[x], l = r - (cnt - 1);
   				add = spcal.size() - (lower_bound(all(spcal),r + 1) - spcal.begin());
   				high = upper_bound(all(b), r) - b.begin(), low = lower_bound(all(b), l) - b.begin(); 
   				add += high - low;
   				res = max(res, add);
   			//cout << " a[x] = " << a[x] << " " << l << " " << r << endl;
   			}
   		}
   		else{
			r = a[x], l = r - cnt;
			// int add = spcal.size() - (lower_bound(all(spcal), r + 1) - spcal.begin());
			// int high = upper_bound(all(b), r) - b.begin(), low = lower_bound(all(b), l) - b.begin(); 
			// add += high - low;
			// res = max(res, add);
   // 			//cout << add << endl;
			cnt++;
			au.erase(a[x]);
   		}
   		x++;


   	}
   	mres += res;

   	printf("%d\n", mres);
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