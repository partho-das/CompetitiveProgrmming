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

const int maxn = 1e3;
int n;

multiset<int> mx;
set<int, greater<int> > st;
vi v(maxn + 5), res;


int mex()
{

    int m = 0;
    auto it = mx.begin();


    // for(auto it : mx) cout << it << " ";
    //     cout << endl;

    for(; it != mx.end();it++)
    {
        if( *it < m) continue;
        else if(*it == m) m++;
        else break;

    }
    //fap(m);
    return m;

}


int main()
{
#ifdef PARTHO
    freopen("/home/partho/Desktop/IO/input.txt","r",stdin);
    freopen("/home/partho/Desktop/IO/output.txt","w",stdout);
    int start_time = clock();
#endif
//FastIO;


int test;

sc1(test);

//cout << test << endl;
while(test--)
{



    sc1(n);
    mx.clear();
    res.clear();
    st.clear();
    //fap(n);

    for(int i = 0; i < n; i++)
    {
        sc1(v[i]);
        mx.insert(v[i]);
        if(v[i] != i) st.insert(i);
    }

    //for(auto it : st) cout << "it = " << it << endl;

    while(!st.empty())
    {
        int m = mex(), pos = m;
        if(m == n) pos--, m--;
        
        //cout << m << " " << pos << endl;
        if(v[pos] != m)
        {    
            res.pb(pos + 1);
            mx.insert(m);
            auto dit = mx.find(v[pos]);
            mx.erase(dit);
            v[pos] = m;
            st.erase(m);
        }
        else
        {
            int now = *(st.begin());
            if(now == n) now--;
            res.pb(now + 1);
            //st.erase(st.begin());
            auto dit = mx.find(v[now]);
            mx.erase(dit);
            mx.insert(m);
            v[now] = m;
        }
    }

   

    printf("%d\n", (int)res.size());

    for(int i = 0; i < res.size(); i++)
    {
        printf("%d ", res[i]);
    }
    puts("");

    // for(int i = 0;i < n; i++)
    // {
    //     cout << v[i] << " ";
    // }
    // cout << endl;
    
    
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