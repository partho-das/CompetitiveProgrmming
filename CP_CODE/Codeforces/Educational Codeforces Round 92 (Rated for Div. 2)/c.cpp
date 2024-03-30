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


int freq[10];
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

 	string str;

 	std::vector<int> pos[10];


 	cin >> str;
 	//cout << str << endl;


 	for(int i = 0; i < str.size(); i++)
 	{

 		if(pos[str[i] - '0'].size() == 0) pos[str[i] - '0'].pb(-1);

 		pos[ str[i] - '0' ].pb(i);
 	}





 	int mx = 0;
 	for(int i = 0; i < 10; i++)
 	{
 		mx = max(int(pos[i].size() - 1), mx);
 	}	
 	//cout << str.size() << endl;

 	for(int i = 0; i < 10; i++)
 	{
 		for(int j = 0; j < 10; j++)
 		{
 			if(pos[i].size() <= 1 || pos[j].size() <= 1 || i == j)
 			{
 				mx = max(int(pos[i].size() - 1), mx);
 				mx = max(int(pos[j].size() - 1), mx);
 			}
 			else
 			{
 				int a = 1, b = 0, now = 1, cnt = 0; // 1 == a
 				while(1)
 				{
 					if( now == 1)
 					{
 					 	int ck = 0;
 						while( pos[i][a] <= pos[j][b])
 						{
 							a++;
 							if(a == pos[i].size()){
 								ck = 1;
 								break;
 							}
 						}
 						if(ck) break;
 						cnt++;
 						now = 2;
 					}
 					else{

 						int ck = 0;
 						while( pos[j][b] <= pos[i][a])
 						{
 							b++;
 							if(b == pos[j].size()){
 								ck = 1;
 								break;
 							}
 						}

 						if(ck) break;
 						cnt++;
 						now = 1;
 					}

 				}
 				if(cnt & 1 && cnt != 1) cnt--;
 		
 				mx = max(mx, cnt);
 			}
 		}

 	}
 	//cout << str.size() << endl;


 	cout << (int) str.size() - mx << endl;


	
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