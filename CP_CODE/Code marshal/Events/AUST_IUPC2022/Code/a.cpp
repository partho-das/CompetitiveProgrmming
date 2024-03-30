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

ll qsum(ll n){
	return (n * n + n) / 2;
}
void solve(){
	ll n, k, m;

	sclll(n, k, m);
	ll sum = 0;

	if(n <= 5){
		vi v(n);

		for(int i = 0; i < n; i++){
			v[i] = i + 1;
		}

		for(int i = 0; i < k - 1; i++){
			next_permutation(all(v));
		}
		// for(int it : v){
		// 	cout << it << " " ;
		// }
		// puts("");
		while(m--){
			sum += v.back();
			v.pop_back();
		}

	}
	else{
		vi v(5);

		for(int i = 5 - 1; i >= 0; i--){
			v[i] = n--;
		}

		for(int i = 0; i < k - 1; i++){
			next_permutation(all(v));
		}


		while(!v.empty() && m){
			sum += v.back();
			v.pop_back();
			m--;
		}



		if(m > 0){
			sum += qsum(n) - qsum(n - m);
		}

	}
	printf("Case %d: %lld\n", t++, sum);


}

int main()
{
	//FastIO

	int test = 1;
	sc1(test);

	while(test--) {
		solve();
	}

	return 0;
}