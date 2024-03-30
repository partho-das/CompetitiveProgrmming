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

int n;
const int maxn = 2e5 + 5;

bool cmp(pii &a, pii &b)
{
	if(a.ff - a.ss > b.ff - b.ss) return 1;
	return 0;
}



bool ck(int mid, int indx, std::vector<pii> &v)
{
	if(v[indx].ff + v[mid].ff > v[indx].ss + v[mid].ss) return 1;
	else return 0;
}

int main()
{
#ifdef PARTHO
    freopen("/home/partho/Desktop/IO/input.txt","r",stdin);
    freopen("/home/partho/Desktop/IO/output.txt","w",stdout);
    int start_time = clock();
#endif
//FastIO;

sc1(n);



std::vector<pii> v(n);
for(int i = 0;i < n; i++)
{
	sc1(v[i].ff);
}

for(int i = 0;i < n; i++)
{
	sc1(v[i].ss);
}

sort(all(v), cmp);

//for(auto &it : v) cout << it.ff <<" " << it.ss << endl;

ll sum = 0;

for(int i = 0; i < n; i++)
{
	int low = i + 1, high = n - 1, mid, ans = i, cnt = 32;

	while(low <= high)
	{
		mid = high + low >> 1;
		// fap(mid);
		// fap(high);
		// fap(low);
		if(ck(mid, i, v))
		{
			low = mid + 1;
			ans = mid;
		}
		else high = mid - 1;
	}
	sum += ((ans - i));
	//cout << ans << endl;
}
printf("%lld\n", sum);
    

#ifdef PARTHO
   int end_time = clock();
   printf("Time = %.4f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
#endif

    return 0;
}
///Before submit=>
///    *check for integer overflow,array bounds
///    *check for n=1
