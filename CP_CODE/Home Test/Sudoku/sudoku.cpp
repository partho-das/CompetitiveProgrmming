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
#define sc1(n)       sc("%d",&n);
#define sc2(n, m)    sc("%d%d", &n, &m);
#define sc3(m, n, o) sc("%d%d", &m, &n, &o);
#define scl(n)       sc("%lld", &n);
#define scll(n, m)   sc("%lld%lld", &n, &m);
#define scf(f)       sc("%f",&f);
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
 
int n = 10, m = 10;
int grid[10][10];
bool row[10][10], col[10][10], block[10][10];
std::vector<int> v;
 
int getblock(int i, int j)
{
    if(i >= 1 && i <= 3)
    {
        if(j >= 1 && j <= 3) return 1;
        else if(j >= 4 && j <= 6) return 2;
        else if(j >= 7 && j <= 9) return 3;
    }
    else if(i >= 4 && i <= 6)
    {
        if(j >= 1 && j <= 3) return 4;
        else if(j >= 4 && j <= 6) return 5;
        else if(j >= 7 && j <= 9) return 6;
    }
    else if(i >= 7 && i <= 9)
    {
        if(j >= 1 && j <= 3) return 7;
        else if(j >= 4 && j <= 6) return 8;
        else if(j >= 7 && j <= 9) return 9;
    }
 
return 0;
}
 
void preprocess()
{
    for(int i = 1; i < n; i++){
        for(int j = 1; j < n; j++)
        {
            row[i][j] = col[i][j] = block[i][j] = 0;
        }
    }
 
    for(int i = 1; i < n; i++)
    {
        for(int j = 1; j < n; j++)
        {
            row[i][ grid[i][j] ] = 1;
            col[j][ grid[i][j] ] = 1;
            int b = getblock(i, j);
            block[b][ grid[i][j] ] = 1;
        }
    }
    return;
}
 
 
bool isval(int i, int j, int b, int x)
{
    return !row[i][x] && !col[j][x] && !block[b][x];
}
 
 int cnt = 0;
bool solve(int i, int j, int pos)
{
 cnt++;
    if(j > 9) j = 1, i++;
    if(i > 9)
    {
        //puts("");
        for(int i = 1; i < n; i++)
        {
            for(int j = 1; j < n; j++)
            {
                printf("%d", grid[i][j]);
 
                if(j == 9) puts("");
                //else printf(" ");
            }
        }
 	
 		//printf("%d\n", cnt);
        // int y;
 
        // printf("More ? // 1 : 0\n");
        // scanf("%d", &y);
        return 1;
    }
    bool ck = 0;
    int x;
    if(pos == 9) pos = 0;
    if(grid[i][j] == 0)
    {
 
        int a = pos, b = pos + 1;
        if(b == 9) b = 1;
 
        swap(v[a], v[b]);
        for(int l = 1; l < n; l++)
        {
        	x = l;
            int b = getblock(i, j);
            x = v[l - 1];
            //cout << x << endl;
            if(isval(i, j, b, x))
            {
                row[i][x] = 1;
                col[j][x] = 1;
                block[b][x] = 1;
                grid[i][j] = x;
 
                if(solve(i, j + 1, pos + 1)) return 1;
 
                row[i][x] = 0;
                col[j][x] = 0;
                block[b][x] = 0;
                grid[i][j] = 0;
 
            }
        }
        swap(v[a], v[b]);
    }
    else return solve(i, j + 1, pos);
    return 0;
}
 
 
 
 
int main()
{
#ifdef PARTHO
    freopen("/home/partho/Desktop/IO/input.txt","r",stdin);
    freopen("/home/partho/Desktop/IO/output.txt","w",stdout);
    int start_time = clock();
#endif
//FastIO;
 
char s[10];
 
 
int test, tc = 1;
sc1(test);
 

v.pb(9);
v.pb(1);
v.pb(2);
v.pb(8);
v.pb(5);
v.pb(3);
v.pb(6);
v.pb(7);
v.pb(4);



 
while(test--)
{
 
for(int i = 1; i < n; i++)
{
    scanf("%s", s);
    //puts(s);
 
    for(int j = 1; j < n; j++)
    {
        if(s[j - 1] == '.') grid[i][j] = 0;
        else grid[i][j] = s[j - 1] - '0';
    }
}
 
 
 
// for(int i = 1; i < n; i++)
//      {
//          for(int j = 1; j < n; j++)
//          {
//              printf("%d", grid[i][j]);
 
//              if(j == 9) puts("");
//              else printf(" ");
//          }
//      }
 
preprocess();
 
printf("Case %d:\n", tc++);
solve(1, 1, 0);
 
}
 
/*input format:
0 0 0 0 0 0 0 0 0 // 0 mean empty cell
0 0 0 0 0 0 0 0 x // x mean constant cell
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
*/
 
 
 
 
#ifdef PARTHO
    int end_time = clock();
    printf("Time = %.4f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
#endif
 
    return 0;
}
///Before submit=>
///    *check for integer overflow,array bounds
///    *check for n=1
 