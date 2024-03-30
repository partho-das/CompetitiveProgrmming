#include <bits/stdc++.h>
using namespace std;
 
//____________________________________________________________________________________________________________________________________
#define PI  2*acos(0.0)
#define pf  printf
#define sc  scanf
#define ff  first
#define ss  second
#define mp  make_pair
#define pb  push_back
typedef long long ll;
typedef unsigned long long ull;
typedef std::vector<int> vi;
typedef vector<long long> vll ;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define sc1(n)         sc("%d",&n);
#define sc2(n, m)      sc("%d%d", &n, &m);
#define sc3(m, n, o)   sc("%d%d%d", &m, &n, &o);
#define scl(n)         sc("%lld", &n);
#define scll(n, m)     sc("%lld%lld", &n, &m);
#define sclll(n, m, o) sc("%lld%lld%lld", &n, &m, &o);
#define scf(f)         sc("%f",&f);
#define pn(n)        printf("%d\n", n);
#define ps(str)      printf("%s\n", str);
#define FOR(i,a,n)   for( int i = a; i < n; i++)
#define TEST(test)   for(int cse = 1; cse <= test; cse++)
#define all(x) (x).begin(), (x).end()
#define fap(x) cout << __LINE__ << " says: " << #x << " = " << x << "\n"
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const ll INF = 2000000000000000000LL;
const int inf = 0x3f3f3f3f;
ll MOD =  1e9 + 7;
const long double EPS = 1e-9;
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline double my_sqrt(T n) { double high = n, low = 0, mid, ans; int cnt = 100; while(cnt--) { mid = low + (high - low) / 2; if(mid * mid <= n) ans = mid, low = mid; else high = mid; } return ans; }
template<class T> inline T bigmod(T b, T p){ if(p <= 0 || b == 0) return 1; if(p & 1) return (b * bigmod(b, p - 1)) % MOD; ll x = bigmod(b, p >> 1); return (x * x) % MOD;}
//____________________________________________________________________________________________________________________________________

const int maxn = 5e5;
vi iv, v, fix;
int change[maxn + 5], n, k, res;

bool check(){

    fix.pb(n + 1);
    v.pb(inf);

    int first = -inf, second = v[ fix[0]  - 1], l = -1, r = 0;
    for(int i = 0; i < n; i++){
        if(i == fix[r] - 1){
        
            change[i] = 2;
            
            if(v[i] < first || v[i] > second ||
            abs(first - v[i]) < abs(i - (fix[l] - 1) ) || abs(second - v[i]) < abs( (fix[r] - 1) - i))
            return 1;
            
            l++, r++;
             
            first = v[ fix[l] - 1], second = v[ fix[r] - 1]; 
        }
        else{
            if( v[i] <= first || v[i] >= second ||
             abs(first - v[i]) < abs(i - (fix[l] - 1) ) || abs(second - v[i]) < abs(fix[r] - 1) - i){
                change[i] = 1, res++;
            }
        }


    }
    return 0;
}

int seg[maxn * 3];

int query(int indx, int l, int r, int i, int j){
    if( r < i || l > j) return -inf;

    if( i <= l && r <= j) return seg[indx];
    int mid = l + ( r - l >> 1) ;

    return max( query(indx << 1, l, mid, i, j), query( (indx << 1) + 1, mid + 1, r, i, j));
}

void update(int indx, int l, int r, int i, int add){
    if( l > i|| r < i) return;

    if(l == r && l == i){
        seg[indx] = add + 1;
        return;
    }

    int mid = l + ( r - l >> 1) ;

    update( (indx << 1) , l, mid, i, add);
    update( (indx << 1) + 1, mid + 1, r, i, add);
    seg[indx] = max( seg[indx << 1], seg[ ( indx << 1) + 1]);

    return;
}


int main()
{
#ifdef PARTHO
    freopen("/home/partho/Desktop/IO/input.txt","r",stdin);
    freopen("/home/partho/Desktop/IO/output.txt","w",stdout);
    int start_time = clock();
#endif
//FastIO;



sc2(n, k);

v.resize(n);
iv.resize(n);
fix.resize(k);

FOR(i, 0, n) sc1(v[i]);
FOR(i, 0, k) sc1(fix[i]);


int ck = 0;
if(k > 0)
ck = check();

for(int i = 0; i < n; i++) 
iv[i] = v[i] - i;

v = iv;

iv.pb(-inf);
sort(all(iv));


if(ck){
    puts("-1");
}
else{

    int l = 0, r, cnt;    
    for(int i = 0; i < n; i++){
        if(change[i] == 1) continue;

        r = (int)(lower_bound(all(iv), v[i]) - iv.begin());
        cnt = query(1, 0, n, l, r);

        update(1, 0, n, r, cnt);

        if(change[i] == 2){
            l = lower_bound(all(iv), v[i]) - iv.begin();
        }

    }
    cnt = max( n - seg[1], res);

    printf("%d\n", cnt);
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