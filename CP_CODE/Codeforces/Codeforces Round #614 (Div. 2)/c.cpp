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
 
bool visit[2][100005];
 
int n;
 
bool valid(int x)
{
	if(x>=0 && x<=n) return 1;
	else return 0;
}
ll connection = 0;
 
 
void down(int u,int v)
{
	if(valid(u+1) && valid(v-1))
	{
		if(visit[u+1][v-1])
		connection--;
		
	}
 
	if(valid(u+1) && valid(v+1))
	{
		if(visit[u+1][v+1])
		connection--;
	
	}
 
	if(valid(u+1) && valid(v))
	{
		if(visit[u+1][v])
		connection--;
	
	}
 
 
 
	return;
}
 
void up(int u,int v)
{
	if(valid(u-1) && valid(v-1))
	{
		if(visit[u-1][v-1])
		connection--;
	}
 
	if(valid(u-1) && valid(v+1))
	{
		if(visit[u-1][v+1])
		connection--;
	}
 
	if(valid(u-1) && valid(v))
	{
		if(visit[u-1][v])
		connection--;
	}
 
 
 
 
	return;
}
 
 
 
 
void downi(int u,int v)
{
	if(valid(u+1) && valid(v-1))
	{
		if(visit[u+1][v-1])
		connection++;
		
	}
 
	if(valid(u+1) && valid(v+1))
	{
		if(visit[u+1][v+1])
		connection++;
	
	}
 
	if(valid(u+1) && valid(v))
	{
		if(visit[u+1][v])
		connection++;
	
	}
 
 
 
	return;
}
 
void upi(int u,int v)
{
	if(valid(u-1) && valid(v-1))
	{
		if(visit[u-1][v-1])
		connection++;
	}
 
	if(valid(u-1) && valid(v+1))
	{
		if(visit[u-1][v+1])
		connection++;
	}
 
	if(valid(u-1) && valid(v))
	{
		if(visit[u-1][v])
		connection++;
	}
 
 
 
 
	return;
}
 
 
 
 
 
 
 
int main(){
 
  #ifdef PARTHO
       freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
       freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
       int start_time = clock();
  #endif
   //FastIO;
 
     int q;
 
 
    cin >> n >> q;
 
 
    int u,v;
   
    for(int i = 0;i<q;i++)
    {
    	cin >> u >> v;
    	u--,v--;
    	if(visit[u][v])
    	{
 
	    	if(u == 0)
	    	{
	    		down(u,v);
	    	}
	    		else up(u,v);
 
	    		visit[u][v] = 0;
	    	}
 
 
    	else
    	{
 
    		if(u == 0)
	    	{
	    		downi(u,v);
	    	}
    		else upi(u,v);
 
    		visit[u][v] = 1;
    	}
 
    	//cout << connection << endl;
    	if(connection == 0)
    		puts("Yes");
    	else puts("No");
 
 
 
    		
    	}
    	
    
 
 
  #ifdef PARTHO
       int end_time = clock();
       printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
  #endif
  return 0;
}