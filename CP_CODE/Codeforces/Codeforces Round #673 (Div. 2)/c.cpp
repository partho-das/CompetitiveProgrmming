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
template<class T> inline T bigmod(T b, T p){ if(p <= 0) return 1; if(p & 1) return (b * bigmod(b, p - 1)) % MOD; ll x = bigmod(b, p >> 1); return (x * x) % MOD;}
//____________________________________________________________________________________________________________________________________

const int maxn = 3e5;
int lastpos[maxn + 5], firstmn[maxn + 5], mxdis[maxn + 5];

bool cmp(pii &a, pii &b)
{
	if(a.ss < b.ss)
		return 1;
	else if(a.ss == b.ss) return a.ff < b.ff;

	return 0;
}

int solve(std::vector<pii> &fv, int cnt)
{
	int low = 0, high = fv.size() - 1, mid = low + (high - low) / 2, indx = -1;

	//cout << cnt << endl;
	while(low <= high)
	{
		if(fv[mid].ss <= cnt) low = mid + 1, indx = mid;
		else  high = mid - 1;
		// fap(fv[mid].ss);
		// cout << fv[mid].ff << endl;

		 mid = low + (high - low) / 2;		
	}

	if(indx == -1) return indx;

	else return firstmn[indx];

}


int main()
{
#ifdef PARTHO
    freopen("/home/partho/Desktop/IO/input.txt","r",stdin);
    freopen("/home/partho/Desktop/IO/output.txt","w",stdout);
    int start_time = clock();
#endif
//FastIO;

int test;

sc1(test);


while(test--)
{
	int n;

	sc1(n);

	for(int i = 0; i <= n; i++)
		lastpos[i] = -1, mxdis[i] = -1;

	vi v(n);

	for(int i = 0; i < n; i++)
	{
		sc1(v[i]);

		if( mxdis[v[i]] == -1){
			
			mxdis[v[i]] = i + 1;
			//cout << mxdis[4] << endl;
		}
		else
		mxdis[v[i]] = max( mxdis[ v[i] ], ((i - lastpos[v[i] ]))) ; 
		lastpos[v[i]] = i;

	}

	// for(int i = 1; i <= n; i++)
	// 	cout << mxdis[i] << endl;


	for(int i = 0; i < n; i++)
	{
		mxdis[ v[i] ] = max( mxdis[ v[i] ], ( (n - 1) - lastpos[v[i] ]) + 1 );
	}


 	std::vector<pii> fv;


 	for(int i = 0; i <= n; i++)
 	{
 		if( mxdis[i] != -1 ) fv.pb({i, mxdis[i]});
 	}
 	sort(all(fv), cmp);

 	// for(auto it : fv)
 	// 	cout << it.ff << " " << it.ss << endl;

 	int mn = inf;

 	for(int i = 0; i < fv.size(); i++)
 	{
 		mn = min(fv[i].ff, mn);
 		firstmn[i] = mn;
 		//cout << mn << endl;
 	}


 	for(int i = 1; i <= n; i++)
 	{
 		int cnt = i;

 		printf("%d ", solve(fv, cnt));
 	}

 	puts("");



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