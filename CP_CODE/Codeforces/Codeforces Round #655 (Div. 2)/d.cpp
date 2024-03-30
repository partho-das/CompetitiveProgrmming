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
#define sc1(n)       sc("%d",&n);
#define sc2(n, m)    sc("%d%d", &n, &m);
#define sc3(m, n, o) sc("%d%d", &m, &n, &o);
#define scl(n)		 sc("%lld", &n);
#define scll(n, m)	 sc("%lld%lld", &n, &m);
#define scf(f)       sc("%f",&f);
#define pn(n)        printf("%d\n", n);
#define ps(str)      printf("%s\n", str);
#define FOR(i,a,n)   for( int i = a; i < n; i++)
#define TEST(test)   for(int cse = 1; cse <= test; cse++)
#define all(x) (x).begin(), (x).end()
#define fap(x) cout << __LINE__ << " says: " << #x << " = " << x << "\n"
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const ll INF = 2000000000000000000LL;
const int inf = 0x3f3f3f3f;
const long double EPS = 1e-9;
const ll MOD = 1e9 + 7;
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline double my_sqrt(T n) { double high = n, low = 0, mid, ans; int cnt = 100; while(cnt--) { mid = low + (high - low) / 2; if(mid * mid <= n) ans = mid, low = mid; else high = mid; } return ans; }
template<class T> inline T bigmod(T b, T p){ if(p <= 0) return 1; if(p & 1) return (b * bigmod(b, p - 1)) % MOD; ll x = bigmod(b, p >> 1); return (x * x) % MOD;}
//____________________________________________________________________________________________________________________________________

const int maxn = 2e5 + 5;

ll even[maxn], odd[maxn];
int main()
{
#ifdef PARTHO
    freopen("/home/partho/Desktop/IO/input.txt","r",stdin);
    freopen("/home/partho/Desktop/IO/output.txt","w",stdout);
    int start_time = clock();
#endif
//FastIO;


int test;

test = 1;

while(test--)
{
	int n;
	sc1(n);

	int e = 0, o = 0, value;
	for(int i = 1; i <= n; i++)
	{
		sc1(value);
		if(i & 1)
		{
			o++;
			odd[o] = odd[o - 1] + value;
		}
		else
		{
			e++;
			even[e] = even[e - 1] + value;
		}
	}
	ll mx = 0;

	int now = 0, l = 0;
	for(int i = 1; i <= o; i++)
	{
		ll sum = odd[o] - odd[l];
		sum += even[now];
		l++, now++;
		mx = max(mx, sum);
	}

	now = 1, l = 0;
	for(int i = 1; i <= e; i++)
	{

		ll sum = even[e] - even[l];
		sum += odd[now];
		l++, now++;
		mx = max(mx, sum);
	}
		printf("%lld\n", mx);

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
