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
int n;

vi graph[ maxn + 5 ];
int res[maxn + 5];
int mxmin = inf, indx = 0;

bool visit[maxn + 5];
void input()
{
	for(int i = 1; i <= n; i++)
		visit[i] = 0, graph[i].clear();
	mxmin = inf;

	int u, v;
	for(int i = 1; i < n; i++)
	{

		sc2(u, v);
		graph[u].pb(v);
		graph[v].pb(u);
	}

	return;
}


int dfs(int src, int prev)
{
	int mx = prev, temp, sum = 0;

	visit[src] = 1;


	for(int i = 0; i < graph[src].size(); i++)
	{
		if(visit[ graph[src][i] ] != 1)
		{
			temp = dfs(graph[src][i], prev + 1);

			//cout << src << " " << temp << " " << prev << endl;
			
			mx = max( temp, mx );
			sum += temp;
		}
	}

	prev += n - sum - prev - 1;

	mx = max(mx, prev);
	//cout << src << mx << endl;
	res[src] = mx;

	if(mx < mxmin)
	{
		mxmin = mx;
		indx = src;
	}


	return sum + 1;
}


int findnode(int src)
{
	if(graph[src].size() == 1) return src;
	visit[src] = 1;

	for(int i = 0; i < graph[src].size(); i++)
	{
		if(! visit[ graph[src][i] ])
		{
			return findnode( graph[src][i] );
		}
	}

	return src;
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

	sc1(n);

	input();

	int first = 1;
	
	while(graph[first].size() != 1)first++;

	int temp = dfs(first, 0);

	if( temp < mxmin){

		mxmin = temp;
		indx = first; 
	}
	//cout << first << endl;

	int second = -1;

	for(int i = 0; i < graph[indx].size(); i++)
	{
		if(mxmin == res[ graph[indx][i] ]  ){
			second = graph[indx][i];
			break;
		}
	}
	//cout << mxmin << indx << endl;
	if( second == -1)
	{
		printf("%d %d\n", 1, graph[1].back() );
		printf("%d %d\n", 1, graph[1].back() );	
	}
	else
	{
		for(int i = 1; i <= n; i++)
		visit[i] = 0;
		visit[second] = 1;

		int extract = findnode(indx), extract2 = graph[extract].back();

		printf("%d %d\n", extract2, extract);

		printf("%d %d\n", second, extract);
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