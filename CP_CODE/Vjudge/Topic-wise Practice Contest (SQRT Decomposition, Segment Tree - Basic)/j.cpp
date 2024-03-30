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

const int maxn = 30000;

char str[maxn + 1000];
struct node{
	int unlcnt, unrcnt;
	node(){unrcnt = 0, unrcnt = 0;}
} seg[100000 + 5];

node marge(node a, node b){

	int m = min(a.unlcnt, b.unrcnt);
	a.unlcnt-=m;
	b.unrcnt-=m;
	node temp;
	temp.unlcnt =  a.unlcnt + b.unlcnt, temp.unrcnt = a.unrcnt + b.unrcnt ;
	return temp;
}
int cnt = 0;
int mxr = -inf, mxindx = -inf;
void build(int indx, int l, int r){
	mxindx = max(mxindx, indx);
	mxr = max(mxr, (max(l, r)));
	if(l == r){
		seg[indx].unlcnt = (str[l] == '(');
		seg[indx].unrcnt = (str[l] == ')');
		return;
	}

	int mid = l + (r - l >> 1);

	build(indx << 1, l, mid);
	build((indx << 1) + 1, mid + 1, r);
	seg[indx] = marge(seg[indx << 1], seg[ (indx << 1) + 1]);

	return; 
}

int query(){
	return (seg[1].unlcnt == 0 && seg[1].unrcnt == 0);
}

void upddate(int indx, int l, int r, int i){

	if( i < l || i > r) return;

	if( l == r){
		if(l == i)
		{
			if(str[i] == '(') str[i] = ')';
			else str[i] ='(';
			seg[indx].unlcnt = (str[l] == '(');
			seg[indx].unrcnt = (str[l] == ')');
		}
		return;
	}


	int mid = l + (r - l >> 1);

	upddate( indx << 1, l, mid, i);
	upddate( (indx << 1) + 1, mid + 1, r, i);

	seg[indx] = marge(seg[indx << 1], seg[ (indx << 1) + 1 ]);
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

int test, tc = 1;

test = 10;


while(test--)
{
	int n,q;
	sc1(n);

	sc("%s", str);
	sc1(q);

	build(1, 0, n - 1);

	printf("Test %d:\n", tc++);
	while(q--){

		int cmd;
		sc1(cmd);
		if(!cmd){
			int res = query();
			if(res) printf("YES\n");
			else puts("NO");
		}
		else upddate(1, 0, n - 1, cmd - 1);
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