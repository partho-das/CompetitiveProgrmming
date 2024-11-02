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
template <class T> inline long long my_sqrt(T n) { double high = n, low = 0, mid, ans; int cnt = 100; while(cnt--) { mid = low + (high - low) / 2; if(mid * mid <= n) ans = mid, low = mid; else high = mid; } return ans; }
template <class T> inline T bigmod(T b, T p){ if(p <= 0 || b == 0) return 1; if(p & 1) return (b * bigmod(b, p - 1)) % MOD; ll x = bigmod(b, p >> 1); return (x * x) % MOD;}
#ifdef PARTHO
#define dbg(x) cout << __LINE__ << " says: " << #x << " = " << x << "\n"
#else
#define dbg(x)
#endif
//____________________________________________________________________________________________________________________________________

void solve(){

    int n;
    sc1(n);

    vector<vector<int>>dataSet(n);
    vector<int>dayesInYear(n, 0);
    for(int i = 0; i < n; i++){
        int months;
        sc1(months);
        for(int j = 0; j < months; j++){
            int day;
            sc1(day);
            dayesInYear[i] += day;
            if(dataSet[i].size() == 0) dataSet[i].pb(day);
            else dataSet[i].pb(dataSet[i].back() + day);
        }
    }

    int q;
    sc1(q);

    for(int qindx = 1; qindx <= q; qindx++){
        int t1, t2;
        sc2(t1, t2);
        int d, m, y;
        sc3(d, m, y);
        int daycount = (y - 1) * dayesInYear[t1 - 1];
        if(m != 1) daycount += (dataSet[t1 - 1][m - 2]);
        daycount += d;
        int y2 = daycount / dayesInYear[t2 - 1] + 1;
        daycount = daycount % dayesInYear[t2 - 1];

        int m2 = 1, d2 = 1;
        if(daycount == 0) {
            m2 = dataSet[t2 - 1].size();
            if(m2 > 1) d2 = dataSet[t2 - 1].back() - dataSet[t2 - 1][dataSet[t2 - 1].size() - 2];
            else d2 = dataSet[t2 - 1].back();
            y2--;

        }
        for(int i = 0; i < dataSet[t2 - 1].size() && daycount; i++){
            if(dataSet[t2 - 1][i] >= daycount) {
                m2 = i + 1;
                if(i == 0) d2 = daycount;
                else d2 = daycount - dataSet[t2 - 1][i - 1];
                break;
            }
        }
        cout <<"Query " << qindx << ": " << d2 << " " << m2 << " " << y2 << endl;

    }
}

int main() {
    #ifdef PARTHO
        freopen("/home/partho/Desktop/Code/IO/input.txt","r",stdin);
        freopen("/home/partho/Desktop/Code/IO/output.txt","w",stdout);
        int start_time = clock();
    #endif
    //FastIO;

    int test = 1;

    // sc1(test);

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


