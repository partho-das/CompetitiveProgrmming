#include <bits/stdc++.h>

using namespace std;

#define PI 2*acos(0.0)
#define pf printf
#define sc scanf
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef unsigned long long ull;
typedef std::vector<int> vi;
typedef std::vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define sc1(n) sc("%d", &n)
#define sc2(n, m) sc("%d%d", &n, &m)
#define sc3(n, m, o) sc("%d%d%d", &n, &m, &o)
#define scl(n) scanf("%lld", &n);
#define scll(n, m) scanf("%lld%lld", &n, &m)
#define sclll(n, m, o) scanf("%lld%lld%lld", &n, &m, &o)
#define all(x) (x).begin(), (x).end()

#define FastIO ios_base::sync_with_stdio(false);cin.tie(nullptr);
const ll INF = 0x3f3f3f3f3f3f3f3f;
int t = 1;

vi pos;
pii cycle_lenght(vi v, int i){
	int cnt = (v[i] != i);
	int mnindx = i;
	int temp;

	pos.pb(i);

	while(v[i] != i){
		mnindx = min( min(mnindx, v[i]) , min(mnindx, v[i]) );
		pos.pb(v[i]);
		swap(v[i], v[ v[i] ]);
		mnindx = min(i, mnindx);
		cnt++;
	}
	return {cnt, mnindx};
}
ll score(vi &v, int i){

	ll sum = 0;
	int content = 1;
	if(v[1] == 1){
		swap(v[i], v[1]);
		sum = 1 + i;
	}
	while(v[1] != 1){	
		sum += 1 + v[1];
		swap(v[1], v[ v[1] ]);
	}
	return sum;
}
ll score2(vi &v, int i){

	ll sum = 0;
	while(v[i] != i){
		sum += i + v[i];
		swap(v[i], v[ v[i] ]);
	}
	return sum;
}
int minpos2 = 1e9;
bool f(vi v, int mnindx){

	ll minscore = INF;
	vi tempv = v;

	for(int i = 0; i < pos.size(); i++){
		v = tempv;
		int count = score2(v, pos[i]);
		if(minscore > count){
			minscore = count;
			minpos2 = pos[i];
		}
	}
	v = tempv;
	if(minscore > score(v, mnindx)){
		return 1;
	}
	return 0;

}

void solve(){

	int n;
	sc1(n);
	vi v(n + 1);

	for(int i = 1; i <= n; i++){
		sc1(v[i]);
	}
	ll res = 0;
	for(int i = 1; i <= n; i++){
		pii ckvaue = cycle_lenght(v, i);
		if(v[i] != i &&  ckvaue.ff >= 6){
			res += score(v, ckvaue.ss);
		}
		else if( ckvaue.ff ){
			minpos2 = 1e9;
			if(f(v, ckvaue.ss)){
				res += score(v, ckvaue.ss);
			}
			else{
				res += score2(v, minpos2);
			}
		}
		pos.clear();
	}

	printf("%lld\n", res);

}

int main()
{
    int start_time = clock();

	int test = 1;
	sc1(test);

	while(test--) {
		solve();
	}

	return 0;
}
