#include <bits/stdc++.h>

using namespace std;

#define PI 2*acos(0.0)
#define pf printf
#define sc scanf
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef unsigned long long ull;
typedef std::vector<int> vi;
typedef std::vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define sc1(n) sc("%d", &n)
#define sc2(n, m) sc("%d%d", &n, &m)
#define sc3(n, m, o) sc("%d%d%d", &n, &m, &o)
#define scl(n) scanf("%lld", &n);
#define scll(n, m) scanf("%lld%lld", &n, &m)
#define sclll(n, m, o) scanf("%lld%lld%lld", &n, &m, &o)
#define all(x) (x).begin(), (x).end()

#define FastIO ios_base::sync_with_stdio(false);cin.tie(nullptr);
const ll INF = 0x3f3f3f3f3f3f3f3f;
int t = 1;


void solve(){
	cout << 1 << endl;

	int n = 1e5;
	cout << n << " " << n << endl;
	for(int i = 1; i <= n; i++){
		cout << i << " ";
	}	
	cout << endl;
	for(int i = 1; i <= n; i++){
		cout << (i + 1e5) << " "; 
	}
	cout << endl;
}

int main()
{
	

	int test = 1;
	sc1(test);

	while(test--) {
		solve();
	}

	return 0;
}