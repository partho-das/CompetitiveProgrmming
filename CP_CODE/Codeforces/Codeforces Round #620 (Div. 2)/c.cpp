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


bool isval(int m,int t,int h,int l) { 

if(abs(m - h)>t && abs(m - l) > t) return 1;
return 1;
}

int main(){
 
#ifdef PARTHO
    freopen("/home/partho/Desktop/IO/input.txt","r",stdin);
    freopen("/home/partho/Desktop/IO/output.txt","w",stdout);
    int start_time = clock();
#endif

FastIO;


int q;

cin >> q;

while(q--)
{
	int n,m;

	cin >> n >> m;
	int mx,mn,l,h,t;
	int prvt = 0;
	cin >> t >> l >> h;
		int ck = 1;
		if(abs(m - h)>t && abs(m - l) > t) {
			ck = 0;
		}
		mx = min(m + t,h);

		mn = max(m - t,l);
		prvt = t;
		//cout << mx << " " << mn << endl;
		int nwt;
	for(int i = 1;i < n;i++)
	{
		cin >> t >> l >> h;
		

		nwt = t - prvt;
		prvt = t;
		t = nwt;
		std::vector <int> v;
		if(mx<=l && mx + t >= l){
			v.pb(min(mx + t,l));
		}
		if(mx>=h && mx - t <= h){
			v.pb(max(mx - t,l));
		}
		if(mn<=l && mn + t >= l){
			v.pb(min(mn + t,l));
		}
		if(mn>=h && mn - t <= h){
			v.pb(max(mn - t,l));
		}

		if(mx<=h && mx >= l)
		{
			v.pb(max(l,mx - t));
			v.pb(min(h,mx + t));
		}
		if(mn<=h && mn >= l)
		{
			v.pb(max(l,mn - t));
			v.pb(min(h,mn + t));

		}

		sort(all(v));
		if(v.size() == 0 )
		{
			ck = 0;
			continue;
		}
		mn =v[0],mx = v.back();

		//cout << mx << " " << mn << endl;

		
		
	}
	if(ck  == 0) cout << "NO" << endl;
	else cout << "YES" << endl;
}


   

    
  
  #ifdef PARTHO
       int end_time = clock();
       printf("Time = %.4f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
  #endif
  return 0;
}
