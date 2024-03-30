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

const int maxn = 3e5 + 5;

char str[maxn];

void fill(int l, int r, int value)
{
	FOR(i, l, r + 1) if(str[i] == '?') str[i] = '0' + value;

	return;
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

while(test--){
	int n, k;


	sc2(n, k);
	//cout << n << " " << k << endl;
	sc("%s", str);

	int onecnt = 0, zerocnt = 0, kby2 = k >> 1;
	for(int i = 0; i < k; i++)
	{
		if(str[i] == '1') onecnt++;
		else if(str[i] == '0') zerocnt++;
	}


	int ck = !( onecnt <= kby2 && zerocnt <= kby2);

	if(onecnt == kby2) fill(0, k - 1, 0);
	if(zerocnt == kby2) fill(0, k - 1, 1);


	int l = 1, r = k;


	while( r < n && !ck)
	{
		//cout << l << endl;
		
		if(str[r] == '?') str[r] = str[l - 1];
		
		// cout << onecnt << " " << zerocnt <<" " << str << endl;
		// fap(l);
		// fap(r);
		if( (str[ l - 1 ] != '?' && str[r] != '?' ) && str[l - 1] != str[r])
		{
			ck = 1;
			break;
		}


		if( str[l - 1] == '1' ) onecnt--;
		if( str[l - 1] == '0' ) zerocnt--;

		if( str[r] == '1' ) onecnt++;
		if( str[r] == '0' ) zerocnt++;

		if(onecnt == kby2) fill(l, r, 0);
		if(zerocnt == kby2) fill(l, r, 1);

		ck = max(ck , (int)!( onecnt <= kby2 && zerocnt <= kby2) );

		r++, l++;

	}


	if(!ck) puts("YES");
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