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

ll dp[25][2][2][2], mx;

char a[25], b[25];

ll product(int pos, int pbig, int  psmall, int pzero)
{
    if(pos == mx) return 1;

    ll &ret = dp[pos][pbig][psmall][pzero];

    if( ret != -1) return ret;

    ll ans = -1, st = 0, lim = 9;


    if( !pbig ) st = a[pos] - '0';
    if( !psmall ) lim = b[pos] - '0';

    if(pzero && st == 0) {
        ans = product(pos + 1, pbig || 0 > st, psmall || 0 < lim, 1 );
        st++;
    }

    for(ll i = st; i <= lim; i++)
    {
        ans = max(ans, i * product(pos + 1, pbig || i > st, psmall || i < lim, pzero && i == 0 ));
    }

    return ret = ans;


}

void printans(int pos, int pbig, int psmall, int pzero)
{
    if(pos == mx ) return;

    ll ans = -1, st = 0, lim = 9, indx = -1;


    if( !pbig ) st = a[pos] - '0';
    if( !psmall ) lim = b[pos] - '0';

    if(pzero && st == 0) {
        ans = product(pos + 1, pbig || 0 > st, psmall || 0 < lim, 1 );
        st++;
        indx = 0;
    }

    for(ll i = st; i <= lim; i++)
    {
        ll callvalue = i * product(pos + 1, pbig || i > st, psmall || i < lim, pzero && i == 0 );
        if(ans < callvalue)
        {
            ans = callvalue;
            indx = i;
        }
    }


    if( !(pzero && indx == 0) ) printf("%lld", indx);
    printans(pos + 1, pbig || indx > st, psmall || indx < lim, pzero && indx == 0);

}

int main()
{
#ifdef PARTHO
    freopen("/home/partho/Desktop/IO/input.txt","r",stdin);
    freopen("/home/partho/Desktop/IO/output.txt","w",stdout);
    int start_time = clock();
#endif
//FastIO;

ll x, y;

scll(x, y);

if(x > y) swap(x, y);

sprintf(a, "%lld", x);
sprintf(b, "%lld", y);

mx = strlen(b);

int def = 0, indx = 0, pos = 0;
char zero[20];

def = mx - strlen(a);

zero[indx] = 0;

while(def--) zero[indx++] = '0';
while(a[pos]) zero[indx++] = a[pos++];
zero[indx] = 0;

strcpy(a, zero);
memset(dp, -1, sizeof dp);

ll ans = product(0, 0, 0, 1);
printans(0, 0, 0, 1);
puts("");

#ifdef PARTHO
    int end_time = clock();
    printf("Time = %.4f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
#endif

    return 0;
}
///Before submit=>
///    *check for integer overflow,array bounds
///    *check for n=1