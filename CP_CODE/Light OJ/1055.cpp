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

const int maxn = 10;
int n, t = 1,visit[maxn + 5][maxn + 5][maxn + 5][maxn + 5][maxn + 5][maxn + 5];
vector<pii> src, dest;

char grid[maxn + 5][maxn + 5];

struct node{
    int x1, x2, x3, y1, y2, y3, c1, c2, c3;

    node(){}
    node(int _x1, int _y1, int _x2, int _y2, int _x3, int _y3){
        x1 = _x1, y1 = _y1, x2 = _x2, y2 = _y2, x3 = _x3, y3 = _y3; 
    }
};

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
bool isval(node now){
    return ((now.x1 >= 1 && now.x1 <= n && now.y1 >= 1 && now.y1 <= n) ) &&
     ((now.x2 >= 1 && now.x2 <= n && now.y2 >= 1 && now.y2 <= n)) && 
     ((now.x3 >= 1 && now.x3 <= n && now.y3 >= 1 && now.y3 <= n)) && !visit[now.x1][now.y1][now.x2][now.y2][now.x3][now.y3];
}

bool isval(int x, int y){
    return x >= 1 && x <= n && y >= 1 && y <= n && grid[x][y] != '#';
}

bool isdest(int x, int y){
    if( (x == dest[0].ff && y == dest[0].ss) || (x == dest[1].ff && y == dest[1].ss) || (x == dest[2].ff && y == dest[2].ss) ) return 1;
    //cout << x << " " << y << endl;
        return 0;
}
void reconfing(node &now, node &nxt){
    if(nxt.x1 == nxt.x2 && nxt.y1 == nxt.y2){
        if(now.x1 == nxt.x1 && now.y1 == nxt.y1) nxt.x2 = now.x2 , nxt.y2 = now.y2;
        else nxt.x1 = now.x1, nxt.y1 = now.y1;
    }
    if(nxt.x1 == nxt.x3 && nxt.y1 == nxt.y3){
        if(now.x1 == nxt.x1 && now.y1 == nxt.y1) nxt.x3 = now.x3 , nxt.y3 = now.y3;
        else nxt.x1 = now.x1, nxt.y1 = now.y1;
    }
    if(nxt.x2 == nxt.x3 && nxt.y2 == nxt.y3){
        if(now.x2 == nxt.x2 && now.y2 == nxt.y2) nxt.x3 = now.x3 , nxt.y3 = now.y3;
        else nxt.x2 = now.x2, nxt.y2 = now.y2;
    }
}
int bfs(){
    visit[src[0].ff][src[0].ss][src[1].ff][src[1].ss][src[2].ff][src[2].ss] = 1;

    queue<node>Q;
    Q.push(node(src[0].ff, src[0].ss, src[1].ff, src[1].ss, src[2].ff, src[2].ss));

    vi res;
    while(!Q.empty()){
        node now = Q.front();
        Q.pop();

       //cout << "now = " << now.x1 << " " << now.y1 << " " << now.x2 << " " << now.y2  << " " << now.x3 << " " << now.y3 << endl;
        if(isdest(now.x1, now.y1) && isdest(now.x2, now.y2) && isdest(now.x3, now.y3)){
            res.pb(now.c1 - 1);
            res.pb(now.c2 - 1);
            res.pb(now.c3 - 1);
            sort(all(res));
            //cout << now.c1 << " " << now.c2 << " " << now.c3 << endl;
            int sum = res.back();
            return sum;
        }


        for(int i = 0; i < 4; i++){

            node nxt = now;
            
            int nx = now.x1 + dx[i], ny = now.y1 + dy[i];
            if(isval(nx, ny)){
                nxt.x1 = nx, nxt.y1 = ny;
            }

        
            nx = now.x2 + dx[i], ny = now.y2 + dy[i];
            if(isval(nx, ny)){
                nxt.x2 = nx, nxt.y2 = ny;
            }
        
            nx = now.x3 + dx[i], ny = now.y3 + dy[i];
            if(isval(nx, ny)){
                nxt.x3 = nx, nxt.y3 = ny;
            }

            for(int i = 0; i <= 6; i++){
                reconfing(now, nxt);
            }   
          //cout << "nxt = " << nxt.x1 << " " << nxt.y1 << " " << nxt.x2 << " " << nxt.y2 << " " << nxt.x3 << " " << nxt.y3 << endl;


            if(isval(nxt)){
                visit[nxt.x1][nxt.y1][nxt.x2][nxt.y2][nxt.x3][nxt.y3] = visit[now.x1][now.y1][now.x2][now.y2][now.x3][now.y3] + 1;
                if(isdest(nxt.x1, nxt.y1)){
                    nxt.c1 =  visit[now.x1][now.y1][now.x2][now.y2][now.x3][now.y3] + 1;
                }
                if(isdest(nxt.x2, nxt.y2)){
                    nxt.c2 =  visit[now.x1][now.y1][now.x2][now.y2][now.x3][now.y3] + 1;
                }
                if(isdest(nxt.x3, nxt.y3)){
                    nxt.c3 =  visit[now.x1][now.y1][now.x2][now.y2][now.x3][now.y3] + 1;
                }
            //cout << nxt.x1 << " " << nxt.y1 << " " << nxt.x2 << " " << nxt.y2 << " " << nxt.x3 << " " << nxt.y3 << " " <<  visit[now.x1][now.y1][now.x2][now.y2][now.x3][now.y3] << endl;
                Q.push(nxt);
            }

        }
       // cout << endl;
    }
    return -1;

}
void solve(){
    
    sc1(n);


    src.clear(), dest.clear();
    for(int i = 1; i <= n; i++){
        getchar();
        for(int j = 1; j <= n; j++){
            grid[i][j] = getchar();
            if( grid[i][j] == 'A' || grid[i][j] == 'B' || grid[i][j] == 'C'){
                src.pb({i, j});
            }
            else if(grid[i][j] == 'X') dest.pb({i, j});
        }
    }

    // for(int i = 1; i <= n; i++){
    //     for(int j = 1; j <= n; j++){
    //         cout << grid[i][j];
    //     }
    //     cout << endl;
    // }
    grid[n + 1][n + 1] = '.';

    memset(visit, 0, sizeof visit);

    int res = bfs();

    if(res != -1){
        printf("Case %d: %d\n", t++, res);
    }
    else {
        printf("Case %d: trapped\n", t++);
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