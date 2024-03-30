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

typedef pair<double, double> pd;

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

        pd A, B, C, D;
        pd pivot, ratio;

        cin >> A.F >> A.S;
        cin >> B.F >> B.S;
        cin >> C.F >> C.S;
        cin >> D.F >> D.S;
        cin >> pivot.F >> pivot.S;
        cin >> ratio.F >> ratio.S;

        pd topLeft = {-1, -1};
        pd bottomLeft = topLeft, topRight = topLeft, bottomRight = topLeft;

        auto find_corner = [&](pd agent) -> pd {
            double l = 0, r = 1e18;
            int cnt = 32;

            while (cnt--) {
                double m = l + (r - l) / 2;
                
            }
        };
    }

    return 0;
}
