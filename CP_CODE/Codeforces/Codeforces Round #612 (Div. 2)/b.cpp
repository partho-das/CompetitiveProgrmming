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
 
 
 
 
int main(){
 
  #ifdef PARTHO
       freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
       freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
       int start_time = clock();
  #endif
   FastIO;
 
 
    ll n, k, cnt = 0;
 
    
    
    unordered_map<string,int> mp;
    string str;
    cin >> n >> k;
    std::vector<string> v(n+5);
 
 
    for(int i = 0; i < n ; i++ )
    {
        cin >> str;
        v[i] = str;
        mp[str]++; 
    }
    
    for(int i = 0;i<n;i++)
    {
        for(int j = i+1 ; j < n; j++)
        {
           
 
            for(int x = 0; x<k ;x++)
             {
                    if(v[i][x] != v[j][x])
                    {
                        if(v[i][x] == 'S' && v[j][x] == 'E' ||
                         v[i][x] == 'E' && v[j][x] == 'S') str[x] = 'T';
                        else if(v[i][x] == 'S' && v[j][x] == 'T' ||
                            v[i][x] == 'T' && v[j][x] == 'S' ) str[x] = 'E';
                        else if(v[i][x] == 'E' && v[j][x] == 'T' ||
                            v[i][x] == 'T' && v[j][x] == 'E') str[x] = 'S';
                    }
                    else{
                        str[x] = v[i][x];
                    }
                }
 
 
                if( mp.find(str) != mp.end())
                {
                    
                    cnt+= mp[v[i]] * mp[v[j]] * mp[str];
                    //mp[v[i]] = mp[v[j]] = mp[str] = 0;
                }
 
            
 
        }
    }
 
    cout << cnt/3 << endl; // because (we calculated the seame value 3 time. like (1,2,3) (1,2,3)(2,3,1) string 1,2,3 are differet and make a set.)
 
  #ifdef PARTHO
       int end_time = clock();
       printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
  #endif
  return 0;
}