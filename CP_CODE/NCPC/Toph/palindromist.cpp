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

ull power[1000110],forward_hash = 0,reverse_hash = 0,base =  313; 
pair<ull, ull> hash_function(string &nstr)
{
  ull hashv = 0,hashv2 = 0;
  for(int i = 1 ; i<=nstr.size() ;i++)
    hashv = hashv*base + (nstr[i - 1] - 'a' + 1);


  for(int i = 1 ; i<=nstr.size() ;i++)
    hashv2 = hashv2 + (nstr[i - 1] - 'a' + 1)*power[i];

  return {hashv,hashv2};

}


int main(){
 
  #ifdef PARTHO
       freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
       freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
       int start_time = clock();
  #endif
   FastIO;

   power[0] = 0,power[1] = 1;
  for(int i = 2 ; i<= 1e6+100;i++)
    power[i] = power[i - 1]*base;

  pair<ull, ull> now;
  string str;

  int test,q;

  cin >> test;
  TEST(test)
  {

    cin >> str;
    now = hash_function(str);
    forward_hash = now.ff,reverse_hash = now.ss;
    int cnt = str.size();
    cin >> q;

    char ch,cmd;
    int k;
    printf("Case %d:\n",cse);
    while(q--)
    {
        cin >> cmd >> ch >> k;
     
        str.clear();
        while(k--) str+=ch;

        now = hash_function(str);

        if(cmd == 'L')
        {
          forward_hash = now.ff * power[cnt + 1] + forward_hash;
          reverse_hash = reverse_hash*(power[str.size() + 1]) + now.ss;
        }
        else
        {
         forward_hash = forward_hash*(power[str.size() + 1]) + now.ff ;
         reverse_hash = now.ss * power[cnt + 1] + reverse_hash;
        }


        cnt+=str.size();
          if(forward_hash == reverse_hash)
            puts("Yes");
          else puts("No");

    }



   	   
  }
 
  #ifdef PARTHO
       int end_time = clock();
       printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
  #endif
  return 0;
}
 
 
 
///Before submit=>
///    *check for integer overflow,array bounds
///    *check for n=1