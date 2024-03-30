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
#define scl(n)       sc("%lld", &n);
#define scll(n, m)   sc("%lld%lld", &n, &m);
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
template <class T> inline T gcd(T a,T b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
template <class T> inline double my_sqrt(T n)
{
    double high = n, low = 0, mid, ans;
    int cnt = 100;
    while(cnt--)
    {
        mid = low + (high - low) / 2;
        if(mid * mid <= n) ans = mid, low = mid;
        else high = mid;
    }
    return ans;
}
template<class T> inline T bigmod(T b, T p)
{
    if(p <= 0) return 1;
    if(p & 1) return (b * bigmod(b, p - 1)) % MOD;
    ll x = bigmod(b, p >> 1);
    return (x * x) % MOD;
}
//____________________________________________________________________________________________________________________________________

map<int, int> pos;

int main()
{
#ifdef PARTHO
    freopen("/home/partho/Desktop/IO/input.txt","r",stdin);
    freopen("/home/partho/Desktop/IO/output.txt","w",stdout);
    int start_time = clock();
#endif
//FastIO;

    ll n, m, x, k, y, indx = 0, amx = -inf, xc;



scll(n,m);
scll(x, k);
scl(y);

xc = x;

if(x >= k * y) x = k * y;

vi v(n + 3), v2(m + 1);

for(int i = 1; i <= n; i++)
{
    sc1(v[i]);
    pos[v[i]] = i;

    if(amx < v[i])
    {
        amx = v[i];
        indx = i;
    }
}
pos[-1] = 0;
v[0] = -inf;
int ck = 0, l, r;
ll cost = 0;


for(int i = 1; i <= m; i++)
{
    sc1(v2[i]);
    if(pos.find(v2[i]) == pos.end()) 
        {
            pos[v2[i]] = 0, ck = 1;
           // cout << "NO" << endl;
        }
}

ll mx, mn, range;



    l = 0;
    r = pos[ v2[1] ];
    if(l >= r) ck = 1;
    mx = -INF, mn = INF;
    for(int i = l + 1; i < r; i++) mx = max((ll)v[i], mx), mn = min((ll)v[i], mn);

    range = r - l - 1;
    if(v[r] < mn && range % k) ck = 1;
    if(v[r] > mx) cost += (range / k) * x + (range % k) * y;
    else if(v[r] < mx) cost += ((range / k) - 1) * x + (range % k) * y + 1 * xc;

for(int i = 2; i <= m; i++)
{
    if(i == 1) l = 0;
    else l = pos[ v2[i - 1] ];
    r = pos[ v2[i] ];
    if(l >= r) ck = 1;
    mx = -INF, mn = INF;
    for(int i = l + 1; i < r; i++) mx = max((ll)v[i], mx), mn = min((ll)v[i], mn);

    range = r - l - 1;
    //cout << mx << " " << mn << endl;
    if(v[l] < mn && v[r] < mn && range % k) ck = 1;
    if(v[l] > mx || mx < v[r]) cost += (range / k) * x + (range % k) * y;
    else if(v[l] < mx && v[r] < mx) cost += ((range / k) - 1) * x + (range % k) * y + 1 * xc;
    
    //cout << cost << endl;
}

    l = pos[ v2[m] ];
    r = n + 1;
    if(l >= r) ck = 1;
    mx = -INF, mn = INF;
    for(int i = l + 1; i < r; i++) mx = max((ll)v[i], mx), mn = min((ll)v[i], mn);

    range = r - l - 1;
    if(v[l] < mn && range % k) ck = 1;
    if(v[l] > mx) cost += (range / k) * x + (range % k) * y;
    else if(v[l] < mx) cost += ((range / k) - 1) * x + (range % k) * y + 1 * xc;


// cout << v2[m] << " " << n << endl;
// cout << l << " " <<  r << endl;

// cout << range << endl;

    if(ck == 0) printf("%lld\n", cost);
    else puts("-1");



#ifdef PARTHO
    int end_time = clock();
    printf("Time = %.4f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
#endif

    return 0;
}
///Before submit=>
///    *check for integer overflow,array bounds
///    *check for n=1