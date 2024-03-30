#include <bits/stdc++.h>
using namespace std;

//____________________________________________________________________________________________________________________________________

#define PI  2*acos(0.0)
#define pf  printf
#define sc  scanf
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
#define sc1(n)         sc("%d",&n);
#define sc2(n, m)      sc("%d%d", &n, &m);
#define sc3(m, n, o)   sc("%d%d%d", &m, &n, &o);
#define scl(n)         sc("%lld", &n);
#define scll(n, m)     sc("%lld%lld", &n, &m);
#define sclll(n, m, o) sc("%lld%lld%lld", &n, &m, &o);
#define scf(f)         sc("%f",&f);
#define pn(n)        printf("%d\n", n);
#define ps(str)      printf("%s\n", str);
#define FOR(i,a,n)   for( int i = a; i < n; i++)
#define TEST(test)   for(int cse = 1; cse <= test; cse++)
#define all(x) (x).begin(), (x).end()
#define fap(x) cout << __LINE__ << " says: " << #x << " = " << x << "\n"
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const ll INF = 2000000000000000000LL;
const int inf = 0x3f3f3f3f;
ll MOD =  1e9 + 7;
const long double EPS = 1e-9;
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline double my_sqrt(T n) { double high = n, low = 0, mid, ans; int cnt = 100; while(cnt--) { mid = low + (high - low) / 2; if(mid * mid <= n) ans = mid, low = mid; else high = mid; } return ans; }
template<class T> inline T bigmod(T b, T p){ if(p <= 0) return 1; if(p & 1) return (b * bigmod(b, p - 1)) % MOD; ll x = bigmod(b, p >> 1); return (x * x) % MOD;}
//____________________________________________________________________________________________________________________________________


class student{

string name, sex;
int student_id;

public:

	void input()
	{
		cout << "Enter name of the student: ";
		cin >> name;
		cout << "Enter sudent id of the student: ";
		cin >> student_id;
		cout << "Enter sex of the sudent (male / female) : ";
		cin >> sex;
	}

	void output()
	{
		cout << "\nName of the student is : " << name << endl;
		cout << "Student id of " << name << " is " << student_id << endl;
		cout << "Sex of " << name << " is " << sex << endl;
	}

};

int main()
{

int studentcnt = 0;

cout << "Enter the number of student: ";
cin >> studentcnt;
student list1[studentcnt + 1];

for(int i = 0; i < studentcnt; i++)
{
    cout << "\nTaking Input for student : " << i + 1 << endl;
	list1[i].input();
}

for(int i = 0; i < studentcnt; i++)
{
    cout << "\nShowing information of student : " << i + 1 << endl;
	list1[i].output();
}



    return 0;
}
///Before submit=>
///    *check for integer overflow,array bounds
///    *check for n=1
