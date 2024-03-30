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
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const ll INF = 2000000000000000000LL;
const int inf = 0x3f3f3f3f;
const long double EPS = 1e-9;
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}

//____________________________________________________________________________________________________________________________________
 
int main()
{
#ifdef PARTHO
    freopen("/home/partho/Desktop/IO/input.txt","r",stdin);
    freopen("/home/partho/Desktop/IO/output.txt","w",stdout);
    int start_time = clock();
#endif
//FastIO;

       int test;
       scanf("%d",&test);
       int c;
       for( c = 1;c<=test;c++)
       {
            int n,m;
            scanf("%d%d",&n,&m);
            long long grid = n*m;
            int knight = (grid+1)>>1;


            if(n == 1 || m == 1)
            {
                if(n == 1) knight = m;
                else if(m == 1) knight = n; 
            }
            else if(n == 2 ||  m == 2)
            {
                knight = (grid / 8)  * 4;
                int ex = grid % 8;
                if(ex <= 4) knight += ex;
                else knight += 4;
            }

            
 
            printf("Case %d: %d\n",c,knight);
 
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