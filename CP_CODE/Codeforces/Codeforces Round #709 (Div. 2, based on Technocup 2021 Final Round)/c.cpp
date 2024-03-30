#include <bits/stdc++.h>
using namespace std;
 
//____________________________________________________________________________________________________________________________________
#define PI  2*acos(0.0)
#define pf  printf
#define sc  scanf
#define ff  first
#define ss  second
#define pb  push_back
typedef long long ll;
typedef unsigned long long ull;
typedef std::vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define sc1(n)         sc("%d",&n)
#define sc2(n, m)      sc("%d%d", &n, &m)
#define sc3(m, n, o)   sc("%d%d%d", &m, &n, &o)
#define scl(n)         sc("%lld", &n)
#define scll(n, m)     sc("%lld%lld", &n, &m)
#define sclll(n, m, o) sc("%lld%lld%lld", &n, &m, &o)
#define scf(f)         sc("%lf",&f);
#define pn(n)          pf("%d\n", n);
#define FOR(i,a,n)   for( int i = a; i < n; i++)
#define all(x) (x).begin(), (x).end()
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int MOD =  1e9 + 7;
const long double EPS = 1e-9;
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline double my_sqrt(T n) { double high = n, low = 0, mid, ans; int cnt = 100; while(cnt--) { mid = low + (high - low) / 2; if(mid * mid <= n) ans = mid, low = mid; else high = mid; } return ans; }
template <class T> inline T bigmod(T b, T p){ if(p <= 0 || b == 0) return 1; if(p & 1) return (b * bigmod(b, p - 1)) % MOD; ll x = bigmod(b, p >> 1); return (x * x) % MOD;}
#ifdef PARTHO
#define dbg(x) cout << __LINE__ << " says: " << #x << " = " << x << "\n"
#else
#define dbg(x)
#endif
//____________________________________________________________________________________________________________________________________

struct node{
	int id, fcnt;

	node(){}
	node(int _v, int _c){
		id = _v, fcnt = _c;
	}

	bool operator>(const node& a) const {
		return fcnt > a.fcnt;
	}
};

const int maxn = 1e5;
vi day[maxn + 5];
set<int>friends[maxn + 5];
int freq[maxn + 5], visit[maxn + 5], leftt[maxn + 5];
priority_queue< node , vector<node> , greater<node> > pq;

void showpq(){

priority_queue< node , vector<node> , greater<node> > temp = pq;

	while(!temp.empty()){
		cout << temp.top().id << " " << temp.top().fcnt << endl;
		temp.pop(); 
	}
}


void solve(){
    
    int n, m;

    sc2(n, m);

    //cout << n << " " << m << endl;
    while(!pq.empty()) pq.pop();

    for(int i = 0; i <= max(n, m); i++){
    	friends[i].clear();
    	day[i].clear();
    	freq[i] = 0;
    	visit[i] = 0;
        leftt[i] = (m + 1) / 2;
    }
    int ck = 0, cnt = 0;
    vi res(m + 1);
    for(int i = 0; i < m; i++){
    	int k;
    	sc1(k);
    	//cout << k << endl;
    	day[i + 1].resize(k);
    	for(int j = 0; j < k; j++){
    		sc1(day[i + 1][j]);

            if(k == 1){
                cnt++;
                leftt[day[i + 1][j]]--;
                res[i + 1] = day[i + 1][j];
                if(leftt[ day[i + 1][j] ] < 0){
                    ck = 1;
                }
                continue;
            }

    		friends[ day[i + 1][j] ].insert(i + 1);
    		freq[ day[i + 1][j] ]++;
            //cout << day[i + 1][j] << " " << i + 1 << endl;
    	}
    	//puts("");
    }

    if(ck){
        puts("NO");
        return;
    }
    for(int i = 1; i <= n; i++){
        if(freq[i])
    	pq.push(node(i, freq[i]));
    }
    
    int indx = cnt;
    while(indx < m && !pq.empty()){
    	node now = pq.top();
    		pq.pop();
    	if(visit[now.id] || !freq[now.id]){
    		continue;
    	}

    	int lim = min( {freq[now.id], leftt[now.id] });

    	for(int i = 0; i < lim; i++){
    	   int move = *friends[now.id].begin(), dy = move;
    		res[dy] = now.id;

    		indx++;
    		friends[ now.id ].erase(dy);

    		for(int j = 0; j < day[dy].size(); j++){
    			freq[ day[dy][j] ]--;
                friends[ day[dy][j] ].erase(dy);
    			pq.push( node(day[dy][j], freq[ day[dy][j]] )); 
    		}
            if(indx == m) break;
    	}
    	visit[now.id] = 1;
    	//break;

       

    }

    if(indx < m) puts("NO");
    else{
    	puts("YES");
    	for(int i = 1; i < res.size(); i++) cout << res[i] << " ";
    	puts("");
    }




    return;
}



int main() {
    #ifdef PARTHO
        freopen("/mnt/Stable/Dropbox/IO/input.txt","r",stdin);
        freopen("/mnt/Stable/Dropbox/IO/output.txt","w",stdout);
        int start_time = clock();
    #endif
    //FastIO;

    int test = 1;

    sc1(test);

    while(test--){
        solve();
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