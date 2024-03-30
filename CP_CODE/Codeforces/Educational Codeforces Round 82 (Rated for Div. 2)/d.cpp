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
 

void pop_front(std::vector<ll> &v)
{
	if (v.size() > 0) {
		v.erase(v.begin());
	}
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
    	ll n,m,sum = 0,value,indx ,cnt = 0;
    	cin >> n >> m;

    	std::vector< ll > v,bin;

    	for(int i = 0;i < m; i++)
    	{
    		cin >> value;
    		v.pb(value);
    		sum += value;
    	}

    	if(sum < n) {cout << -1 << endl; continue; }


    	for(ll i = 0;i < 63;i++)
    	{
    		value = (ll)1 << i;
    		if(value & n)
    		bin.pb(value);
    	}
    	sort(all(v));

    	std::vector<ll> ::iterator it;
    	while(!bin.empty())
    	{
    		
    		value = bin[0];
    		pop_front(bin);
    		sum = 0;

    		while(sum != value)
    		{
    			sum = 0;
    		it = upper_bound(all(v),value);
    		indx = it - v.begin();
    		indx--;
    		int in = indx;
    		for(int i = indx ;i >= 0;i--)
    		{
    			sum+= v[i],in = i;
    			if(sum == value) break;
    		}
  

    		if(sum == value)
    		{
    			v.erase(v.begin() + in, v.begin() + indx+1);

    		} 
    		else {

	    			indx++;
	    			ll ck = v[indx];
	    			v[indx] = v[indx] >> 1;
	    			if( ck != v[indx])
	    			it = v.insert(v.begin() + indx, v[indx]);

	    			cnt++;
    			}

    		}
    	}

    	cout << cnt << endl;



    }


  
  #ifdef PARTHO
       int end_time = clock();
       printf("Time = %.4f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
  #endif
  return 0;
}