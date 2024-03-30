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




int main()
{

#ifdef PARTHO
    freopen("/home/partho/Desktop/IO/input.txt","r",stdin);
    freopen("/home/partho/Desktop/IO/output.txt","w",stdout);
    int start_time = clock();
#endif

    FastIO;


    ll n,m,k,mxdis;

    cin >> n >> m >> k;

    mxdis = 4 * n * m - 2 * n - 2 * m;
    if(mxdis < k)
    {
        cout << "NO" << endl;
        return 0;
    }

    std::vector<pair<int,char> > v;

    ll r = n - 1,c = m - 1;

// for first row .. first comumn to last comumn =>
    int dis = min(k,c);

    k -= dis;
    if(dis)
        v.pb({dis,'R'});

    if(k > 0)
    {

// going back from to last column to first comumn
// travel one column and trave that comumn all path
        int trv = c;
        while(trv--)
        {

            // for last colum dow
            dis = min(k,r);

            k -= dis;
            if(dis)
                v.pb({dis,'D'});
            // for last colum up


            dis = min(k,r);
            k -= dis;

            if(dis)
                v.pb({dis,'U'});


            if(k)
            {

                k--;
                v.pb({1,'L'});
            }

        }
    }


    if(k > 0)
    {
// nwo we are in the first column
// going first row to the last row
// travel one row and trave that row all pathe
// first  right. then left.
        int trv = r;
        while(trv--)
        {

            // for first colum down
            if(k>0)
            {	
	            k--;
	            v.pb({1,'D'});
            }

            dis = min(k,c);
            k -= dis;
            //  row fist to last comn; 
            if( dis )
                v.pb({dis,'R'});

            // row flast to fist comn; 
            dis = min(k,c);
            k -= dis;
            if(dis)
                v.pb({dis,'L'});


        }
    }

    if(k>0)
    {// for last colum up
        dis = min(r,k);
        if(dis)
            v.pb({dis,'U'});

    }
    cout << "YES" << endl;
    cout << v.size() << endl ;
    for(auto it : v)
        cout << it.ff << " " << it.ss << endl;


#ifdef PARTHO
    int end_time = clock();
    printf("Time = %.4f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
#endif
    return 0;
}
