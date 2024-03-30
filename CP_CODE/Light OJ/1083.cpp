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
const ll INF = 2000000000000000000LL;
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

vi v;
int n;
const int maxn = 3e4;
int mn[maxn * 10], bckarr[maxn + 5];
int build(int indx, int l, int r){
	//cout << indx << " " << l << " " << r << endl; 
	if(l == r){
		return mn[indx] = v[l];
	}
	int mid = l + (r - l) / 2;
	return mn[indx] = min( build(indx << 1, l, mid),
	build((indx << 1) + 1, mid + 1, r) );
}

int Lquery(int indx, int l, int r, int i, int j, int value){

	if( l > j || r < i) return -1;
	if(i <= l && r <= j && mn[indx] >= value) return -1;
	if(l == r && v[l] < value) return l;
	if(l == r) return -1;
	//cout << l << " (2nd) " << r << " " << i << " " << j << " " << value << endl;

	int mid = l + (r - l) / 2;
	int ret = -1;
	
	ret = Lquery( (indx << 1) + 1, mid + 1, r, i, j, value);
	if( ret == -1){
		ret = Lquery(indx << 1, l, mid, i, j, value);
	}

	return ret;
}

int Rquery(int indx, int l, int r, int i, int j, int value){

	if( l > j || r < i) return -1;
	if(i <= l && r <= j && mn[indx] >= value) return -1;
	
	if(l == r && v[l]  < value) return l;
	if(l == r) return -1;

	int mid = l + (r - l) / 2;
	int ret = -1;
	ret = Rquery(indx << 1, l, mid, i, j, value);
	if(ret == -1){
		ret = Rquery( (indx << 1) + 1, mid + 1, r, i, j, value);
	}

	return ret;
}



int solve(){
	sc1(n);
    v.resize(n);
    for(int i = 0; i < n; i++){
    	sc1(v[i]);
    }
    build(1, 0, n - 1);

   	int res = 0, value = 0, value2 = 0, indx;

   	for(int i = 0; i < n; i++){
   		value = v[i], value2 = v[i];
   		
   		indx = Lquery(1, 0, n - 1, 0, i, v[i]);
   		if(indx != -1){
   			value = v[i] * (i - indx) ;
   		}
   		else value = v[i] * (i + 1);

   		indx = Rquery(1, 0, n - 1, i, n - 1, v[i]);
   		//break;
   		if(indx != -1){
   			value2 =  v[i] * (indx - i);
   		}
   		else value2 = v[i] * (n - i);

   		value2 = value - v[i] + value2;
   		res = max({value, res, value2});
   		//cout << res << " " << value << " " << value2 << " " << indx << endl;
   	}

  

    return res;
}



int main() {
    #ifdef PARTHO
        freopen("/home/partho/Desktop/IO/input.txt","r",stdin);
        freopen("/home/partho/Desktop/IO/output.txt","w",stdout);
        int start_time = clock();
    #endif
    //FastIO;

    int test = 1, tc = 1;

    sc1(test);

    while(test--){
        printf("Case %d: %d\n", tc++, solve());	

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