#include <bits/stdc++.h>
 
using namespace std;
 
int main() {


#ifdef PARTHO
    freopen("/mnt/Stable/Dropbox/IO/input.txt","r",stdin);
    freopen("/mnt/Stable/Dropbox/IO/output.txt","w",stdout);
    int start_time = clock();
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    cout << (a[0] < a[n - 1] ? "YES" : "NO") << '\n';
  }
  return 0;
}