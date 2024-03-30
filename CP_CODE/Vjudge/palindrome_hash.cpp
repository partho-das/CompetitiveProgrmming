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


ull bigexp(ull base,ull pwer)
{
  if(pwer == 0) return 1;
    if(pwer&1) return bigexp(base,pwer - 1)*base;
    ull value = bigexp(base,pwer >> 1);
    return value*value;
}


ull forward_hash = 0,reverse_hash = 0,base =  313,cnt = 0,agent = 1;
void hash_function(char &ch)
{
    forward_hash = forward_hash * base + (ch - 'a' + 1);
    reverse_hash =  (ch - 'a' + 1) * agent + reverse_hash;
    agent*=base;

    return;
}



int main(){

  #ifdef PARTHO
       freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
       freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
       int start_time = clock();
  #endif
   FastIO;


  pair<ull, ull> now;
  char ch = 'a';

  int test,q;

  cin >> test;
  TEST(test)
  {



   string str;
   cin >> str;
   for(int i = 0;i<str.size() ;i++)
   {
      hash_function(str[i]);
   }

  //cout << forward_hash << " " << reverse_hash << endl;

    cin >> q;


    char c,cmd;

    ull value, k;
    printf("Case %d:\n",cse);
    while(q--)
    {
        cin >> cmd >> c >> k;

       for(int i = 0; i < k ; i++)
       {
          value =  bigexp(base, k-1);
          if(cmd == 'R')
          {
             hash_function(c);
          }
          else
          {
            if( i == 0 )
            {
                forward_hash = forward_hash +  (c - 'a' + 1) * agent * value;
                reverse_hash = reverse_hash * value*base + (c - 'a' + 1);
            }
            else
            {
                forward_hash = forward_hash + (c - 'a' + 1) * agent * bigexp(base, k - i-1);
                reverse_hash = reverse_hash + bigexp(base, i) * (c - 'a' + 1);
            }

          }

         
       }

       if(cmd == 'L') agent = agent * value*base;


      // cout << forward_hash << " " << reverse_hash << endl;

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
