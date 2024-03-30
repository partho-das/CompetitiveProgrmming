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

const int maxn = 1e6;
char S[maxn + 5];
struct Trie{
    struct trie_node{
        int end_of_word = 0;
        map<int, trie_node*>next_node;
        trie_node *parent = NULL;
    };
    trie_node root;
    void insert_string(string &str){
        trie_node *now = &root;
        int matchck = 1;
        for(int i = 0; i < (int)str.size(); i++){
            int index = str[i] - 'a';
            if( !matchck || now->next_node.find(index) == now->next_node.end()){
                now->next_node[index] = new trie_node;
                matchck = 0;
            }
            now->next_node[index]->parent = now;
            now = now->next_node[index];
        }
        while(1){
            now->end_of_word++;
            if(now->parent == NULL) break;
            now = now->parent;
            
        }
    }
    int find_string(string &str){
        trie_node *now = &root;

        for(int i = 0; i < (int)str.size(); i++){
            int index = str[i] - 'a';
            if(now->next_node.find(index) == now->next_node.end()){
                return 0;
            }
            now = now->next_node[index];
        }
        return now->end_of_word;
        
    }
    bool delete_string(string &str){
        trie_node *now = &root;
        for(int i = 0; i < str.size(); i++){
            int index = str[i] - 'a';
            if(now->next_node.find(index) == now->next_node.end()){
                return 0;
            }
            now = now->next_node[index];
        }
        if(now->end_of_word == true) {
            now->end_of_word = false;
            return 1;
        }
        return 0;
    }


};
void solve(){
    
    string str;
    int n, q;
    cin >> n >> q;

    Trie T1;
    while(n--){
        int type = 1;
        getchar();
        scanf("%s", S);
        str = S;
        if(type == 1){
            T1.insert_string(str);
        }
        else if(type == 2){
            cout << type << " " << T1.delete_string(str) << endl;
        }
        else{
            cout << type << " " << T1.find_string(str) << endl;
        }
    }
    while(q--){
        getchar();
        scanf("%s", S);
        str = S;
        printf("%d\n", T1.find_string(str));
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
