#include <bits/stdc++.h>

#define endl '\n'
#define F first
#define S second
#define pb push_back

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const int B = 91;
const int M = 1e9 + 7;
const int N = 1e6 + 5;

int n, palin;
string s;
vector<int> g[N];

void dfs(int u, int par, ll h, ll rh, ll base) {
    ll nh = (h * B) % M + (s[u - 1] - 'A' + 1);
    nh %= M;
    
    ll nrh = base * (s[u - 1] - 'A' + 1) + rh;
    nrh %= M;
        
    //~ cout << nh << " " << nrh << " " << x << endl;
    if (nh == nrh) {
        ++palin;
    }
    
    for (int v : g[u]) {
        if (v != par) {
            dfs(v, u, nh, nrh, (base * B) % M);
        }
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    for (int tc = 1; tc <= t; ++tc) {
        cout << "Case " << tc << ": ";
        
        cin >> n >> s;
        
        for (int i = 1; i <= n; ++i) {
            g[i].clear();
        }
        
        for (int i = 1, u, v; i < n; ++i) {
            cin >> u >> v;
            
            g[u].pb(v);
            g[v].pb(u);
        }
        
        palin = 0;
        dfs(1, -1, 0LL, 0LL, 1LL);
        
        int gc = __gcd(palin, n);
        cout << palin / gc << "/" << n / gc << endl;
    }
	
	return 0;
}
