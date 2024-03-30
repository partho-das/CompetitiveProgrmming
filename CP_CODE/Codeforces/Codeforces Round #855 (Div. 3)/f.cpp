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
template <class T> inline string to_string(const pair<T,T> &p) {
    return "{" + to_string(p.first) + "," + to_string(p.second) + "}";  
}
#ifdef PARTHO
#define dbg(x) cout << __LINE__ << " says: " << #x << " = " << x << "\n"
#else
#define dbg(x)
#endif
//____________________________________________________________________________________________________________________________________

const int maxn = 50;
vector<string>grid(maxn + 2);
int visited[maxn + 5][maxn + 5], n, m;


bool valid(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == '*' && !visited[x][y];
}

int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0}, condx[] = {1, -1, 1, -1}, condy[] { 1, -1, -1, 1 };

vector<pii>found;
bool dfs(int x, int y, int col){
    visited[x][y] = col;
    found.pb({x, y});

    int ck = 1;

    for(int i = 0; i < 4; i++){
        if(valid(x + dx[i], y + dy[i])){
            ck = ck & dfs(x + dx[i], y + dy[i], col);
        }
    }

    if(!ck) return 0;

    for(int i = 0; i < 4; i++){
            //cout << x + condx[i] << " " << y + condy[i] << " " << x << " " << y << " " << col << endl;
        if(valid(x + condx[i], y + condy[i])){
            if(visited[x + condx[i]] [y + condy[i] ] && visited[x + condx[i]][y + condy[i]] != col){
                ck = 0;
            }
        }
    }
    return ck;
}
void solve(){
    
    sc2(n, m);

    memset(visited, 0, sizeof visited);

    for(int i = 0; i < n; i++){
        cin >> grid[i];
    }

    int ck = 1, col = 1;
    for(int i = 0; i < n && ck; i++){
        for(int j = 0; j < m && ck; j++){
            if(grid[i][j] == '*' && !visited[i][j]){
                found.clear();
                ck = ck & (dfs(i, j, col));
                col++;
                sort(all(found));

                if(found.size() != 3) ck = 0;
                else if(found[0].ff == found[1].ff && found[1].ff == found[2].ff) ck = 0;
                else if(found[0].ss == found[1].ss && found[1].ss == found[2].ss) ck = 0;


            }
        }
    }

    puts(ck ? "YES" : "NO");

    return;
}


int main() {
     #ifdef PARTHO
        freopen("/home/partho/Desktop/CODEFORCES/IO/input.txt","r",stdin);
        freopen("/home/partho/Desktop/CODEFORCES/IO/output.txt","w",stdout);
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
