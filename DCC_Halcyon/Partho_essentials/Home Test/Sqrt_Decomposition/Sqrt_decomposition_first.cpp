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
const int maxn = 1e3;
void pri_process(int n, vi &v, int *res){
	int sq = sqrt(n);

	for(int i = 0; i < maxn; i++) res[i] = inf;
	for(int i = 0; i < n; i++){

		res[i / sq] = min(v[i], res[i / sq]);
		//cout << res[i / sq] << endl;
	}
	return;
}
void update(int n, vi &v, int *res, int indx, int x){ // Chanaging to v[indx] = x;
	v[indx] = x;
	int sq = sqrt(n), st = (indx / sq) * sq, ed  = min(st + sq - 1, n - 1);
	FOR(i, st, ed + 1) res[i / sq] = min(v[i], res[i / sq]);
	return;
}
int query(int n, vi &v, int *res, int l, int r){ // l to r Inclusive
	int sq = sqrt(n), st = (l / sq) * sq, ed = min( st + sq - 1, r);

	int sum = inf;
	for(int i = l; i <= ed && i < n; i++){
		sum =  min(v[i], sum);
	}
	st = ed;
	for(int i = st + sq; i < n && i <= r; i+= sq){
		sum =  min(sum, res[i / sq]);
		st = i;
	}
	st++;
	for(int i = st; i < n && i <= r; i++) sum =  min(v[i], sum);
	//fap(sum);
	return sum;
}



int main()
{
#ifdef PARTHO
    freopen("/home/partho/Desktop/IO/input.txt","r",stdin);
    freopen("/home/partho/Desktop/IO/output.txt","w",stdout);
    int start_time = clock();
#endif
//FastIO;


int n, res[maxn + 5], q, tc = 1;

int test;

sc1(test);

while(test--)
{
	sc2(n, q);
	vi v(n);
	for(int  i = 0; i < n; i++) sc1(v[i]);


	//for(auto it : v) cout << it << " "  << endl;
	pri_process(n, v, res);

	printf("Case %d:\n", tc++);
	while(q--)
	{
		int i, j;

		sc2(i, j);
		//cout << i << " " << j << endl;
		if(i > j) swap(i, j);
			i--;
			j--;	
			int sum = query(n, v, res, i, j);
			printf("%d\n", sum);

	}
		//break;

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