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
template<class T> inline T bigmod(T b, T p){ if(p <= 0) return 1; if(p & 1) return (b * bigmod(b, p - 1)) % MOD; ll x = bigmod(b, p >> 1); return (x * x) % MOD;}
//____________________________________________________________________________________________________________________________________


int main()
{
#ifdef PARTHO
    freopen("/home/partho/Desktop/IO/input.txt","r",stdin);
    freopen("/home/partho/Desktop/IO/output.txt","w",stdout);
    int start_time = clock();
#endif
//FastIO;
 
int n, q;

sc2(n, q);

set <int> st, gap;
map<int, int> freq;


for(int i = 0; i < n; i++)
{   int value;
    sc1(value);
    st.insert(value);
}
ll move = 0;

auto it = st.begin(), it2  = it;
it2++;

while(it2 != st.end() )
{
    int dif = *it2 - *it;

    gap.insert(dif);
    it++, it2++;
    freq[dif]++;
}
auto it3 = gap.end();
if(gap.size())
{ 
    it3--, move = *it3;
    it2--;
    move = *it2 - *st.begin() - move; 
}
printf("%lld\n", move);

while(q--)
{
    int cmd, x;

    sc2(cmd, x);

    if(cmd == 1)
    {
        int a = 0, b = 0;
        
        if(st.size() == 0) st.insert(x);
        else
        {

            auto endit = st.end(), firstit = st.begin();
            endit--;

            if(x < *firstit)
            {
                a = *firstit - x;
                st.insert(x);
                freq[a]++;
                gap.insert(a);
            }
            else if(x > *endit)
            {
                b = x - *endit;
                st.insert(x);
                freq[b]++;
                gap.insert(b);
            }
            else
            {
                st.insert(x);
                auto it = st.lower_bound(x);

                it--, firstit = it;
                it++, it++, endit = it;
                a =  x - *firstit, b = *endit - x;

                freq[a+b]--;
                if(!freq[a+b]) gap.erase(a + b);
                
                gap.insert(a);
                freq[a]++;
                gap.insert(b);
                freq[b]++;

            }
        }       

    }
    else
    {

        int a = 0, b = 0;
        
        if(st.size() == 1) st.erase(x);
        else
        {

            auto endit = st.end(), firstit = st.begin();
            endit--;

            if(x == *firstit)
            {
                *firstit++;
                a = *firstit - x;
                freq[a]--;
                st.erase(x);
                if(!freq[a]) gap.erase(a);

            }
            else if(x == *endit)
            {
                *endit--;
                b = x - *endit;
                freq[b]--;
                if(!freq[b]) gap.erase(b);
                st.erase(x);

            }
            else
            {
                auto it = st.lower_bound(x);

                firstit = --it,it++, endit = ++it;
                a =  x - *firstit, b = *endit - x;

                freq[a+b]++;
                gap.insert(a + b);
                
                freq[a]--;
                freq[b]--;
                if(!freq[a]) gap.erase(a);
                if(!freq[b]) gap.erase(b);
                st.erase(x);
            }
        
        }       

    }
    move = 0;
    if(gap.size() >= 1){

        auto endit = st.end(), firstit = st.begin();
            endit--;

        auto gapit = gap.end();
        gapit--;

        move  = *endit - *firstit - *gapit;

    }

    printf("%lld\n", move);
    

    
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