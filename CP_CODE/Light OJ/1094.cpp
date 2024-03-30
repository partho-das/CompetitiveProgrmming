#include<bits/stdc++.h>
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

const int maxn = 3e4+5;
ll n,msc,msc2,lst; // msc = main source

std::vector <int> gra[maxn],cst[maxn];
bool visit[maxn];
ll cost_sum[maxn];

void init()
{
	
	for(int i = 0; i < n; i++)
	{
		gra[i].clear();
		cst[i].clear();
		visit[i] = 0,cost_sum[i] = 0;
	}
}
void input()
{
	int u,v,c,mx = -1;
	for(int i = 1;i < n; i++)
	{
		cin >> u >> v >> c;
		gra[u].pb(v), gra[v].pb(u);
		cst[u].pb(c), cst[v].pb(c);
		if(c > mx)
		{
			mx = c;
			msc = u; 
			msc2 = v;
		}
	}
	lst = msc;

}

ll bfs(int sc)
{
	queue <int> q;
	q.push(sc);
	visit[sc] = 1;

	ll sum = 0;
	while(!q.empty())
	{
		int now = q.front();
		q.pop();
		lst = now;
		for(int i = 0;i < gra[now].size(); i++)
		{
			int nxt = gra[now][i],c = cst[now][i];
			if(!visit[nxt])
			{
				visit[nxt] = 1;
				q.push(nxt);
				cost_sum[nxt] = cost_sum[now] + c;
				if(sum < cost_sum[nxt])
				{
					sum = cost_sum[nxt];
				}
			}
		}
	}
	return sum;
}






int main()
{
#ifdef PARTHO
    freopen("/home/partho/Desktop/IO/input.txt","r",stdin);
    freopen("/home/partho/Desktop/IO/output.txt","w",stdout);
    int start_time = clock();
#endif
FastIO;

int test;
cin >> test;
int tc = 1;
while(test--)
{
	cin >> n;
	init();
	input();
	ll sum = bfs(msc);
	for(int i = 0;i < n;i++) visit[i] = 0,cost_sum[i] = 0;
	sum = max(sum,bfs(msc2));
	



	cout << "Case " << tc++ << ": " << sum << endl;

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
