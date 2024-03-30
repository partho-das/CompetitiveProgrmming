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
   //FastIO;
 
   	ll ox,oy,sx,sy,ax,ay,bx,by,t;
   	std::vector< pair<ll,ll> > genrate;
 
   	cin >> ox >> oy >> ax >> ay >> bx >> by;
   	cin >> sx >> sy >> t;
 
  // genrate.pb({ox,oy});
   	ll x = ox,y = oy;
 
 
   while(x<=3e116 && y <= 3e16)
   {
   		
   		genrate.pb({x,y});
   		x = ax * x + bx;
   		y = ay * y + by;
   		
 
   }
 
 
 	ll mxcnt = 0;
   for(int i = 0;i<genrate.size();i++)
   {
   	ll time = t;
   	ll dis = abs(genrate[i].ff - sx) + abs(genrate[i].ss - sy);
   	std::vector< pair<ll,ll> > v = genrate;
   	time-= dis;
   	v[i] = {-1,-1};

   	int x = v.size();
   	ll mn = INF,indx,nsx = genrate[i].ff,nsy = genrate[i].ss;

   	ll cnt = 0;
   	if(dis<=t)
   	{
   		cnt = 1;
   		//cout << nsx << " " << nsy << endl;
	   	while(x--)
	   	{
	   		mn = INF;

	   		for(int j = 0; j < v.size() ; j++)
	   		{
	   			if(v[j].ff != -1 && v[j].ss != -1)
	   			{

		   			dis = abs(v[j].ff - nsx) + abs(v[j].ss - nsy);
		   			if(dis < mn)
		   			{
		   				mn = dis;
		   				indx = j;
		   			}
	   			}
	   		}

	   		if(mn<=time)
	   		{
	   			time-=mn;
	   			cnt++;
	   			nsx = v[indx].ff, nsy = v[indx].ss;
	   			v[indx] = {-1,-1};
	   		}
	   		else break;

   		}
   	}


   		mxcnt = max(cnt,mxcnt);

   	

   }

   		cout << mxcnt << endl;
    
 
 
  #ifdef PARTHO
       int end_time = clock();
       printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
  #endif
  return 0;
}