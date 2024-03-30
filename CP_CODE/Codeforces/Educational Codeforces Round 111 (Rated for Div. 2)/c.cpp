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
struct state{
    int no, best2, bestall;
    state(){}
    state(int n, int a, int b){
        no = n, best2 = a, bestall = b;
    }
}seg[maxn * 4 + 5];

map<int, int> pos;
void build(int indx, int l, int r){
    if(l == r){
        seg[indx] = state(-1, -1, -1);
        return;
    }

    int m = l + ( r - l) / 2;

    build(indx << 1, l, m);
    build( ( indx << 1 ) + 1, m + 1, r);
    seg[indx] = state(-1, -1, -1);

    return;
}

set<int> unq;


int n;

state query(int indx, int l, int r, int i, int j){
    //cout << indx<< " " << l << " " << r << "  " << i << " " << j << endl;

    if(r < i || l > j) return state(-1, -1, -1);
    if( i <= l && r <= j) {
        return seg[indx];
    }


    int m = l + (r - l) / 2;

    state t1, t2, t3;
    t1 = query(indx << 1, l, m, i, j);
    t2 = query( (indx << 1) + 1, m + 1, r, i, j);
    if(t1.no > t2.no) {
        t3 = t1;

    }
    else if(t1.no == t2.no){
        t3 = t1;
        t3.best2 = max(t1.best2, t2.best2);
    }
    else t3 = t2;
    t3.bestall = max(t1.bestall, t2.bestall);
    return t3;
    // cout << indx<< " " << l << " " << r << "  " << i << " " << j << endl;
    // cout << (t1.no > t2.no) << " b2 " << t3.best2 << " " << t3.bestall << endl;
}

void update(int indx, int l, int r, int i, int xindx){

    if(i < l || i > r) return;
    if( l == r && i == l){
        if(unq.empty() || *unq.begin() > i){
            seg[indx] = state(1, xindx, xindx);
        //cout << *unq.begin() << endl;
        }
        else{
            state temp = query(1, 1, n, 1, i);
            seg[indx] = state(2, temp.best2, xindx);
        }
        return;
    }
    int m = l + ( r - l ) / 2;

    update(indx << 1, l, m, i, xindx);
    update( (indx << 1) + 1,m + 1, r, i, xindx);

    if(seg[indx << 1].no > seg[ (indx << 1) + 1].no){
        seg[indx] = seg[indx << 1];
    }
    else if(seg[indx << 1].no == seg[ (indx << 1) + 1].no ){
        seg[indx] = seg[indx << 1];
        seg[indx].best2 = max(seg[indx << 1].best2, seg[ (indx << 1) + 1].best2);
    }
    else seg[indx] = seg[ ( indx << 1) + 1];

    //cout << indx<< " " << l << " " << r << "  " << i << " " << xindx << endl;
    //cout << seg[indx].no << " " << seg[indx].best2 << " " << seg[indx].bestall << endl;
    seg[indx].bestall = max(seg[indx << 1].bestall, seg[ (indx << 1) + 1].bestall);
    return;
}




void solve(){
    
    sc1(n);

    vi v(n), vc, dec;

    for(int i = 0; i < n; i++){
    	sc1(v[i]);
    }
    vc = v;

    sort(all(v));

    for(int i = 0; i < n; i++){
        if(!pos[v[i]]) pos[v[i]] = i + 1;
    }

    unq.clear();
    build(1, 1, n);
    ll res = 0;
    int l = 1;


    for(int i = 1; i <= n; i++){
        cout << vc[i - 1] << endl;
        state temp = query(1, 1, n, 1, pos[vc[i - 1]]);
        cout << pos[vc[i - 1]] << endl;
        if(temp.no == 2){
            l = max(l, temp.best2 + 1);
            res += (i - l + 1);
            update(1, 1, n, pos[vc[i - 1]], i);
        cout << temp.no << " " << l << endl;
        }
        else{
            update(1, 1, n, pos[vc[i - 1]], i);
            res += (i - l + 1);
        }

        unq.insert(pos[ vc[i - 1] ]);

        puts("");
    }

    cout << res << endl;


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

    sc1(test);

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