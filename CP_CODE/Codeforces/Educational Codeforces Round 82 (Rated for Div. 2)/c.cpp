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
int visit[30],taken[29][29];
deque<char> dq;


bool bfs(string &str)
{
	queue <char> q;
	char ch = str[0];

	visit[ch - 'a'] = 1;
	dq.pb(ch);
	set <char> st;
		for(int i = 1 ; i < str.size() ; i++)
		{
			if(str[i - 1] == ch ) st.insert(str[i]);
			if(str[ i ] == ch) st.insert(str[i - 1]);
		}
		if(st.size() > 2) return 0;

	int ck = 1;
	for(auto it : st)
	{
		q.push(it);
		taken[it - 'a'][ch - 'a'] = 1;
		taken[ch - 'a'][it - 'a'] = 1;

		visit[it - 'a'] = ck;
		if(ck == 1) dq.push_front(it);
		else dq.push_back(it);

		if(ck==1) ck = 2;
	}

	while(!q.empty())
	{
		ch = q.front();
		
		q.pop();
		set <char> st;
		for(int i = 1 ; i < str.size() ; i++)
		{
			if(str[i - 1] == ch ) st.insert(str[i]);
			if(str[ i ] == ch) st.insert(str[i - 1]);
		}
		if(st.size() > 2) return 0;

		int ck = visit[ch - 'a'];

		for(auto it : st)
		{
			
			if(taken[it - 'a'][ch - 'a'] != 1 &&
				taken[ch - 'a'][it - 'a'] != 1)
			{
				q.push(it);
				taken[it - 'a'][ch - 'a'] = 1;
				taken[ch - 'a'][it - 'a'] = 1;


			if(visit[it - 'a'] == 0)
			visit[it - 'a'] = ck;
			else
				{
					
					if(ck != visit[it - 'a']) return 0;
				}
			if(ck == 1)dq.push_front(it);
			else dq.push_back(it);

			}

			
		}




	}

	return 1;
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
    	string str;

    	cin >> str;
    	memset(visit,0,sizeof(visit));
		memset(taken,0,sizeof(taken)); 
		dq.clear();
		int ck = 1 ;
		if(str.size() > 1)
		(ck = bfs(str));
		if(ck == 1)
		{
			cout << "YES" << endl;	
		for(auto it : dq)
			cout << it;
		for(int i = 0;i < 26;i++)
		{
			if(visit[i] == 0)
				cout << (char)('a'+ i);
		}
		cout << endl;

		}
		else cout <<"NO" << endl;
		




    }


  
  #ifdef PARTHO
       int end_time = clock();
       printf("Time = %.4f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
  #endif
  return 0;
}