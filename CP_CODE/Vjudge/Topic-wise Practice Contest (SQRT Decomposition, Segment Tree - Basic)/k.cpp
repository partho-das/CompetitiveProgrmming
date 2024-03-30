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

const int maxn = 1e5 + 3e4 + 10;

int arr[maxn + 100], seg[maxn * 4 + 5], n, mx;


int query(int indx, int l, int r, int i, int j)
{
    if( j < l || r < i) return 0;
    if(i <= l && j >= r){
    return seg[indx];
    }
    int mid = l + (r - l >> 1);
    int a, b;
    a = query(indx << 1, l, mid, i, j), b = query( (indx << 1) + 1, mid + 1, r, i, j);
    return a + b;
}

int update(int indx, int l, int r, int i){
    if(i < l || i > r) return seg[indx];
    if(l == r && i == l)
    {
        seg[indx]++;
        return  seg[indx];
    }
    int mid = l + (r - l >> 1);
    int a , b;
    a = update(indx << 1, l, mid, i), b = update( (indx << 1) + 1, mid + 1, r, i);
    return  seg[indx] = a + b;
}


int call(int k){
   int low = 0, high = n - 1, mid = low + (high - low >> 1), res = -1;
   while(low <= high){
        int front_gone = query(1, 0,  mx, 0, mid);
        if(mid - front_gone < k){
            low = mid + 1;
        }
        else high = mid - 1;
        if(mid - front_gone == k) res = mid;
        mid = low + (high - low >> 1);
   }
    if(res >= 0)
    update(1, 0, mx, res);
   return res;

}


int main()
{
#ifdef PARTHO
    freopen("/home/partho/Desktop/IO/input.txt","r",stdin);
    freopen("/home/partho/Desktop/IO/output.txt","w",stdout);
    int start_time = clock();
#endif
//FastIO;

int test, tc = 1;

sc1(test);

while(test--){
    int q;
    sc2(n, q);

    memset(seg, 0, sizeof seg);
    for(int i = 0; i < n; i++) sc1(arr[i]);
    printf("Case %d:\n", tc++); 
    mx = n + q ;   
    while(q--)
    {
        char cmd;
        int k;

        getchar();
        cmd = getchar();
        sc1(k);
        if(cmd == 'c'){
            int res = call(k - 1);

            if(res >= 0)
            printf("%d\n", arr[res]);
            else puts("none");
        }
        else{
            arr[n] = k;
            n++;
        }
    }
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