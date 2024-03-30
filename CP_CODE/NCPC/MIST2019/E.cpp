#include<bits/stdc++.h>
using namespace std;
 
int main() {

  #ifdef PARTHO
    freopen("/home/partho/Desktop/IO/input.txt","r",stdin);
    freopen("/home/partho/Desktop/IO/output.txt","w",stdout);
    int start_time = clock();
#endif
 
  double st = clock();
  int t, case_num = 0;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    set < int > segments;
 
    for (int i = 0; i < (int) s.size(); i++) {
      if (i == 0) {
        segments.insert(i);
      } else if (s[i] != s[i - 1]) {
        segments.insert(i);
      }
    }
 
    segments.insert(s.size());
 
    printf("Case %d:\n", ++case_num);;
    int q;
    cin >> q;
    for (int loop = 0; loop < q; loop++) {
      int type;
      int i;
      scanf("%d%d", & type, & i);
 
      if(type == 1) {
        auto iterator = segments.lower_bound(i);
        if( *iterator > i) {
          iterator--;
        }
 
        int left = *iterator;
        int right = *(++iterator);
        int ans = right - left;
        printf("%d\n", ans);
      } else {
        segments.insert(i);
        segments.insert(i + 1);
      }
    }
  }
 
  double en = clock();
  cerr << (en - st) / CLOCKS_PER_SEC << endl;
 
  return 0;
}