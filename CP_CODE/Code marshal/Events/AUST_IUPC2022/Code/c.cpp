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

#define FastIO ios_base::sync_with_stdio(false);cin.tie(nullptr);
const ll INF = 1e18 + 5;
const int maxn = 1e5;

ll sum[maxn + 5], freq[maxn + 5];
map<pii, int>graph;
int t = 1;
void solve(){

	memset(sum, 0, sizeof sum);
	memset(freq, 0, sizeof freq);
	graph.clear();

	int n, m;
	sc2(n, m);

	//cout << n << " " << m << endl;
	for(int i = 0; i < m; i++){
		int u, v, w;
		sc3(u, v, w);

		//cout << u << " " << v << " " << w << endl;
		if( graph.find({u, v}) == graph.end()){
			sum[u] += w;
			sum[v] += w;
			graph[{u, v}] = w;
			graph[{v, u}] = w;
			freq[v]++;
			freq[u]++;
		}
		else{
			if(graph[{u, v}] > w){
				sum[u] = sum[u] + w - graph[{u, v}];
				sum[v] = sum[v] + w - graph[{u, v}];
				graph[{u, v}] = w;
				graph[{v, u}] = w;
			}
		}
		
	}
	ll res = INF;
	for(int i = 1; i <= n; i++){
		//cout << freq[i] << " " << sum[i] << endl;
		if(freq[i] == n - 1)
		res = min(res, sum[i]);
	}
	if(res != INF)
	printf("Case %d: %lld\n", t++, res);
	else printf("Case %d: Impossible\n", t++);
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