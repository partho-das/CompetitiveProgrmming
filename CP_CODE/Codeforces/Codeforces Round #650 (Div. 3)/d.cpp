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

int freq[50];
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

	memset(freq, 0, sizeof freq);
	int n;

	string str;
	cin >> str >> n;
	vi v(n);
	int cnt = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> v[i];
		if(v[i] == 0) cnt++;
	}

	for(int i = 0; i < str.size(); i++)
	{
		int value = str[i] - 'a';
		freq[value]++;
	}

	int start = 25;
	for(int i = 25; i >= 0; i--)
		if(cnt <= freq[i]){
			start = i;
			break;
		}

	string res;

	for(int i = 0; i < n; i++){
		res.pb('1');
		if(v[i] == 0) res[i] = (char)(start + 'a');
	}

	while(1)
	{
		vi indx;

		int ck = 0;
		for(int i = 0; i < n; i++)
		{
				if(res[i] == '1')
				{
					ck = 1;
					ll sum = 0;
					for(int j = 0; j < n; j++) if(res[j] != '1') sum += abs(i - j);
					
					if(sum == v[i]) indx.pb(i);
				}
		}
		if(ck == 0) break;

		for(start = start - 1; start >= 0; start--)
		{
			if(indx.size() <= freq[start])
			{
				for(auto it : indx) res[it] = (char)('a' + start);
				break;
			}
		}

	}

	cout << res << endl;
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
