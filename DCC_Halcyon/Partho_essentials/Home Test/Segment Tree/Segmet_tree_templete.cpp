#include <bits/stdc++.h>
using namespace std;
 
//____________________________________________________________________________________________________________________________________
#define PI  2*acos(0.0)
#define pf  printf
#define sc  scanf
#define ff  first
#define ss  second
#define pb  push_back
typedef long long ll;
typedef unsigned long long ull;
typedef std::vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define lseg indx << 1, l, l + (r - l) / 2
#define rseg (indx << 1) + 1, l + (r - l) / 2 + 1, r
#define lindx indx << 1
#define rindx (indx << 1) + 1
#define sc1(n)         sc("%d",&n)
#define sc2(n, m)      sc("%d%d", &n, &m)
#define sc3(m, n, o)   sc("%d%d%d", &m, &n, &o)
#define scl(n)         sc("%lld", &n)
#define scll(n, m)     sc("%lld%lld", &n, &m)
#define sclll(n, m, o) sc("%lld%lld%lld", &n, &m, &o)
#define scf(f)         sc("%lf",&f);
#define pn(n)          pf("%d\n", n);
#define FOR(i,a,n)   for( int i = a; i < n; i++)
#define all(x) (x).begin(), (x).end()
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int MOD =  1e9 + 7;
const long double EPS = 1e-9;
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline double my_sqrt(T n) { double high = n + 5, low = 0, mid, ans; int cnt = 100; while(cnt--) { mid = low + (high - low) / 2; if(mid * mid <= n) ans = mid, low = mid; else high = mid; } return ans; }
template <class T> inline T bigmod(T b, T p){ if(p <= 0 || b == 0) return 1; ll x = b; if(p & 1) return (x * bigmod(b, p - 1)) % MOD; x = bigmod(b, p >> 1); return (x * x) % MOD;}
#ifdef PARTHO
#define dbg(x) cout << __LINE__ << " says: " << #x << " = " << x << "\n"
#else
#define dbg(x)
#endif
//____________________________________________________________________________________________________________________________________

const int maxn = 2e5;

vi v(maxn + 5);
struct segment_tree{

    struct point{
        int size, first, last, presize, sufsize;
        ll cnt;
        point(){
            size = first = last = presize = sufsize = cnt = 0;
        }
        point(int _first, int _last, int _presize = 1, int _sufsize = 1, int _size = 1, ll _cnt = 1){
            first = _first, last = _last, presize = _presize, sufsize = _sufsize, size = _size, cnt = _cnt; 
        }
    };
    
    point seg[4 * maxn + 5];

    inline ll sum(ll n){
        return (n * n + n) >> 1;
    }
    point marge(point a, point b){
        point ret;
        if(!a.size) return b;
        if(!b.size) return a;
        ret = point(a.first, b.last, a.presize, b.sufsize, a.size + b.size, a.cnt + b.cnt);
        if(a.last <= b.first){
            ret.cnt = ret.cnt - sum(a.sufsize) - sum(b.presize) + sum(a.sufsize + b.presize);
            if(a.presize == a.size) ret.presize = a.size + b.presize;
            if(b.sufsize == b.size) ret.sufsize = b.size + a.sufsize;
        }
        return ret;
    }

    void bulid(int indx, int l, int r){
       
        if(l == r){
            seg[indx] = point(v[l], v[l]);
            return;
        }
        bulid(lseg);
        bulid(rseg);
        seg[indx] = marge(seg[lindx], seg[rindx]);
        return;
    }

    void update(int indx, int l, int r, int i){

        if(i > r || i < l) return;
        if(l == r && l == i){
            seg[indx] = point(v[l], v[l]);
            return;
        }
        update(lseg, i);
        update(rseg, i);
        seg[indx] = marge(seg[lindx], seg[rindx]);
        return;
    }

    point query(int indx, int l, int r, int i, int j){
        if(j < l || i > r) return point(0, 0, 0, 0, 0, 0);
        if(i <= l && r <= j) return seg[indx];
        return marge(query(lseg, i, j), query(rseg, i, j));
    }
};


void solve(){
    
    int n, q;

    sc2(n, q);

    for(int i = 1; i <= n; i++){
        sc1(v[i]);
    }
    segment_tree stree;

    stree.bulid(1, 1, n);

    while(q--){
        int cmd, i, j;

        sc3(cmd, i, j);

        if(cmd == 1){
            v[i] = j;
            stree.update(1, 1, n, i);
        }
        else{
            printf("%lld\n", stree.query(1, 1, n, i, j).cnt);
        }

    }
    return;
}



int main() {
    #ifdef PARTHO
        freopen("/mnt/Stable/Dropbox/IO/input.txt","r",stdin);
        freopen("/mnt/Stable/Dropbox/IO/output.txt","w",stdout);
        int start_time = clock();
    #endif
    //FastIO;

    int test = 1;

    //sc1(test);

    while(test--){
        solve();
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