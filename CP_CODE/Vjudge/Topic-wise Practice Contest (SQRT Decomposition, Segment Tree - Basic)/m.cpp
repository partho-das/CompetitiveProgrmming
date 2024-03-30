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

const int maxn = 1e7;

int seg[maxn * 4];


void update(int indx, int l, int r, int i, int j, int x, int last)
{
    if( l > j || r < i ){
        if(last > 0) seg[indx] = last;
        return;
    }
    if( i <= l && r <= j ){
        seg[indx] = x;
        return;
    }
    int mid = l + (r - l >> 1);
    if(seg[indx] == -1) seg[indx] = 0;

    if(last > 0){
        update( indx << 1, l, mid, i, j, x, last);
        update( (indx << 1) + 1, mid + 1, r, i, j, x, last);
    }
    else{
        update( indx << 1, l, mid, i, j, x, seg[indx]);
        update( (indx << 1) + 1, mid + 1, r, i, j, x, seg[indx]);
    }
    if( seg[indx << 1] == seg[ (indx << 1) + 1 ]) seg[indx] = seg[indx << 1];
    else seg[indx] = 0;
    return;
}

set<int> unq;
void query(int indx, int l, int r)
{
    if(seg[indx] == -1) return;
    if(seg[indx] > 0){ 
        unq.insert(seg[indx]);
        return;
    }
    if(l == r)return;
    int mid = l + (r - l >> 1);
    query(  indx << 1, l, mid);
    query( (indx << 1) + 1, mid + 1, r);

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

sc1(test);

while(test--)
{
    int n;
    sc1(n);

    memset(seg, -1, sizeof seg);
    int x = 1;
    while(n--)
    {
        int i, j;
        sc2(i, j);
        update(1, 1, maxn, i, j, x++, seg[1]);
    }

    unq.clear();
    query(1, 1, maxn);
    printf("%d\n", (int)unq.size());


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