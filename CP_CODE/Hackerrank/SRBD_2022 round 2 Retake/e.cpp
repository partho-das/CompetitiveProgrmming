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

const int maxn = 1e5, MAX = 17;
int sub[maxn + 5], par[maxn + 5][18], depth[maxn + 5], n, q;
vi adj[maxn + 5];

int dfs(int src, int parent, int d){
    int sz = 1;

    depth[src] = d;
    par[src][0] = parent;
    for(int i = 1; i <= MAX; i++){
        par[src][i] = par[par[src][i - 1]][i - 1];
    }

    for(int child : adj[src]){
        if(child != parent){
            sz += dfs(child, src, d + 1);
        }
    }

    return sub[src] = sz;
}

int LCA(int u, int v){
    if(depth[u] > depth[v]) swap(u, v);

    int diff = depth[v] - depth[u];

    for(int i = 0; i <= MAX; i++){
        if(diff & (1 << i)){
            v = par[v][i];
        }
    }
    if(u == v) return u;

    int lca = 0;
    for(int i = MAX; i >= 0; i--){
        if(par[u][i] == par[v][i]){
            lca = par[u][i];
        }
        else{
            u = par[u][i], v = par[v][i];
        }
    }
    return lca;

}

int dtime = 1, chainHead[maxn + 5], dis[maxn + 5], disindx[maxn + 5];
void HLD(int src, int par, int chainid){
    disindx[dtime] = src;
    dis[src] = dtime++;
    chainHead[src] = chainid;

    if(sub[src] == 1) return ;
    int mxsubtree = 1, indx = src;
    for(int child : adj[src]){
        if(child != par && mxsubtree < sub[src]){
            mxsubtree = sub[src];
            indx = child;
        }
    }
   
    HLD(indx, src, chainid);
    for(int child : adj[src]){
        if(child != par && child != indx){
            HLD(child, src, child);
        }
    }
    return;
}



struct segment{
    int freq[62];
    segment(){
        for(int i = 0; i < 62; i++){
            freq[i] = 0;
        }
    }
    int get_pos(char ch){
        if(ch >= 'a' && ch <= 'z') return ch - 'a';
        else if(ch >= 'A' && ch <= 'Z') return ch - 'A' + 26;
        else return ch - '9' + 52;
    }
    
    void pos_freq_add(char ch, char ch2){
        freq[get_pos(ch)]--;
        freq[get_pos(ch2)]++;
        return;
    }
    segment operator + (segment const &b)const {
        segment temp;
        for(int i = 0; i < 61; i++){
            temp.freq[i] = freq[i] + b.freq[i];
        }
        return temp;
    }
    segment operator - (segment const &b)const {
        segment temp;
        for(int i = 0; i < 61; i++){
            temp.freq[i] = freq[i] - b.freq[i];
        }
        return temp;
    }
    void print_freq(){
        for(int i = 0; i < 61; i++){
            cout << i << " " << freq[i] << endl;
        }
        cout << endl;
    }



};

string str;
struct segment_tree {
   segment *seg;
   segment_tree(){
        seg = new segment[4 * maxn + 5];
   }
   void build(int indx, int l, int r){
        if(l == r){
            seg[indx].freq[seg[indx].get_pos(str[ disindx[l] ])]++;
            
            return;
        }

        int mid = l + (r - l) / 2;

        build(indx << 1, l, mid);
        build((indx << 1) + 1, mid + 1, r);
        seg[indx] = seg[indx << 1] + seg[ (indx << 1) + 1];
        return;
   }
   void update(int indx, int l, int r, int i, char ch){
        if(i < l || i > r || l > r) return;
        if( l == r && l == i){
            seg[indx].pos_freq_add(str[disindx[i]], ch);
            str[disindx[i]] = ch;
            return;
        }

        int mid = l + (r - l) / 2;

        update(indx << 1, l, mid, i, ch);
        update((indx << 1) + 1, mid + 1, r, i, ch);
        seg[indx] = seg[indx << 1] + seg[(indx << 1) + 1];
        return;
   }
   segment query(int indx, int l, int r, int i, int j){
        if(j < l || i > r || l > r) {
            segment temp;
            return temp;
        }
        if(i <= l && r <= j){
            return seg[indx];
        }
        int mid = l + (r - l) / 2;
        return query(indx << 1, l, mid, i, j) + query((indx << 1) + 1, mid + 1 , r, i, j); 
   }
};


segment get_res(int u, int v, segment_tree &tree){
    segment res;
    while(chainHead[u] != chainHead[v]){
        int l = dis[chainHead[v]];
        int r = dis[v];
        res = res + tree.query(1, 1, n, l, r);
        v = par[chainHead[v]][0];
    }
    int l = dis[u];
    int r = dis[v];

    res = res + tree.query(1, 1, n, l, r);

    return res;
}


void solve(){
    
    sc2(n, q);
    cin >> str;
    str = '#' + str;

    for(int i = 0; i < n - 1; i++){
        int u, v;
        sc2(u, v);
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs(1, 0, 0);
    HLD(1, 0, 1);

    segment_tree tree1;
    tree1.build(1, 1, n);
    while(q--){
        int type;
        sc1(type);

        if(type == 2){
            int pos;
            char ch;
            scanf("%d %c",&pos, &ch);
            tree1.update(1, 1, n, dis[pos], ch);
        }
        else{
            int u, v;
            sc2(u, v);

            segment res;
            int lca = LCA(u, v);
            if(depth[u] > depth[v]) swap(u, v);
            
            res = get_res(lca, v, tree1);
            if(lca != u){
                res = res + get_res(lca, u, tree1);
            }
            res = res - get_res(lca, lca, tree1);

            int ck = 1, cnt = -1;
            for(int i = 0; i < 61; i++){
                if(res.freq[i] > 0){
                    if(cnt == -1) cnt = res.freq[i];
                    if(cnt != res.freq[i]){
                        ck = 0;
                        break;
                    }
                }
            }

            puts(ck ? "Yes" : "No");
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
    int test = 1;


    while(test--){
        solve();
    }
    #ifdef PARTHO
        int end_time = clock();
        printf("Time = %.4f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif
    return 0;
}
