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

const int maxn = 2e2;
int n, m, t = 1, visitf[maxn + 5][maxn + 5], visitj[maxn + 5][maxn + 5];
char grid[maxn + 5][maxn + 5];

int dirx[] = {0, 0, 1, -1};
int diry[] = {1, -1, 0, 0};


bool isval(int x, int y){
    //cout << x << " "<<  y << " " << (x >= 0 && x < n && y >= 0 && y < m) << endl;
    return x >= 0 && x < n && y >= 0 && y < m && !visitf[x][y] && grid[x][y] != '#';
}

void print_visit(){
    cout << "visitj = " << endl;
    FOR(i, 0, n){
        FOR(j, 0, m){
            cout << visitj[i][j] << " ";
        }
        cout << endl;
    }

    cout <<"visitf = " <<  endl;

      FOR(i, 0, n){
        FOR(j, 0, m){
            cout << visitf[i][j] << " ";
        }
        cout << endl;
    }

    cout << "------------" << endl;

}
int bfs(int sx, int sy){

    queue<pii>Qj, Qf;

    Qj.push({sx, sy});
    visitj[sx][sy] = 1;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 'F') Qf.push({i, j}), visitf[i][j] = 1;
        }
    }


    while(!Qj.empty()){

        queue<pii>temp;
        while(!Qf.empty()){
            pii now = Qf.front();
            Qf.pop();

            for(int i = 0; i < 4; i++){
                pii nxt = {now.ff + dirx[i], now.ss + diry[i]};
            //cout << now.ff << " " << now.ss << " " << nxt.ff << " " << nxt.ss << endl;
                if(isval(nxt.ff, nxt.ss)) temp.push(nxt), visitf[nxt.ff][nxt.ss] = 1;
            }
        }
        Qf = temp;
        while(!temp.empty()) temp.pop();

        //cout << Qf.size() << endl;

        while(!Qj.empty()){
            pii now = Qj.front();
            Qj.pop();

            for(int i = 0; i < 4; i++){
                pii nxt = {now.ff + dirx[i], now.ss + diry[i]};
                if(isval(nxt.ff, nxt.ss) && !visitj[nxt.ff][nxt.ss]){
                    temp.push(nxt), visitj[nxt.ff][nxt.ss] = visitj[now.ff][now.ss] + 1;
                    if(nxt.ff == 0 || nxt.ff == n - 1 || nxt.ss == 0 || nxt.ss == m - 1) return visitj[nxt.ff][nxt.ss];
                }
            }
        }
        //print_visit();
        Qj = temp;
    }
    return -1;
}

void solve(){
    
    sc2(n, m);

    int sx, sy;
    for(int i = 0; i < n; i++){
        getchar();
        for(int j = 0; j < m; j++){
            grid[i][j] = getchar();
            visitf[i][j] = visitj[i][j] = 0;
            if(grid[i][j] == 'J') sx = i, sy = j;
            //cout << grid[i][j];
        }
        //puts("");
    }   
    //cout << sx << sy << endl;

    int res = bfs(sx, sy);

    if(res == -1){
        printf("Case %d: IMPOSSIBLE\n", t++);
    }
    else printf("Case %d: %d\n", t++, res);


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