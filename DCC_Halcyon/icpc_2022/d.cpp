#include <bits/stdc++.h>

#define endl '\n'
#define F first
#define S second
#define pb push_back

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

template<typename T>
void scan(vector<T> &v) {for (T &x : v) cin >> x;};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LZYTOURIST
    freopen("/home/joker/Documents/code/in", "r", stdin);
    freopen("/home/joker/Documents/code/out", "w", stdout);
#endif

    int t;
    cin >> t;

    for (int tc = 1; tc <= t; ++tc) {
    	cout << "Case " << tc << ": ";

    	int a, b, c, k;
    	cin >> a >> b >> c >> k;

    	int less = 0;
    	if (a < k) ++less;
    	if (b < k) ++less;
    	if (c < k) ++less;

    	int s = a + b + c;
    	if (s % 3 != 0) {
    		cout << "Fight" << endl;
    		continue;
    	}

    	if (less >= 2 && min({a, b, c}) != max({a, b, c})) {
    		cout << "Fight" << endl;
    		continue;
    	}

    	int d = s / 3;
    	bool ok = true;

    	if (a > d && (a - d) % k != 0) {
    		ok = false;
    	}
    	if (b > d && (b - d) % k != 0) {
    		ok = false;
    	}
    	if (c > d && (c - d) % k != 0) {
    		ok = false;
    	}

    	cout << (ok ? "Peaceful" : "Fight") << endl;
    }

    return 0;
}