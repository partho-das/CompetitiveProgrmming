#include <bits/stdc++.h>
using namespace std;
 
//____________________________________________________________________________________________________________________________________
#define PI  2*acos(0.0)
#define pf  printf
#define sc  scanf
#define ff  first
#define ss  second
#define mp  make_pair
#define pb  push_back
typedef long long ll;
typedef unsigned long long ull;
typedef std::vector<int> vi;
typedef vector<long long> vll ;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define sc1(n)         sc("%d",&n);
#define sc2(n, m)      sc("%d%d", &n, &m);
#define sc3(m, n, o)   sc("%d%d%d", &m, &n, &o);
#define scl(n)         sc("%lld", &n);
#define scll(n, m)     sc("%lld%lld", &n, &m);
#define sclll(n, m, o) sc("%lld%lld%lld", &n, &m, &o);
#define scf(f)         sc("%f",&f);
#define pn(n)        printf("%d\n", n);
#define ps(str)      printf("%s\n", str);
#define FOR(i,a,n)   for( int i = a; i < n; i++)
#define TEST(test)   for(int cse = 1; cse <= test; cse++)
#define all(x) (x).begin(), (x).end()
#define fap(x) cout << __LINE__ << " says: " << #x << " = " << x << "\n"
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const ll INF = 2000000000000000000LL;
const int inf = 0x3f3f3f3f;
ll MOD =  1e9 + 7;
const long double EPS = 1e-9;
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline double my_sqrt(T n) { double high = n, low = 0, mid, ans; int cnt = 100; while(cnt--) { mid = low + (high - low) / 2; if(mid * mid <= n) ans = mid, low = mid; else high = mid; } return ans; }
template<class T> inline T bigmod(T b, T p){ if(p <= 0 || b == 0) return 1; if(p & 1) return (b * bigmod(b, p - 1)) % MOD; ll x = bigmod(b, p >> 1); return (x * x) % MOD;}
//____________________________________________________________________________________________________________________________________

const int maxn = 1e5, maxn2 = 4e2;
ll seg[maxn2 + 5][2], arr[maxn], n, q;

pll max_of2(ll a, ll b, ll c, ll d = -inf)
{
	ll x = -inf, y = -inf; 
	if( a >= x) y = x, x = a;
	else if(a > y) y = a;

	if( b >= x) y = x, x = b;
	else if(b > y) y = b;

	if( c >= x) y = x, x = c;
	else if(c > y) y = c;

	if( d >= x) y = x, x = d;
	else if(d > y) y = d;
	return {x, y};
}
void preprocess()
{
	for(int i = 0; i < maxn2; i++){
		seg[i][0] = seg[i][1] = -inf;
	}
	int sq = sqrt(n);
	for(int i = 0; i < n; i++){
		pll res = max_of2(seg[i / sq][0], seg[i / sq][1], arr[i]);
		seg[i / sq][0] = res.ff;
		seg[i / sq][1] = res.ss;
	}

	return;
}

void Update(int indx, ll x)
{
	int sq = sqrt(n), st = (indx / sq) * sq, ed = min(ll(st + sq - 1), n - 1);

	arr[indx] = x;
	seg[indx / sq][0] = seg[indx / sq][1] = -inf;
	for(int i = st; i <= ed; i++){

		pll res = max_of2(seg[i / sq][0], seg[i / sq][1], arr[i]);
		seg[i / sq][0] = res.ff;
		seg[i / sq][1] = res.ss;
	}

	return;
}

ll Queary(int l, int r){
	int sq = sqrt(n), st = (l / sq) * sq, ed = min(st + sq - 1, r);
	pll res{-inf, -inf};
	for(int i = l; i <= ed; i++){
		res = max_of2(res.ff, res.ss, arr[i]);
	}
	st = ed;
	for(int i = (st + sq) / sq; i * sq + sq - 1 <= r; i++){
		res = max_of2(res.ff, res.ss, seg[i][0], seg[i][1]);
		st = i * sq + sq - 1;
	}
	st++;
	ed = r;
	for(int i = st; i <= ed; i++){
		res = max_of2(res.ff, res.ss, arr[i]);
	}
	return  res.ff + res.ss;
}

int main()
{
#ifdef PARTHO
    freopen("/home/partho/Desktop/IO/input.txt","r",stdin);
    freopen("/home/partho/Desktop/IO/output.txt","w",stdout);
    int start_time = clock();
#endif
//FastIO;

scl(n);

for(int i = 0; i < n; i++)
scl(arr[i]);
scl(q);


preprocess();

while(q--){
	char cmd;
	int indx, l, r;
	ll x;
	getchar();
	cmd = getchar();
	if(cmd == 'U'){
		sc1(indx);
		scl(x);
		Update(indx - 1, x);
	}
	else{
		sc2(l, r);
		ll sum = Queary(l - 1, r - 1);
		printf("%lld\n", sum);
	}

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