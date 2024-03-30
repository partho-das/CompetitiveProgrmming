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
template <class T> inline double my_sqrt(T n) { double high = n + 5, low = 0, mid, ans; int cnt = 100; while(cnt--) { mid = low + (high - low) / 2; if(mid * mid <= n) ans = mid, low = mid; else high = mid; } return ans; }
template <class T> inline T bigmod(T b, T p){ if(p <= 0 || b == 0) return 1; ll x = b; if(p & 1) return (x * bigmod(b, p - 1)) % MOD; x = bigmod(b, p >> 1); return (x * x) % MOD;}
template <class T> inline string to_string(const pair<T,T> &p) {
    return "{" + to_string(p.first) + "," + to_string(p.second) + "}";  
}
#ifdef PARTHO
#define dbg(x) cout << __LINE__ << " says: " << #x << " = " << x << "\n"
#else
#define dbg(x)
#endif
//____________________________________________________________________________________________________________________________________


string find_best3(string str){

	string res = "zzzzz", temp;
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			if(j == i) continue;
			for(int k = 0; k < 3; k++){
				if(k == j || k == i) continue;
				string temp;
				temp.pb(str[i]);
				temp.pb(str[j]);
				temp.pb(str[k]);
				string rtemp = temp;
				reverse(all(temp));
				res = min(res, max(temp, rtemp));
			}
		}
	}
	//cout << res << endl;
	return res;
}

string find_best4(string str){
	string res = "zzzzz", temp;
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			if(j == i) continue;
			for(int k = 0; k < 4; k++){
				if(k == j || k == i) continue;
				for(int l = 0; l < 4; l++){
					if(l == j ||  l == k || l == i) continue;
					string temp;
					temp.pb(str[i]);
					temp.pb(str[j]);
					temp.pb(str[k]);
					temp.pb(str[l]);
					string rtemp = temp;
					reverse(all(temp));
					res = min(res, max(temp, rtemp));
				}
			}
		}
	}
	//cout << str << " " << res << endl;
	return res;
}
void solve(){
	
	string str;

    vi freq(27, 0);
    cin >> str;
    vector<char>res((int)str.size(), '0');
    for(int i = 0; i < (int)str.size(); i++){
        freq[str[i] - 'a']++;
    }
    string strcpy = str;
    sort(all(str));
    reverse(all(str));

    int cnt = str.size(), found = -1;
    int i = 0, j = cnt - 1;
    while(cnt && found == -1){
    	//cout << cnt << endl;
    	if(cnt >= 2){

				if(i == 0){
					res[i] = max(str[j], str[j - 1]);
					res[j] = min(str[j], str[j - 1]);
		

		// 			for(auto it : res){
    	// 	cout << it;
    	// }
    	// cout << endl;

				}
				else{
					string temp;
					temp.pb(res[i - 1]);
					temp.pb(res[j + 1]);
					temp.pb(str[cnt - 1]);
					temp.pb(str[cnt - 2]);
					temp = find_best4(temp);
					//cout << temp << endl;
	    			res[i - 1] = temp[0];
	    			res[i] = temp[0 + 1];
	    			res[j] = temp[0 + 2];
	    			res[j + 1] = temp[0 + 3];

	    			if(res[i - 1] != res[j + 1]){

	    				break;
	    			}
				}
				i++,j--;
	    		cnt -= 2;

	    		str.pop_back();
	    		str.pop_back();
    	}
    	else{
    		if(cnt == 1){
    			if(i == 0){
    				res[i] = str.back();
    			}
    			else{
    				

	    			string temp;
	    			//cout << temp << endl;
	    			temp.pb(res[i - 1]);
					temp.pb(res[j + 1]);
					temp.pb(str.back());

	    			//break;

	    			temp = find_best3(temp);
	    			res[i - 1] = temp[0];
	    			res[i] = temp[1];
	    			res[i + 1] = temp[2];

    			}
    		}
    		i = inf;
    		break;
    	}


    }

    	for(int x = str.size() - 1; i <= j; i++){
    		res[i] = str[x--];
    	}
    	for(auto it : res){
    		cout << it;
    	}
    	cout << endl;


	return;
}


int main() {
     #ifdef PARTHO
        freopen("/home/partho/Desktop/CODEFORCES/IO/input.txt","r",stdin);
        freopen("/home/partho/Desktop/CODEFORCES/IO/output.txt","w",stdout);
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
