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
typedef vector<long long> vll;
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

struct node{
    int root;
    int move;
    int cost = 0;
};

int arr[200009];


void bfs(int n,int m)
{
    map<int , bool> origine,taken;
    std::vector<int> res;
    queue< node > Q;
    node nxtmove,now;
    int left,right,cst = 0;
    FOR(i,0,n) origine[arr[i]] = 1;

    FOR(i,0,n)
    {
        cst = 1,left = arr[i] + cst,right = arr[i] - cst;
        if( taken.find(left) == taken.end() && origine.find(left) == origine.end())
        {
            nxtmove.root = arr[i],nxtmove.move = left,nxtmove.cost = 1;
            Q.push(nxtmove);
            taken[left] = 1;

        }
        if( taken.find(right) == taken.end() && origine.find(right) == origine.end())
        {
            nxtmove.root = arr[i],nxtmove.move = right ,nxtmove.cost = 1;
            Q.push(nxtmove);
            taken[right] = 1;
        }
    }
    ll cost = 0;
    while(!Q.empty() && m)
    {
        now = Q.front();
        Q.pop();
        if(m) m--,cost+= now.cost,res.pb(now.move);
        left = now.move - 1,right = now.move + 1,now.cost++;

        if( taken.find(left) == taken.end() && origine.find(left) == origine.end())
        {
            nxtmove.root = now.root, nxtmove.move = left, nxtmove.cost = now.cost;
            Q.push(nxtmove);
            taken[left] = 1;
        }
        if( taken.find(right) == taken.end() && origine.find(right) == origine.end())
        {
            nxtmove.root = now.root, nxtmove.move = right, nxtmove.cost = now.cost;
            Q.push(nxtmove);
            taken[right] = 1;
        }

    }

    cout << cost << endl;
    for(auto it : res) cout << it << " ";

}


int main(){
 
  #ifdef PARTHO
       freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
       freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
       int start_time = clock();
  #endif
   FastIO;

   int n,m;

   cin >> n >> m;
   FOR(i,0,n){
    cin >> arr[i];
   }

   bfs(n,m);
   cout << endl;




       



  #ifdef PARTHO
       int end_time = clock();
       printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
  #endif
  return 0;
}
 
 
 
///Before submit=>
///    *check for integer overflow,array bounds
///    *check for n=1