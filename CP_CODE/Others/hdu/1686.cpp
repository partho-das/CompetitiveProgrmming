#include <iostream>
#include <string>
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
// typedef std::vector<int> vi;
// typedef vector<long long> vll ;
// typedef pair<int, int> pii;
// typedef pair<ll, ll> pll;
#define sc(n)       scanf("%d",&n);
#define scf(f)      scanf("%f",&f);
#define FOR(i,a,n)  for(int i = a; i < n; i++)
#define TEST(test)  for(int cse = 1; cse <= test; cse++)

#define all(x) (x).begin(), (x).end()
#define fap(x) cout << __LINE__ << " says: " << #x << " = " << x << "\n"
//#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const ll INF = 2000000000000000000LL;
const int inf = 0x3f3f3f3f;
const long double EPS = 1e-9;
//____________________________________________________________________________________________________________________________________

const int maxn = 1e6;
ull power[ maxn + 5],hashv[maxn + 5];
ull hashfunction(string &str,string &cstr)
{	
	int size = str.size();
	
	ull base = 313,ckvalue = 0;
	power[1] = 1,hashv[0] = 0;
	str = '#' + str;
	cstr = '#' + cstr;
	for(int i = 2; i<=size ;i++ ) power[i] = power[i-1]*base;
	for(int i = 1 ; i <= size; i++ ) hashv[i] = hashv[i-1] + (str[i] - 'A' + 1)*power[i];
	for(int i = 1; i < cstr.size() ; i++ ) ckvalue = (cstr[i] - 'A' + 1)*power[i] + ckvalue;

	size = cstr.size() - 1;
	int cnt = 0;
	for(int l = 0,r = l + size;  r <str.size() ; l++,r++ )
	{
			
		if(hashv[r] == hashv[l] + power[l + 1]*ckvalue) cnt++;
	}
	return cnt;
}

int main(){

	#ifdef PARTHO
       freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
       freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
       //int start_time = clock();
  	#endif
   	//FastIO;


   	int test;

   	cin >> test;

   	while(test--)
   	{


   	string str,ckstr;

   	cin >> ckstr >> str;

   	int cnt = 0;
   	if(str.size() >= ckstr.size())
   	cnt = hashfunction(str,ckstr);
	
	
   	cout << cnt << endl;


   	}


  #ifdef PARTHO
       //int end_time = clock();
     //  printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
  #endif
  return 0;
}



///Before submit=>
///    *check for integer overflow,array bounds
///    *check for n=1
