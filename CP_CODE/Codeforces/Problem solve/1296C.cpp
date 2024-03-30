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
 
int dirx[] = { 0,0,-1, 1}; // Left,right,up, down ;
int diry[] = {-1,1, 0, 0};
 
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
    	int len;
    	string path;
    	cin >> len >> path;

    	std::map< pair<ll,ll>, int > visit;

    	ll mn = INF;

    	pair < ll , ll > mnpath {-1,-1} ,pos{0,0} ;
    	visit[{0,0}] = 0;

    	for(int i = 0; i < len ; i++)
    	{

    		if(path[i] == 'L')  pos.ff += dirx[0],pos.ss += diry[0];
    		else if(path[i] == 'R') pos.ff += dirx[1],pos.ss += diry[1];
    		else if(path[i] == 'U') pos.ff += dirx[2],pos.ss += diry[2];
    		else if(path[i] == 'D') pos.ff += dirx[3],pos.ss += diry[3];

    		if(visit.find(pos) != visit.end())
    		{
    			int dis = i - visit[pos] + 1;
    			if(mn >= dis)
    			{
    				mn = dis;
    				mnpath = {visit[pos] + 1, i + 1}; 
    			}
    		}

    		visit[pos] = i+1;
    	}


    	if(mn != INF) cout << mnpath.ff << " " << mnpath.ss << endl;
    	else cout << -1 << endl;





    }



 
 
  
  #ifdef PARTHO
       int end_time = clock();
       printf("Time = %.4f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
  #endif
  return 0;
}