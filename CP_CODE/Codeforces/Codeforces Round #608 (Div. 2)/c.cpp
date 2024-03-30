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
typedef std::vector<int> vi;
typedef vector<long long> vll ;
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


int main(){

  #ifdef PARTHO
       freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
       freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
       int start_time = clock();
  #endif


       int n,sx,sy;

       cin >> n >> sx >> sy;

       int arr[5] = {0,0,0,0,0};

       int x,y;
       for(int i = 0;i<n;i++)
       {
          scanf("%d%d",&x,&y);

          if(x>sx) arr[1]++;
          if(x<sx) arr[2]++;
          if(y>sy) arr[3]++;
          if(y<sy) arr[4]++;
       }


       if(arr[1] >= arr[2] && arr[1] >= arr[3] && arr[1] >= arr[4] )
       {
          cout << arr[1] << endl;
          cout << sx+1 <<" " << sy << endl;
       }
       else if(arr[2] >= arr[1] && arr[2] >= arr[3] && arr[2] >= arr[4])
       {
          cout << arr[2] << endl;
          cout << sx-1 <<" " << sy << endl;
       }
       else if(arr[3] >= arr[1] && arr[3] >= arr[2] && arr[3] >= arr[4])
       {

          cout << arr[3] << endl;
          cout << sx <<" " << sy+1 << endl;

       }
       else if(arr[4] >= arr[1] && arr[4] >= arr[2] && arr[4] >= arr[3])
       {

          cout << arr[4] << endl;
          cout << sx <<" " << sy-1 << endl;

       }



    
  #ifdef PARTHO
       int end_time = clock();
       printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
  #endif
  return 0;
}


