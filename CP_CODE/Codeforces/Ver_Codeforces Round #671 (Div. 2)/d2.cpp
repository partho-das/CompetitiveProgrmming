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

int n;
vi v;
void unique_function()
{

sort(all(v));

vi res(n + 1);

int ans = 0;
if(n & 1)
{
    int st = n / 2;

    for(int i = 0; i < n; i+= 2)
    {
        res[i] = v[st++];
        //cout << v[st] << endl;
    }

    st = 0;
    for(int i = 1; i < n; i += 2)
        res[i] = v[st++];

    ans = n / 2;
}
else
{
    int st = 0;

    for(int i = 0; i < n; i+= 2)
    {
        res[i] = v[st++];
    }

    st = n / 2;
    for(int i = 1; i < n; i += 2)
        res[i] = v[st++];

    ans = (n - 1) / 2;
}

printf("%d\n", ans);


for(int i = 0; i < n; i++)
    printf("%d ", res[i]);

}

set<int> unq_list;
map<int, int> freq;
priority_queue<pii> pq;

void multi_function()
{
    vi res;

    int ck = 0;

    if(pq.size() >= 2)
    {

            pii a = pq.top();
            pq.pop();
            pii b = pq.top();
            pq.pop();


            if(a.ss == *unq_list.begin())
            {
                res.pb(b.ss);
                b.ff--;
                res.pb(a.ss);
                a.ff--;

                if(!b.ff)
                {
                    if(pq.size())
                    {              
                        pii c = pq.top();
                        pq.pop();
                        res.pb(c.ss);
                        c.ff--;

                        if(c.ff) pq.push(c), freq[c.ss] = c.ff;
                        else unq_list.erase(c.ss), freq[c.ss] = 0;

                    }else ck = 1;
                }
                else res.pb(b.ss), b.ff--;

                if(a.ff) pq.push(a), freq[a.ss] = a.ff;
                else unq_list.erase(a.ss), freq[a.ss] = 0;

                if(b.ff) pq.push(b), freq[b.ss] = b.ff;
                else unq_list.erase(b.ss), freq[b.ss] = 0;
            }
            else
            {


                if(a.ss < b.ss)
                {
                    priority_queue<pii> nq;
                    nq.push(b);


                    while(!pq.empty())
                    {
                       // puts("HI");
                        b = pq.top();
                        pq.pop();


                        if(b.ss < a.ss) break;
                        nq.push(b);
                    }

                    while(!nq.empty())
                    {
                        pii now = nq.top();
                        nq.pop();
                        pq.push(now);
                    }
                }

                res.pb(a.ss);
                res.pb(b.ss);
                res.pb(a.ss);

                a.ff-= 2;
                b.ff--;

                if(a.ff) pq.push(a), freq[a.ss] = a.ff;
                else unq_list.erase(a.ss), freq[a.ss] = 0;

                if(b.ff) pq.push(b), freq[b.ss] = b.ff;
                else unq_list.erase(b.ss), freq[b.ss] = 0;

            }

            int big = 1;

            while( !ck && pq.size() > 1)
            {
                a = pq.top();
                pq.pop();

                if(a.ss == res.back()) b = pq.top() , pq.pop(), pq.push(a),  a = b;

                if(big)
                {
                    if(a.ss > res.back())
                    {
                        res.pb(a.ss);
                        swap(res[res.size() - 1], res[res.size() - 2]);
                    }
                    else res.pb(a.ss);
                    a.ff--, big = 0; 
                }
                else
                {
                    if(a.ss < res.back())
                    {
                        res.pb(a.ss);
                        swap(res[res.size() - 1], res[res.size() - 2]);
                    }
                    else res.pb(a.ss);
                    a.ff--, big = 1; 
                    
                }


                if(a.ff) pq.push(a), freq[a.ss] = a.ff;
                else unq_list.erase(a.ss), freq[a.ss] = 0;
            }

            if(!pq.empty())
            {

                a = pq.top();

                    if(big)
                    {
                        if(a.ss > res.back())
                        {
                            res.pb(a.ss);
                            swap(res[res.size() - 1], res[res.size() - 2]);
                        }
                        else res.pb(a.ss);
                        a.ff--, big = 0; 
                    }
                    else
                    {
                        if(a.ss < res.back())
                        {
                            res.pb(a.ss);
                            swap(res[res.size() - 1], res[res.size() - 2]);
                        }
                        else res.pb(a.ss);
                        a.ff--, big = 1; 
                        
                    }


                for(int i = 0; i < a.ff ; i++)
                    res.pb(a.ss);
            }

    }
    else ck = 1;

    if(ck)
     {
        puts("0");

        for(int i = 0; i < v.size(); i++) 
            printf("%d " , v[i]);
    }
    else {
        int cnt = 0;

       // printf("HI\n");
        for(int i = 1; i < res.size() - 1; i++)
        {
            if( res[i - 1] > res[i] && res[i] < res[i + 1]) cnt++;
        }


        printf("%d\n", cnt);

        for(int i = 0; i < res.size(); i++)
            printf("%d ", res[i]);
    }
}


int main()
{
#ifdef PARTHO
    freopen("/home/partho/Desktop/IO/input.txt","r",stdin);
    freopen("/home/partho/Desktop/IO/output.txt","w",stdout);
    int start_time = clock();
#endif
//FastIO;

sc1(n);



int value;
for(int i = 0; i < n;i++)
{
    sc1(value);
    v.pb(value);

    //fap(value);
    unq_list.insert(value);
    freq[value]++;
}

int mx = 0;
for(auto it : unq_list)
{
    int a = it, b = freq[it];

    pq.push({b, a});
    mx = max(mx, b);
}

if(mx == 1) unique_function();
else multi_function();



#ifdef PARTHO
    int end_time = clock();
    printf("Time = %.4f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
#endif

    return 0;
}
///Before submit=>
///    *check for integer overflow,array bounds
///    *check for n=1
