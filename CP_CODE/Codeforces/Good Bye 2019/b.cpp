#include <bits/stdc++.h>
using namespace std;
 
 
//____________________________________________________________________________________________________________________________________
 
#define PI  2*acos(0.0)
#define pf  printf
#define sf  scanf
#define ff  first
#define ss  second
#define mp  make_pair
#define pb  push_back
typedef long long ll;
typedef unsigned long long ull;
typedef std::vector<int> vi;
typedef vector<long long> vll;
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

int arr[2000005],front[200005],back[200009];

int main(){
 
  #ifdef PARTHO
       freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
       freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
       int start_time = clock();
  #endif
   
   int test;
   sc(test);

   while(test--)
   {
      int n;

      cin >> n;
      
      int value;

      for(int i = 1;i<=n;i++)
      {
        cin >> arr[i];
      }
      int ck = 0,a ,b ;
      for(int i = 2;i<=n;i++)
      {
        if(abs(arr[i] - arr[i-1])>=2)
        {
          ck = 1;
          a = i-1;
          b = i;
          break;
        }
      }

      if(ck)
      {
         puts("YES");
        cout << a << " " << b << endl;
      }
      else puts("NO");

      

   }


  

  #ifdef PARTHO
       int end_time = clock();
       printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
  #endif
  return 0;
}
 
 
 
///Before submit=>
///    *check for integer overflow,array bounds
///    *check for n=1