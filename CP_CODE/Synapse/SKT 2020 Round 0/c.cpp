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
 
bool cmp(pair< ll , ll > a,pair< ll , ll > b)
{
    if(a.ss<=b.ss) return 1;
    else return 0;

}

 
int main(){
 
#ifdef PARTHO
    freopen("/home/partho/Desktop/IO/input.txt","r",stdin);
    freopen("/home/partho/Desktop/IO/output.txt","w",stdout);
    int start_time = clock();
#endif
    FastIO;


    int test;

    cin >> test;

    while(test--)
    {
        ll m,k,sum = 0;

        cin >> m >> k;
        std::vector<pair< ll , ll > > v,now;


        v.pb({0,0});
        for(int i = 0;i < m;i++)
        {  ll b,d,x,age;

            cin >> x >> b >> d;
            age = d - b + 1;
            v.pb({x,age});
        } 
         v.pb({INF,INF});
         sort(v.begin(), v.end(),cmp);



        for(int i = 0;i < v.size() ;i++)
        {
            sum+=v[i].ff;
            v[i].ff = sum;
        }

        sum-=INF;
        if(sum < k)
        {
            cout << -1 << endl;
            continue;
        }
        
        ll high = (long long)v.size()-2 , low = 1,mid,res = -1;

        while(high >= low)
        {
            mid = high + low >> 1;

            if(v[mid].ff < k) low = mid + 1;
           else if(v[mid - 1].ff < k && v[mid + 1].ff > k)
            {
                res = v[mid].ss;
                break;
            }
            else if(v[mid - 1].ff > k )
                    high = mid - 1;

            else if(v[mid + 1].ff < k)
                low = mid + 1;
        }

        cout << res << endl;



    }
  
  #ifdef PARTHO
       int end_time = clock();
       printf("Time = %.4f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
  #endif
  return 0;
}