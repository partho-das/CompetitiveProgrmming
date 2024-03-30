#include <bits/stdc++.h>
using namespace std;

//____________________________________________________________________________________________________________________________________

#define PI  2*acos(0.0)
#define pf  printf
#define sf  scan
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

struct edge{
	int u,v,indx,indx2;
	edge(){}
	edge(int _u,int _v,int _indx,int _indx2)
	{
		u = _u, v = _v, indx = _indx,indx2 = _indx2;
	}
};

std::vector< int > grap[100009],cst[100009];
std::vector < edge > moves;
void input(int n)
{
	int u,v;
	for(int i = 1; i < n; i++)
	{
		cin >> u >> v;
		grap[u].pb(v), grap[v].pb(u);
		cst[u].pb(-1), cst[v].pb(-1);
		edge a;
		a.u = u,a.v = v, a.indx = grap[u].size() - 1,
		a.indx2 = grap[v].size() - 1;
		moves.pb(a);
	}
}

int c = 0;

void lenear(int sc,int n)
{
	for(int i = 1;i <= n; i++) if(grap[ i ].size() == 1) cst[ i ][0] = c++;
}


int main()
{
#ifdef PARTHO
    freopen("/home/partho/Desktop/IO/input.txt","r",stdin);
    freopen("/home/partho/Desktop/IO/output.txt","w",stdout);
    int start_time = clock();
#endif
FastIO;

	int n;
	cin >> n;
	input(n);
	lenear(1,n);

	for(int i = 0; i < moves.size(); i++){
		int u = moves[i].u, v = moves[i].v, cs = cst[u][moves[i].indx],cs2 = cst[v][moves[i].indx2];

		if(cs !=-1 && cs2 !=-1 ){
			cs = min(cs,cs2);
			cs2 = cs;
		}
		if(cs != -1) cout << cs << endl;
		else if(cs2 != -1) cout << cs2 << endl;
		else cout << c++ << endl;
	}  

#ifdef PARTHO
    int end_time = clock();
    printf("Time = %.4f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
#endif

    return 0;
}
///Before submit=>
///    *check for integer overflow,array bounds
///    *check for n=1
