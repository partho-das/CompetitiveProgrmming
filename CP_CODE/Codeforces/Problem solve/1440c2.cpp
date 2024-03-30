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
#define sc1(n)         sc("%d",&n);
#define sc2(n, m)      sc("%d%d", &n, &m);
#define sc3(m, n, o)   sc("%d%d%d", &m, &n, &o);
#define scl(n)         sc("%lld", &n);
#define scll(n, m)     sc("%lld%lld", &n, &m);
#define sclll(n, m, o) sc("%lld%lld%lld", &n, &m, &o);
#define scf(f)         sc("%lf",&f);
#define pn(n)          pf("%d\n", n);
#define FOR(i,a,n)   for( int i = a; i < n; i++)
#define all(x) (x).begin(), (x).end()
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const ll INF = 2000000000000000000LL;
const int inf = 0x3f3f3f3f;
const int MOD =  1e9 + 7;
const long double EPS = 1e-9;
template <class T> inline T gcd(T a,T b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
template <class T> inline double my_sqrt(T n)
{
    double high = n, low = 0, mid, ans;
    int cnt = 100;
    while(cnt--)
    {
        mid = low + (high - low) / 2;
        if(mid * mid <= n) ans = mid, low = mid;
        else high = mid;
    }
    return ans;
}
template <class T> inline T bigmod(T b, T p)
{
    if(p <= 0 || b == 0) return 1;
    if(p & 1) return (b * bigmod(b, p - 1)) % MOD;
    ll x = bigmod(b, p >> 1);
    return (x * x) % MOD;
}
#ifdef PARTHO
#define dbg(x) cout << __LINE__ << " says: " << #x << " = " << x << "\n"
#else
#define dbg(x)
#endif
//____________________________________________________________________________________________________________________________________
const int maxn = 100;
bool arr[maxn + 5][maxn + 5];

struct node
{
    pii a, b, c;
    node() {}
    node(pii x, pii y, pii z)
    {
        a = x, b = y, c = z;
    }
};

std::vector<node> res;
void four(pii a, pii b, pii c, pii d){
int cnt = 10;
while( cnt-- && arr[a.ff][a.ss] + arr[b.ff][b.ss] + arr[c.ff][c.ss] + arr[d.ff][d.ss] )
            {
                if(arr[a.ff][a.ss] + arr[b.ff][b.ss] + arr[c.ff][c.ss] + arr[d.ff][d.ss] == 4)
                {
                    res.pb( node( a, b, c ) );
                    arr[a.ff][a.ss] = arr[a.ff][a.ss] ^ 1;
                    arr[b.ff][b.ss] = arr[b.ff][b.ss] ^ 1;
                    arr[c.ff][c.ss] = arr[c.ff][c.ss] ^ 1;
                }
                else if(arr[a.ff][a.ss] + arr[b.ff][b.ss] + arr[c.ff][c.ss] + arr[d.ff][d.ss] == 1)
                {
                    if(arr[a.ff][a.ss] || arr[b.ff][b.ss] || arr[c.ff][c.ss])
                    {
                        res.pb( node( a, b, c));
                        arr[a.ff][a.ss] = arr[a.ff][a.ss] ^ 1;
                        arr[b.ff][b.ss] = arr[b.ff][b.ss] ^ 1;
                        arr[c.ff][c.ss] = arr[c.ff][c.ss] ^ 1;
                    }
                    else
                    {
                    	res.pb( node( d, b, c ) );
                    	arr[d.ff][d.ss] = arr[d.ff][d.ss] ^ 1;
                        arr[b.ff][b.ss] = arr[b.ff][b.ss] ^ 1;
                        arr[c.ff][c.ss] = arr[c.ff][c.ss] ^ 1;
                    }

                }

                else if(arr[a.ff][a.ss] + arr[b.ff][b.ss] + arr[c.ff][c.ss] + arr[d.ff][d.ss] == 2)
                {
                    if(arr[a.ff][a.ss] + arr[b.ff][b.ss] + arr[c.ff][c.ss] == 1)
                    {
                        res.pb( node(a, b, c));
                        arr[a.ff][a.ss] = arr[a.ff][a.ss] ^ 1;
                        arr[b.ff][b.ss] = arr[b.ff][b.ss] ^ 1;
                        arr[c.ff][c.ss] = arr[c.ff][c.ss] ^ 1;
                    }
                    else if( arr[a.ff][a.ss] + arr[b.ff][b.ss] + arr[d.ff][d.ss] == 1)
                    {
                        res.pb( node(a, b, d));
                        arr[a.ff][a.ss] = arr[a.ff][a.ss] ^ 1;
                        arr[b.ff][b.ss] = arr[b.ff][b.ss] ^ 1;
                        arr[d.ff][d.ss] = arr[d.ff][d.ss] ^ 1;
                    }
                    else if(arr[a.ff][a.ss] + arr[c.ff][c.ss] + arr[d.ff][d.ss] == 1)
                    {
                        res.pb( node(a, c, d));
                        arr[a.ff][a.ss] = arr[a.ff][a.ss] ^ 1;
                        arr[c.ff][c.ss] = arr[c.ff][c.ss] ^ 1;
                        arr[d.ff][d.ss] = arr[d.ff][d.ss] ^ 1;
                    }
                    else if( arr[b.ff][b.ss] + arr[c.ff][c.ss] + arr[d.ff][d.ss] == 1)
                    {
                        res.pb( node( b, c, d ) );
                        arr[b.ff][b.ss] = arr[b.ff][b.ss] ^ 1;
                        arr[c.ff][c.ss] = arr[c.ff][c.ss] ^ 1;
                        arr[d.ff][d.ss] = arr[d.ff][d.ss] ^ 1;
                    }
                }

                else
                {

                    if(!arr[a.ff][a.ss])
                    {
                        res.pb( node( b, c, d ) );
                        arr[b.ff][b.ss] = arr[b.ff][b.ss] ^ 1;
                        arr[c.ff][c.ss] = arr[c.ff][c.ss] ^ 1;
                        arr[d.ff][d.ss] = arr[d.ff][d.ss] ^ 1;
                    }
                    else if(!arr[b.ff][b.ss])
                    {
                        res.pb( node( a, c, d ));
                        arr[a.ff][a.ss] = arr[a.ff][a.ss] ^ 1;
                        arr[c.ff][c.ss] = arr[c.ff][c.ss] ^ 1;
                        arr[d.ff][d.ss] = arr[d.ff][d.ss] ^ 1;
                    }
                    else if(!arr[c.ff][c.ss])
                    {
                        res.pb( node(a, b, d));
                        arr[a.ff][a.ss] = arr[a.ff][a.ss] ^ 1;
                        arr[b.ff][b.ss] = arr[b.ff][b.ss] ^ 1;
                        arr[d.ff][d.ss] = arr[d.ff][d.ss] ^ 1;
                    }
                    else
                    {
                        res.pb( node(a, b, c));
                        arr[a.ff][a.ss] = arr[a.ff][a.ss] ^ 1;
                        arr[b.ff][b.ss] = arr[b.ff][b.ss] ^ 1;
                        arr[c.ff][c.ss] = arr[c.ff][c.ss] ^ 1;
                    }

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

    int test;

    sc1(test);

    while(test--)
    {
        int n, m;

        sc2(n, m);

        getchar();
        res.clear();
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                char ch;
                scanf("%c", &ch);
                arr[i][j] = ch - '0';
            }
            getchar();
        }
        if(m == 2)
        {
            for(int i = 0; i < n - 2; i++)
            {
                if(arr[i][0] || arr[i][1])
                {

                    if(arr[i][0] && arr[i][1])
                    {
                        res.pb( node({i, 0}, {i, 1}, {i + 1, 0}) );
                       	arr[i][0] = arr[i][0] ^ 1;
                       	arr[i][1] = arr[i][1] ^ 1;
                        arr[i + 1][0] = arr[i + 1][0] ^ 1;
                    }
                    else if(arr[i][0])
                    {
                        res.pb( node({i, 0}, {i + 1, 0}, {i + 1, 1}) );
                        arr[i][0] = arr[i][0] ^ 1;
                        arr[i + 1][0] = arr[i + 1][0] ^ 1;
                        arr[i + 1][1] = arr[i + 1][1] ^ 1;
                    }
                    else
                    {
                        res.pb( node({i, 1}, {i + 1, 0}, {i + 1, 1}) );
                        arr[i][1] = arr[i][1] ^ 1;
                        arr[i + 1][0] = arr[i + 1][0] ^ 1;
                        arr[i + 1][1] = arr[i + 1][1] ^ 1;
                    }
                }
            }
          	four({n - 2, 0}, {n - 2, 1}, {n - 1, 0}, {n - 1, 1});
        }
        else
        {
            for(int i = 0; i < n - 1; i += 2)
            {
                for(int j = 0; j < m - 2; j++)
                {
                    if(arr[i][j] || arr[i + 1][j])
                    {
                        if(arr[i][j] && arr[i + 1][j])
                        {
                            res.pb( node({i, j}, {i + 1, j}, {i, j + 1}) );
                            arr[i][j] = arr[i][j] ^ 1;
                            arr[i + 1][j] = arr[i + 1][j] ^ 1;
                            arr[i][j + 1] = arr[i][j + 1] ^ 1;
                        }
                        else if(arr[i][j])
                        {
                            res.pb( node({i, j}, {i, j + 1}, {i + 1, j + 1}) );
                            arr[i][j] = arr[i][j] ^ 1;
                            arr[i][j + 1] = arr[i][j + 1] ^ 1;
                            arr[i + 1][j + 1] = arr[i + 1][j + 1] ^ 1;
                        }
                        else
                        {
                            res.pb( node({i + 1, j}, {i, j + 1}, {i + 1, j + 1}) );
                            arr[i + 1][j] = arr[i + 1][j] ^ 1;
                            arr[i][j + 1] = arr[i][j + 1] ^ 1;
                            arr[i + 1][j + 1]  = arr[i + 1][j + 1] ^ 1;
                        }
                    }
            
         		}	

          	four({i, m - 2}, {i, m - 1}, {i + 1, m - 2}, {i + 1, m - 1});


         	}
            if(n & 1)
            {
                for(int j = 0; j < m - 2; j++)
                {

                    if(arr[n - 2][j] || arr[n - 1][j])
                    {

 	                   if(arr[n - 2][j] && arr[n - 1][j])
                        {
                            res.pb( node({n - 2, j}, {n - 1, j}, {n - 2, j + 1}) );
                            arr[n - 2][j] = arr[n - 2][j] ^ 1;
                            arr[n - 1][j] = arr[n - 1][j] ^ 1;
                            arr[n - 2][j + 1] = arr[n - 2][j + 1] ^ 1;
                        }
                        else if(arr[n - 2][j])
                        {
                            res.pb( node({n - 2, j}, {n - 2, j + 1}, {n - 1, j + 1}) );
                            arr[n - 2][j] = arr[n - 2][j] ^ 1;
                            arr[n - 2][j + 1] = arr[n - 2][j + 1] ^ 1;
                            arr[n - 1][j + 1] = arr[n - 1][j + 1] ^ 1;
                        }
                        else
                        {
                            res.pb( node({n - 1, j}, {n - 2, j + 1}, {n - 1, j + 1}) );
                            arr[n - 1][j] = arr[n - 1][j] ^ 1;
                            arr[n - 2][j + 1] = arr[n - 2][j + 1] ^ 1;
                            arr[n - 1][j + 1] = arr[n - 1][j + 1] ^ 1;
                        }
                    }
                }
                four({n - 2, m - 2}, {n - 2, m - 1}, {n - 1, m - 2}, {n - 1, m - 1});
            }
        }
        printf("%d\n", (int)res.size());

        for(int i = 0; i < res.size(); i++)
        {
            printf("%d %d %d %d %d %d\n", res[i].a.ff + 1, res[i].a.ss + 1, res[i].b.ff + 1, res[i].b.ss + 1, res[i].c.ff + 1, res[i].c.ss + 1);
        }
    }




// #ifdef PARTHO
//     int end_time = clock();
//     printf("Time = %.4f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
// #endif

    return 0;
}
///Before submit=>
///    *check for integer overflow,array bounds
///    *check for n=1
