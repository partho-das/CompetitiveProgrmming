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
#define sc1(n)      sc("%d",&n);
#define sc2(n, m)   sc("%d%d", &n, &m);
#define scf(f)      sc("%f",&f);
#define pn(n)       printf("%d\n", n);
#define ps(str)     printf("%s\n", str);
#define FOR(i,a,n)  for( int i = a; i < n; i++)
#define TEST(test)  for(int cse = 1; cse <= test; cse++)
#define all(x) (x).begin(), (x).end()
#define fap(x) cout << __LINE__ << " says: " << #x << " = " << x << "\n"
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const ll INF = 2000000000000000000LL;
const int inf = 0x3f3f3f3f;
const long double EPS = 1e-9;
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline double my_sqrt(T n) { double high = n, low = 0, mid, ans; int cnt = 100; while(cnt--) { mid = low + (high - low) / 2; if(mid * mid <= n) ans = mid, low = mid; else high = mid; } return ans; }
//____________________________________________________________________________________________________________________________________

ll n, MOD = (long long)(1ll << 32ll);
vll primes;
const int maxn = 1e8, sz = maxn / 32, sz2 = maxn / 256;

map<int, int> mep;
int is_prime[sz + 10];
unsigned int lcar[maxn + 5];

bool yn(int n)
{
    int indx = n >> 5, ck = n & 31;
    ck = 1 << ck;
    if( ck & is_prime[indx]) return 1;
    return 0;
}
void solve()
{
    //cout << sz << " sz2 " << sz2  << endl;
    for(int i = 3; i * i <= maxn; i+= 2)
    {

        if(!yn(i))
        {
            for(int j = i * i; j <= maxn; j+= 2*i)
            {
                unsigned int indx = j >> 5, ck = j & 31;
                //if(indx > sz) cout << "RE" << endl;
                //fap(ck);
                ck = (1ll << ck);
                //cout << ck << endl;
                is_prime[indx] = is_prime[indx] | ck;
            }
        }
    }

    primes.pb(2);

    ll indx = 0, pos;
    for(int i = 0; i <= maxn / 32 + 1; i++)
    {
        for(int j = 0; j < 32; j++, indx++)
        {
            if(indx < 3 || (indx & 1) == 0) continue;
            pos = 1 << j;
            if( (is_prime[i] & pos) == 0) primes.pb(i * 32 + j);
        }
    }

    //cout << primes.size() << endl;

    for(int i = 0;i < maxn / 32 + 2; i++) is_prime[i] = 0;

    for(int i = 0; i < primes.size(); i++)
    {
        ll value = primes[i];

        while(value <= maxn)
        {
            indx = value >> 5, pos = value & 31, pos = 1 << pos;
            mep[value] = primes[i];
            //cout << value << endl;
            //if(value < 0) cout << value << endl;
            is_prime[indx] = is_prime[indx] | pos;
            value *= primes[i];
        }
    }

    ll lcm = 1;
    lcar[0] = 1;
    //cout << mep.size() << sizeof(mep) << endl;
    for(int i = 1; i <= maxn; i++)
    {
        indx = i >> 5, pos = i & 31, pos = 1 << pos;

        if(is_prime[indx] & pos) lcm = (long long)(lcm * mep[i]);
        lcm = lcm & ((1ll << 32) - 1);

        if( (i & ((1 << 8) - 1)) == 0)
            {
                lcm = lcm & ((1ll << 32) - 1);
                lcar[ i >> 8 ] = lcm;
                //if(lcar[i >> 8] < 0) cout << lcm << " " << lcar[i >> 8] << " wrong " << endl;
                //cout << i << " " << (i >> 7) << " " << lcm << endl;
            }

    }

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


int test, tc = 1;

sc1(test);

solve();
while(test--)
{
    sc("%lld", &n);

    ll lcm = 1;
    //cout << MOD << endl;

    int indx = n >> 8, pos;
    lcm = lcar[indx];
    //cout << indx << " " << lcar[indx] << endl;
    for(int i = indx * (256) + 1; i <= n; i++)
    {
        
        indx = i >> 5, pos = i & 31, pos = 1 << pos;
        if(is_prime[indx] & pos) lcm = (long long)(lcm * mep[i]);
        lcm = lcm & ((1ll << 32) - 1);
    }

    printf("Case %d: %lld\n",tc++ , lcm);

    //cout << (ll)(sizeof (is_prime)) << endl;
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