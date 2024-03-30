// meow-meow
#pragma GCC optimize("O3", "unroll-loops")
#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(a) (ll)((a).size())
#define heap priority_queue
#define hash_map unordered_map
#define hash_set unordered_set
#define ft first
#define sd second
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define mineq(a, b) (a) = min((a), (b))
#define maxeq(a, b) (a) = max((a), (b))
using namespace std;
typedef int ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef vector<ll> vll;
typedef set<ll> sll;
typedef map<ll, ll> mll;
const ll inf = numeric_limits<ll>::max() / 2;
const ld eps = 1e-9;
const ld pi = acos(-1);

const ll MAXN = 3e5 + 10;

struct dsu {
	ll n;
	ll t[MAXN], rank[MAXN] = { 1 };
	vector<pair<ll&, ll>> st;
	ll cnt = 0;
	dsu() {}
	dsu(ll n_) {
		n = n_;
		iota(t, t + n + 1, 0);
		cnt = n;
	}
	ll find(ll v) {
		if (t[v] == v) {
			return v;
		}
		return find(t[v]);
	}
	void join(ll a, ll b) {
		a = find(a), b = find(b);
		if (a != b) {
			if (rank[a] < rank[b]) {
				swap(a, b);
			}
			st.pb({ t[b], t[b] });
			t[b] = a;
			if (rank[a] == rank[b]) {
				st.pb({ rank[a], rank[a] });
				++rank[a];
			}
			st.pb({ cnt, cnt });
			--cnt;
		}
	}
	void restore(ll pos) {
		while (sz(st) != pos) {
			st.back().ft = st.back().sd;
			st.popb();
		}
	}
};

ll n, k;
dsu d;
ll qs[MAXN], vs[MAXN], us[MAXN];
ll ans[MAXN];
ll bs[MAXN];
map<pll, ll> open;

void divide(ll l, ll r) {
	if (l > r) {
		return;
	}
	if (l == r) {
		if (qs[l] == 2) {
			ans[l] = d.cnt;
		}
		return;
	}
	ll m = (l + r) / 2;
	ll prev = sz(d.st);
	for (ll i = m + 1; i <= r; i++) {
		if (qs[i] == 1) {
			ll op = bs[i];
			if (op <= l) {
				d.join(vs[i], us[i]);
			}
		}
	}
	divide(l, m);
	d.restore(prev);
	for (ll i = l; i <= m; i++) {
		if (qs[i] == 0) {
			ll op = bs[i];
			if (op > r) {
				d.join(vs[i], us[i]);
			}
		}
	}
	divide(m + 1, r);
	d.restore(prev);
}

void solve() {
	cin >> n >> k;
	d = dsu(n);
	for (ll i = 1; i <= k; i++) {
		char op;
		cin >> op;
		if (op == '+') {
			qs[i] = 0;
			cin >> vs[i] >> us[i];
			if (vs[i] > us[i]) {
				swap(vs[i], us[i]);
			}
			open[{vs[i], us[i]}] = i;
			bs[i] = k + 1;
		} else if (op == '-') {
			qs[i] = 1;
			cin >> vs[i] >> us[i];
			if (vs[i] > us[i]) {
				swap(vs[i], us[i]);
			}
			ll op = open[{vs[i], us[i]}];
			bs[op] = i;
			bs[i] = op;
		} else if (op == '?') {
			qs[i] = 2;
		}
	}
	divide(1, k);
	for (ll i = 1; i <= k; i++) {
		if (qs[i] == 2) {
			cout << ans[i] << endl;
		}
	}
}

int main() {
	fast;
	solve();
	return 0;
}
