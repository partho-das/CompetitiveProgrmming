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
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}

//____________________________________________________________________________________________________________________________________

const int maxn = 2e5 + 2;
int n, m, visit[maxn];

std::vector<long long> graph[maxn], income(maxn),people(maxn), res(maxn), v;
bool cmp(int a, int b)
{
	if(income[a] * people[b] > income[b] * people[a]) return 1;

	return 0;
}

void input()
{
	v.clear();
	double value;
	for(int i = 1; i <= n; i++)
	{
		graph[i].clear(), visit[i] = 0;
		cin >> income[i];
	}
	for(int i = 1; i <= n; i++)
	{
		cin >> people[i];
		v.pb(i); 
	}

	int u, v;

	for(int i = 0; i < m; i++)
	{
		cin >> u >> v;

		graph[u].pb(v);
		graph[v].pb(u);
	}

	return;
}


int bfs(int src)
{
	int cnt = 1;
	res[cnt++] = src;
	visit[src] = 1;
	queue<int> q;
	q.push(src);
	while(!q.empty())
	{
		int now = q.front();
		q.pop();
		for(int i = 0; i < graph[now].size(); i++)
		{
			int nxt = graph[now][i];
			if( (income[nxt] * people[v[0]] == income[v[0]] * people[nxt]) && visit[nxt] == 0)
			{
				visit[nxt] = 1;
				q.push(nxt);
				res[cnt++] = nxt;
			}
		}
	}



	return cnt - 1;
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


while(test--)
{
	cin >> n >> m;
	input();

	sort(all(v), cmp);


	int mxcnt = 0, indx = -1;
	for(int i = 0; i < n; i++)
	{	
		if( income[v[i]] * people[v[0]] == people[v[i]] * income[ v[0] ] ){	
			if(visit[v[i]] == 0)
			{
				int cnt = bfs(v[i]);
				if(mxcnt < cnt){
					mxcnt = cnt;
					indx = v[i];
				}
			}

		}
		else break;
	}

	if(mxcnt > 0)
	{

		for(int i = 0; i <= n ; i++) visit[i] = 0;
		bfs(indx);
	
	}
	cout << mxcnt << endl;

	for(int i = 1; i <= mxcnt ; i++)
	{

		cout << res[i];

		if(i != mxcnt) cout << " ";
		else cout << endl;
	}




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