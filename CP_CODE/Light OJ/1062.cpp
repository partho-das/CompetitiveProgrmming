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


int main()
{
#ifdef PARTHO
    freopen("/home/partho/Desktop/IO/input.txt","r",stdin);
    freopen("/home/partho/Desktop/IO/output.txt","w",stdout);
    int start_time = clock();
#endif
   // FastIO;

int test;

cin >> test;
int tc = 1;
while(test--)
{
	double x,y,c;

	cin >> x >> y >> c;

	double low = 0,high = min(x,y), mid,p , q,nc; // p = wall 1 , q = wall 2
	while(abs(high - low) >= EPS) 
	{
		mid = low + (high - low) / 2; // new weaght
		p = sqrt( (x * x) - (mid * mid)); // applying pethagors to calclute p
		q = sqrt(y * y - mid * mid);
		nc = 1 / (1 / p + 1 / q); // if(w is given then wc can caculate p)
		if(nc > c) low = mid; 
		else if(nc < c) high = mid;
		else break;
	}

	printf("Case %d: %.14lf\n",tc++,mid);
	
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
