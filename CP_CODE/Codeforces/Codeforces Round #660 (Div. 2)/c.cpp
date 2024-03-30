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

const int maxn = 1e5;
int presone[maxn + 5], happy[maxn + 5], visit[maxn + 5];
int child[maxn + 5];
std::vector<int> grid[maxn + 5];
int n, m;

int ck = 0;
int dfs(int src)
{
	visit[src] = 1;

	if(ck == 1) return -1;
	int h = happy[src];

	int p = child[src];

	if(( p & 1 && (h & 1) == 0) || (h & 1 && (p & 1) == 0) || (abs(h) > p) ) ck = 1;

	int a = p - abs(h);

	if(h < 0)
	{
		h = p - a / 2;
	}
	else
	{
		 h = a / 2;
	}
	//cout << src << " " << h << endl;

	ll ex = 0;
	for(int i = 0; i < grid[src].size(); i++)
	{
		if(visit[grid[src][i]] == 0)
		{
		ex += dfs( grid[src][i] );
		//fap(src);
		// fap(grid[src][i]);
		// cout << ex << endl;	
		}
	}



	if(h < ex)
	{
		return h;
	}
	else
	{
		//cout << src  << " " << h << " " << ex <<" " << ck << endl;
		int dif = abs(ex - h);
		if(dif <= presone[src]) return h;
		else ck = 1;

		return -1;
	}

}


int gen(int src)
{
	visit[src] = 1;

	int sum = 0;

	//cout << src << endl;
	for(int i = 0; i < grid[src].size(); i++)
	{
		if(visit[ grid[src][i] ] == 0)
		{

			//fap(grid[src][i]);
			sum += gen( grid[src][i] );

		}
	}

	sum += presone[src];

	//fap(sum);
	return child[src] = sum;
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
	
	sc2(n, m);

	for(int i = 1; i <= n; i++)
	{
		sc1(presone[i]);
	}
	

	for(int i = 1; i <= n; i++)
	{
		sc1(happy[i]);
		grid[i].clear();
		visit[i] = 0;
	}

	for(int i = 1; i < n; i++)
	{
		int u, v;

		sc2(u, v);
		//cout << u << " " << v << endl;
		grid[u].pb(v);
		grid[v].pb(u);
	}

	gen(1);


	for(int i = 1; i <= n; i++)
	{
		visit[i] = 0;
	}


	ck = 0;
	int now = dfs(1);


	if(ck == 0) puts("YES");
	else puts("NO");


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