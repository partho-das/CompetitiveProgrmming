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


int main()
{
#ifdef PARTHO
    freopen("/home/partho/Desktop/IO/input.txt","r",stdin);
    freopen("/home/partho/Desktop/IO/output.txt","w",stdout);
    int start_time = clock();
#endif
FastIO;

int test,tc = 1;
cin >> test;
while(test--)
{
	int n,q;

	cin >> n >> q;
	printf("Case %d:\n",tc++);
	deque<int> dq;
	while(q--){
		string str;
		int value,ck = 0;
		cin >> str;
		if(str == "pushLeft"){
			cin >> value;
			if(dq.size() >= n) ck = 1;
			else{
				dq.push_front(value);
				printf("Pushed in left: %d\n",value);
			}
		}
		else if(str == "pushRight"){
			cin >> value;
			if(dq.size() >= n) ck = 1;
			else {
				dq.push_back(value);
				printf("Pushed in right: %d\n",value);
			}

		}
		else if(str == "popLeft"){
			if(dq.empty()) ck = 2;
			else {
				value = dq.front();
				dq.pop_front();
				printf("Popped from left: %d\n", value);
			}
		}
		else if(str == "popRight"){
			if(dq.empty()) ck = 2;
			else{
				value = dq.back(); 
				dq.pop_back();
				printf("Popped from right: %d\n", value);
			}
		}
		if(ck == 1) puts("The queue is full");
		else if(ck == 2) puts("The queue is empty");
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
