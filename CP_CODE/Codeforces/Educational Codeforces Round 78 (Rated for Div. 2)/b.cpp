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
       FastIO;


       int test;

       cin >> test;

       while(test--)
       {
          int a,b;
          cin >> a >> b;

          if(a==b)
          {
            cout << 0 << endl;
            continue;
          }

          if(a<b) swap(a,b);

          ll n = a-b;

          ll cnt = (sqrt(1+(8*n))-1)/2;



          ll sum = (cnt*(cnt+1))/2;

          b+= sum;
          n = cnt;
         
          n = abs(a-b);
          ll value ;

        while(n)
        {
           if(n<=2)
          {
            cnt+= n*2;
             break;
          }
          if(n==3)
          {
            cnt+=5;
            break;
          }
          cout << n << endl;
            value = sqrt(n);
           cnt += (value*value);
            n = n - (value*value);

        }


        cout << cnt << endl;
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

