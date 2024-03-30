#include <bits/stdc++.h>
using namespace std;
 
//____________________________________________________________________________________________________________________________________
 
#define PI  2*acos(0.0)
#define pf  printf
#define sf  scan
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
#define sc(n)       sf("%d",&n);
#define scf(f)      sf("%f",&f);
#define FOR(i,a,n)  for(int i = a; i < n; i++)
#define TEST(test)  for(int cse = 1; cse <= test; cse++)
#define all(x) (x).begin(), (x).end()
#define fap(x) cout << __LINE__ << " says: " << #x << " = " << x << "\n"
#define FastIO ios::sync_with_stdio(false);;
const ll INF = 2000000000000000000LL;
const int inf = 0x3f3f3f3f;
const long double EPS = 1e-9;
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline double my_sqrt(T n) { double high = n, low = 0, mid, ans; int cnt = 100; while(cnt--) { mid = low + (high - low) / 2; if(mid * mid <= n) ans = mid, low = mid; else high = mid; } return ans; }
//____________________________________________________________________________________________________________________________________
 
const int maxn = 5e6 + 5;
bool is_prime[maxn];
std::vector<ll> primes;
unsigned long long phi[maxn];
void phigen()
{
 
    for(int i = 1; i <= maxn - 5; i++) phi[i] = i;
 
    for(ll i = 2; i * i <= maxn - 5; i++)
    {
        if(is_prime[i] == 0)
        {
            //fap(i);
        for(ll j =  i * i; j <= maxn - 5; j+= i){
                is_prime[j] = 1;
            }
        }
    }
    for(int i  = 2;i <= maxn - 5; i++)
    {
        if(!is_prime[i])
        {
         primes.pb(i);
        // fap(i);
        }
    }
 
    //fap(primes.size());
    //cout << primes.back();
 
    for(int i = 0; i < primes.size(); i++)
    {
        for(int j = primes[i]; j <= maxn - 2; j+= primes[i])
        {
            phi[j] /= primes[i];
            phi[j] *= primes[i] - 1;
            //cout << j << endl;
        }
      //fap(primes[i]);
    }
 
 
 
    for(int i = 2; i <= maxn - 2; i++)
    {
        //fap(phi[i]);
        phi[i] *= phi[i];
    }
 
    for(int i = 2; i <= maxn - 2; i++)
    {
       phi[i] = phi[i] + phi[i - 1];
       //cout << phi[i] << endl;
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
FastIO;
 
 phigen();
 
 
 int test, tc = 1;
 
 cin >> test;
 
 while(test--)
 {
    int l, r;
    cin >> l >> r;
 
    if(l > r) swap(l, r);
 
    cout << "Case " << tc++ << ": ";
    cout << (unsigned long long)(phi[r] - phi[l - 1]);
    cout << '\n';
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