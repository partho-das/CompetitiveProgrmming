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

ll powr(ll base, ll p)
{
	if( p <= 0) return 1;

	if(p & 1) return powr(base , p - 1) * base;
	else {
		ll x = powr(base, p / 2);
		return x * x;

	}
} 
int freq[50];

int main()
{
#ifdef PARTHO
    freopen("/home/partho/Desktop/IO/input.txt","r",stdin);
    freopen("/home/partho/Desktop/IO/output.txt","w",stdout);
    int start_time = clock();
#endif
FastIO;
 
ll k;
string str = "codeforces";
cin >> k;

if(k == 1)
{
	cout << str << endl;
	return 0;
}
ll i;
for(i = 1; i < 200; i++)
{
	ll p = (ll)powr(i, 10);
	if(p >= k) break;
}

ll x = i;

ll sum = powr(x - 1, 10);

for(int i = 0;i < 10; i++) freq[i] = x - 1;

i = 0;
while(sum < k && i < 10)
{
	freq[i]++;
	sum /= x - 1;
	sum *= x;
	i++;
}

for(int i = 0; i < 10; i++)
{
	while(freq[i]--) cout << str[i];
}

cout << endl;

#ifdef PARTHO
    int end_time = clock(); 
    printf("Time = %.4f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
#endif
 
    return 0;
}
///Before submit=>
///    *check for integer overflow,array bounds
///    *check for n=1