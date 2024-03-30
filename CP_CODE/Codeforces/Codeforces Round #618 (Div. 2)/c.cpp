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
 
int fre[33];
 
 
 
 
 
int main()
{
 
#ifdef PARTHO
    freopen("/home/partho/Desktop/IO/input.txt","r",stdin);
    freopen("/home/partho/Desktop/IO/output.txt","w",stdout);
    int start_time = clock();
#endif
    // FastIO;
 
    int n,arr[100009];
 
 
    cin >> n;
 
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
 
        bitset<32> binary(arr[i]);
 
        int value = binary.to_ulong();
 
        for(int j = 0; j < 32 ; j++)
        {
            if(binary[j] == 1) fre[j]++;
        }
 
 
    }
 
    long long value,mx = 0,res = -1;
    for(int i = 0; i < n; i++)
    {
 
        bitset<32> binary(arr[i]);
 
 
        for(int j = 0; j < 32 ; j++)
        {
            if(binary[j] == 1 && fre[j] == 1 ) binary[j] = 1;
            else binary[j] = 0;
        }
 
 
        value = binary.to_ulong();
 
 
        if(value >= mx )
        {
 
            mx = value;
            res = arr[i];
        }
 
 
    }
 
    cout << res << " ";
        int ck = 1;
    for(int i = 0; i < n; i++)
    {
 
        if(res != arr[i] || ck == 0)
            cout << arr[i] << " ";
        else if(res == arr[i]){
            ck = 0;
        }
    }
 
    cout << endl;
 
 
 
#ifdef PARTHO
    int end_time = clock();
    printf("Time = %.4f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
#endif
    return 0;
}
