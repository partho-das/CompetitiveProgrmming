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
const ll MOD =  1e9 + 7;
const long double EPS = 1e-9;
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline double my_sqrt(T n) { double high = n, low = 0, mid, ans; int cnt = 100; while(cnt--) { mid = low + (high - low) / 2; if(mid * mid <= n) ans = mid, low = mid; else high = mid; } return ans; }
template<class T> inline T bigmod(T b, T p){ if(p <= 0) return 1; if(p & 1) return (b * bigmod(b, p - 1)) % MOD; ll x = bigmod(b, p >> 1); return (x * x) % MOD;}
//____________________________________________________________________________________________________________________________________

const int maxn = 2e3;
int dp[maxn + 5][2][2][2][maxn + 5], dev, d;
char str[maxn + 5];

int f(int pos, int prevsmall, int zero, int move, int rem)
{
	//cout << pos << " " << prevsmall << " " << zero << " " << move << " " << rem << endl;

	if(str[pos] == 0) return rem == 0 && (!zero);
	if(dp[pos][prevsmall][zero][move][rem] != -1) return dp[pos][prevsmall][zero][move][rem];


	ll sum = 0;

	if(move){
		if(  prevsmall || str[pos] >= '0' + d )
			sum = f(pos + 1, prevsmall || (str[pos]  > '0' + d), zero, 0, (rem * 10 + d) % dev);
	}
	else{

		int lim = 9;

		if(prevsmall == 0) lim = str[pos] - '0';

		if(zero || d != 0)
		sum = f(pos + 1, prevsmall || str[pos] > '0', zero, !zero, (rem * 10) % dev);

		for(int i = 1; i <= lim; i++)
		{
			if(i != d)
			{
				//fap(i);
			//cout << pos << " " << prevsmall << " " << zero << " " << move << " " << rem << endl;
			sum = (sum + f(pos + 1, prevsmall || i < lim, 0, 1, (rem * 10 + i) % dev)) % MOD;
			}
		}
	}


	return dp[pos][prevsmall][zero][move][rem] = sum;
}

int main()
{
#ifdef PARTHO
    freopen("/home/partho/Desktop/IO/input.txt","r",stdin);
    freopen("/home/partho/Desktop/IO/output.txt","w",stdout);
    int start_time = clock();
#endif
//FastIO;

int a, b;


sc2(dev, d);

scanf("%s", str);


int len = strlen(str);

len--;
int st = 0;
while(str[len] == '0') str[len--] = '9';
str[len]--;

if(str[0] == '0') st++; 

//fap(str);

memset(dp, -1, sizeof dp);
int cnta = f(st, 0, 1, 0, 0);
memset(dp, -1, sizeof dp);

scanf("%s", str);

int cntb  = f(0, 0, 1, 0, 0);



//cout << cnta << " " << cntb << endl;
printf("%lld\n", (cntb - cnta + MOD) % MOD) ;




#ifdef PARTHO
    int end_time = clock();
    printf("Time = %.4f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
#endif

    return 0;
}
///Before submit=>
///    *check for integer overflow,array bounds
///    *check for n=1