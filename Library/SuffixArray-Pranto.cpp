#include <bits/stdc++.h>
using namespace std;
// #include <ext/rope> //header with rope
// using namespace __gnu_cxx;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
 
 
/// Typedef
typedef long double ld;
typedef long long ll;
typedef unsigned long ul;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pld;
typedef vector< pii > vii;
 
#define pb                  push_back
#define ppb                 pop_back
#define MP                  make_pair
#define ff                  first
#define ss                  second
#define sf                  scanf
#define pf                  printf
#define loop(i, y)          for(int i=0; i<int(y); i++)
#define FOR(i, x, y)        for(int i=int(x); i<int(y); i++)
#define ROF(i, x, y)        for(int i=int(x)-1; i>=int(y); i--)
#define tr(it, container)   for(auto it = container.begin(); it != container.end(); it++)
#define Binary(x,b)         std::bitset< b >( x ).to_string()
#define fastIO              ios::sync_with_stdio(false);    cin.tie(nullptr);   cout.tie(nullptr)
#define ran(a, b)           ((((rand() << 15) ^ rand()) % ((b) - (a) + 1)) + (a))
#define CLR(x, y)           memset(x, y, sizeof(x))
#define sc(n)               sf("%d",&n)
#define sc2(a,b)            sf("%d%d",&a,&b)
#define sc3(a,b,c)          sf("%d%d%d",&a,&b,&c)
#define sc4(a,b,c,d)        sf("%d%d%d%d",&a,&b,&c,&d)
#define scll(n)             sf("%lld",&n)
#define scll2(a,b)          sf("%lld%lld",&a,&b)
#define scll3(a,b,c)        sf("%lld%lld%lld",&a,&b,&c)
#define scll4(a,b,c,d)      sf("%lld%lld%lld%lld",&a,&b,&c,&d)
#define bitCheck(N,in)      ((bool)(N&(1<<(in))))
#define bitOff(N,in)        (N&(~(1LL<<(in))))
#define bitOn(N,in)         (N|(1LL<<(in)))
#define bitFlip(a,k)        (a^(1LL<<(k)))
#define bitCount(a)         __builtin_popcount(a)
#define bitCountLL(a)       __builtin_popcountll(a)
#define bitRightMost(a)     __builtin_ctzll(a)
#define bitLeftMost(a)      (63-__builtin_clzll(a))
#define SQR(x)              ((x)*(x))
#define mxEq(a,b)           (a = max(a,b))
#define all(c)              c.begin(), c.end()
#define unq(v)              sort(all(v)), (v).resize(unique(all(v)) - v.begin())
#define common(a,b)         sort(all(a)), sort(all(b)), a.erase(set_intersection(all(a),all(b),a.begin()),a.end())
#define uncommon(a,b)       sort(all(a)), sort(all(b)), a.erase(set_symmetric_difference(all(a),all(b),a.begin()),a.end())
 
// uniform random generator -->
// uniform_int_distribution<int> dist(0, 1);
// default_random_engine gen;
 
// *X.find_by_order(k) //returns the kth largest element.(0-based)
// X.order_of_key(val) //returns the no. of values less than val
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; // C++98
// template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T> inline T bigMod(T p,T e,T M){ T ret = 1; for(; e > 0; e >>= 1){ if(e & 1) ret = (ret * p) % M; p = (p * p) % M; } return (T) ret;}
template <class T> inline T modInverse(T a,T M){return bigMod(a,M-2,M);}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T lcm(T a,T b) {a=abs(a);b=abs(b); return (a/gcd(a,b))*b;}
template <class T> inline string int2String(T a){ostringstream str; str<<a; return str.str();}
const int dr[] = { 0,  1,  0, -1,        -1,  1,  1, -1,     -2, -2,  2,  2, -1, -1,  1,  1};
const int dc[] = { 1,  0, -1,  0,         1,  1, -1, -1,     -1,  1, -1,  1, -2,  2, -2,  2};
 
 
/// Constants
//#define endl                '\n'
#define MAX                 2250000000000
#define MOD                 (int)(1e9+9)
//#define base                1000000007
#define eps                 1e-9
#define INF                 0x3f3f3f3f3f3f3f3f
#define inf                 0x3f3f3f3f // CLR(63)
#define PI                  (2.0*acos(0.0))  // 3.1415926535897932
#define Log(b,x)            (log(x)/log(b))

/// Debug
#define out(a,T,str)        copy(a.begin(),a.end()-1,ostream_iterator<T>(cout,str)),cout<<a.back()<<endl
#ifdef VAMP
    #define dbg(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template < typename Arg1 >
    void __f(const char* name, Arg1&& arg1){
        cout << name << " = " << arg1 << std::endl;
    }
    template < typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names+1, ',');
        cout.write(names, comma - names) << " = " << arg1 <<" | ";
        __f(comma+1, args...);
    }
#else
    #define dbg(...)
#endif
 
/// Priority Queue custom compare
// bool cmp(const int &a, const int &b){ return a > b;}
// std::priority_queue<int, std::vector<int>, decltype(&cmp) > pq(cmp);

namespace SuffixArray {
    const int maxn = 1e5+5, maxlog = 18;
    struct Suffix {
        int idx;
        pair<int,int> rank;
    }SA[maxn];
    int Rank[maxlog][maxn], N,LOG,len,lcp[maxn];

    inline bool cmp(const Suffix &a, const Suffix &b){ return a.rank < b.rank;}

    void build(string str){
        CLR(Rank,0);
        N = str.size();
        LOG = 1;
        int i;
        for(i = 0; i < N; i++) Rank[0][i] = int(str[i]), SA[i].rank = {0,0};
        for(len = 1; len>>1 < N; LOG++, len <<= 1){
            for(i = 0; i < N; i++){
                SA[i].rank = { Rank[LOG-1][i], (i+len < N) ? Rank[LOG-1][i+len] : -1};
                SA[i].idx = i;
            }
            sort(SA, SA+N, cmp);
            for(i = 0; i < N; i++){
                Rank[LOG][SA[i].idx] = 0<i && SA[i-1].rank == SA[i].rank ? Rank[LOG][SA[i-1].idx] : i;
            }
        }
        LOG--;
    }
    int find_LCP(int p, int q){
        int Lcp = 0;
        for(int i = LOG; i>=0 && p < N && q < N; i--){
            if(Rank[i][p] == Rank[i][q]){
                Lcp += 1LL<<i;
                p += 1LL<<i;
                q += 1LL<<i;
            }
        }
        return Lcp;
    }
    void Generate_LCP(){
        lcp[0] = 0;
        for(int i = 1; i < N; i++){
            lcp[i] = find_LCP(SA[i-1].idx,SA[i].idx);
        }
    }
}

int main(){
    #ifdef VAMP
        int start_s=clock();
        freopen("//home//pranto//Desktop//input.txt","r",stdin);
        freopen("//home//pranto//Desktop//output.txt","w",stdout);
    #endif
    //fastIO;
    //srand((rand()-time(NULL))%MOD);
    
    using namespace SuffixArray;

    string s("mississippi");
    build(s);
    Generate_LCP();
    FOR(i,0,N) dbg(SA[i].idx, s.substr(SA[i].idx));
    

    #ifdef VAMP
        int end_s=clock();    
        printf("\nTime :: %.2lf\n", (double)(end_s-start_s)/CLOCKS_PER_SEC);
    #endif
    return 0;
}