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
//____________________________________________________________________________________________________________________________________

struct dive
{
	int a,b,c;
	dive(){ }
	dive(int _a, int _b,int _c) { a = _a,b = _b, c = _c ;}
};

std::vector<dive> v;

void gen()
{
	
	int maxn = 1e4 + 1000;
	for(int a = 1; a <= maxn; a++)
	{
		for(int b = a; b <= maxn; b+= a)
		{
			for(int c = b; c <= maxn; c += b)
			{
				dive value(a,b,c);
				v.pb(value);
			}
		}

	}

}




int main()
{
#ifdef PARTHO
    freopen("/home/partho/Desktop/IO/input.txt","r",stdin);
    freopen("/home/partho/Desktop/IO/output.txt","w",stdout);
    int start_time = clock();
#endif
    FastIO;

    gen();
    int test;

    cin >> test;
    while(test--)
    {
    	int a,b,c;
    	cin >> a >> b >> c;
    	dive now(a,b,c);
    	ll mn = INF;
    	for(int i = 0;i < v.size();i++)
    	{
    		int dis = abs(v[i].a - a) + abs(v[i].b - b) + abs(v[i].c - c);
    		if(mn > dis){
    		 now = v[i];
    		 mn = dis;
    		}
    	}
    	cout << mn << endl;
    	cout << now.a << " " << now.b << " " << now.c << endl;
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
