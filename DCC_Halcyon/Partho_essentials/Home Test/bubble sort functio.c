
///bubble sort
#include<stdio.h>
#define swap(a,b)  a ^= b, b ^= a, a ^= b

void sort(int *arr,int n,int lesser){
    int i, j;
    for(i = 0;i<n;i++){
        for(j = i;j<n;j++){
            if(!lesser && arr[i]<arr[j]) swap(arr[i],arr[j]);
            if( lesser && arr[i]>arr[j]) swap(arr[i],arr[j]);
        }
        printf("\n");
    }
}

int arr[1000000];
int main(){
    int i, j,n,order;
    while(1){
        scanf("%d%d",&n,&order);
        for(i = 0;i<n;i++) scanf("%d",arr+i);
        sort(arr,n,order);
        for(i = 0; i < n; i++) printf("%d ",arr[i]); putchar('\n');
    }

    return 0;
}




/*#include <bits/stdc++.h>
using namespace std;
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
#define ROF(i, x, y)        for(int i=int(x-1); i>=int(y); i--)
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
template <class T> inline T bigMod(T p,T e,T M){ ll ret = 1; for(; e > 0; e >>= 1){ if(e & 1) ret = (ret * p) % M; p = (p * p) % M; } return (T) ret;}
template <class T> inline T modInverse(T a,T M){return bigMod(a,M-2,M);}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T lcm(T a,T b) {a=abs(a);b=abs(b); return (a/gcd(a,b))*b;}
template <class T> inline string int2String(T a){ostringstream str; str<<a; return str.str();}
const int dr[] = { 0,  1,  0, -1,        -1,  1,  1, -1,     -2, -2,  2,  2, -1, -1,  1,  1};
const int dc[] = { 1,  0, -1,  0,         1,  1, -1, -1,     -1,  1, -1,  1, -2,  2, -2,  2};


/// Constants
#define endl                '\n'
#define inv                 405641995LL
#define MAX                 2250000000000
#define MOD                 1000000007
//#define base                1000000007
#define eps                 1e-9
#define INF                 0x3f3f3f3f3f3f3f3f
#define inf                 0x3f3f3f3f
#define PI                  (2.0*acos(0.0))  // 3.1415926535897932
#define Log(b,x)            (log(x)/log(b))

/// Debug
#define dbg(x)              cout << #x << " = " << x << endl
#define out(a,T,str)        copy(a.begin(),a.end()-1,ostream_iterator<T>(cout,str)),cout<<a.back()<<endl
#define out2(a,b)           cout<<a<<" "<<b<<endl
#define out3(a,b,c)         cout<<a<<" "<<b<<" "<<c<<endl
#define out4(a,b,c,d)       cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl
#define out5(a,b,c,d,e)     cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<endl

void fileIO()
{
    #ifndef ONLINE_JUDGE
        freopen("//home//pranto//Desktop//input.txt","r",stdin);
        freopen("//home//pranto//Desktop//output.txt","w",stdout);
    #else
      // Read("immetric.in");
      // Write("immetric.out");
    #endif
}

/// Priority Queue custom compare
// bool cmp(const int &a, const int &b){ return a > b;}
// std::priority_queue<int, std::vector<int>, decltype(&cmp) > pq(cmp);

ll Sum(ll n, ll d){
    ll m = n/d;
    ll nth = 1 + d*((n-d)/d);
    return (m*(1+nth))>>1;
}

int main()
{
    //fastIO;
   // fileIO();  int start_s = clock();

    ll n; scll(n);
    vll v;
    for(ll d = 1; d*d <= n; d++){
        if(n%d == 0){
            v.pb(Sum(n,d));
            if(d != n/d) v.pb(Sum(n,n/d));
        }
    }

    sort(all(v));
    out(v,ll," ");

    // int end_s=clock();
    // printf("\nTime :: %.2lf\n", (double)(end_s-start_s)/CLOCKS_PER_SEC);
    return 0;
}

*/
