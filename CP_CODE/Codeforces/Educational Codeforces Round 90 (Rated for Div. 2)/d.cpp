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
#define sc1(n)      sc("%d",&n);
#define sc2(n, m)   sc("%d%d", &n, &m);
#define scf(f)      sc("%f",&f);
#define pn(n)       printf("%d\n", n);
#define ps(str)     printf("%s\n", str);
#define FOR(i,a,n)  for(int i = a; i < n; i++)
#define TEST(test)  for(int cse = 1; cse <= test; cse++)
#define all(x) (x).begin(), (x).end()
#define fap(x) cout << __LINE__ << " says: " << #x << " = " << x << "\n"
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const ll INF = 2000000000000000000LL;
const int inf = 0x3f3f3f3f;
const long double EPS = 1e-9;
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline double my_sqrt(T n) { double high = n, low = 0, mid, ans; int cnt = 100; while(cnt--) { mid = low + (high - low) / 2; if(mid * mid <= n) ans = mid, low = mid; else high = mid; } return ans; }
//____________________________________________________________________________________________________________________________________

const int maxn = 2e5;
ll qsum[maxn + 5], n, dp[maxn + 5][6], mxsum;
std::vector<long long>  v(maxn + 5);


ll f(int indx, int st)
{
	if(indx >= n) return 0;

	if(dp[indx][st] != -1) return dp[indx][st];
	
	ll till = mxsum - qsum[indx - 2];
	if(st == 5)	return dp[indx][st] = till;

	ll res = 0;
	if(st == 0)
	{
		ll a = 0, b = 0,c = 0, d = 0;
		a = f(indx + 2, 0) + v[indx]; // dont change the next one
		b = f(indx + 2, 1) + v[indx]; // swap with the fornt one
		c = f(indx + 2, 2) + v[indx]; // swap with the back one
		d = f(indx + 2, 5) + v[indx]; // no move // nxt move return even sum
		res = max(a, b);
		res = max(res, c);
		res = max(res, d);	
	}
	else
	{
		ll a = 0 , b = 0, c = 0;
		if(st == 1 ) a = f(indx + 2, 1) + v[indx + 1];			
		else if(st == 2) a = f(indx + 2, 2) + v[indx - 1];
		
		b = f(indx + 2, 5) + v[indx];
		res = max(a, b);
	}

	return dp[indx][st] = res;
}


int main()
{
#ifdef PARTHO
    freopen("/home/partho/Desktop/IO/input.txt","r",stdin);
    freopen("/home/partho/Desktop/IO/output.txt","w",stdout);
    int start_time = clock();
#endif


int test;

sc1(test);

while(test--)
{

	sc("%lld", &n);
	n += 2;

	qsum[1] = 0;
	for(int i = 2; i < n; i++)
	{
		sc("%lld", &v[i]);
		dp[i][0] = dp[i][1] = dp[i][2] = dp[i][3] = dp[i][4]  = dp[i][5] =   -1;

		if(i % 2 == 0) qsum[i] = qsum[i - 2] + v[i];
	}
	v[n + 1] = 0;
	v[n] = 0;


	if(n & 1)
	{
		mxsum = qsum[n - 1];
	}
	else mxsum = qsum[n - 2];


	ll a = f(2, 0);
	ll b = f(2, 1);

	mxsum = max(mxsum, a);
	mxsum = max(mxsum, b);

	printf("%lld\n", mxsum);
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
