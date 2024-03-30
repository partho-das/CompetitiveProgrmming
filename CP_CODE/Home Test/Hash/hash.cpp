#include <bits/stdc++.h>
using namespace std;


//____________________________________________________________________________________________________________________________________

#define PI  2*acos(0.0)
#define ll  long long
#define ull unsigned long long
#define pf  printf
#define sf  scanf
#define ff  first
#define ss  second
#define mp  make_pair
#define pb  push_back
#define vi  std::vector<int>
#define pi  pair<int , int>
#define vll vector<long long>
#define pll pair<long long , long long>
#define sc(n)       sf("%d",&n);
#define scf(f)      sf("%f",&f);
#define FOR(i,a,n)  for(int i = a; i < n; i++)
#define TEST(test)  for(int cse = 1; cse <= test; cse++)
//____________________________________________________________________________________________________________________________________

#define fap(x) cout << __LINE__ << " says: " << #x << " = " << x << "\n"


void dec_to_bin(int n,string &bin)
{
    while(n)
        bin.push_back('0'+(n&1)),n =  n>>1;

    for(int i = 0,j = bin.size()-1;i<j;i++,j--)
      swap(bin[i],bin[j]);
}

ll hashv[1000];
ll ck_value;
const int base = 52;
const ll MOD[] = {1000000007,1000000009};

ll get_hash(ll last,char ch)
{
  ll value;
  return value = ((last*base)%MOD[0]+(ch-'A'+1))%MOD[0];
}
void hash_gen(string &str,string &ckstr)
{
  hashv[0] = 0;
  ll hashvalue = 0;
  for(int i = 1;i<=str.size();i++)//genrate hash (1,n)
  {
      hashvalue = get_hash(hashvalue,str[i-1]);
      hashv[i] = hashvalue;
  }

  ck_value = 0;
  for(int i = 0;i<ckstr.size();i++)
    ck_value = get_hash(ck_value,ckstr[i]);

  return;
}


ll hash_check(int mlen,int len)
{
    ll value,power = (ll)(pow(base,len))%MOD[0];
    

    for(int i = 0;i<=mlen &&  (len+i <= mlen) ;i++)
    {
      value = (hashv[i+len] - ((hashv[i]*power)%MOD[0]))%MOD[0];
     if(value<0) value+=MOD[0];
      if(value == ck_value)
        return i;
     cout << value << endl;
    }
    return -1;
}


int count_unique_substrings(string const& s) {
    int n = s.size();

    const int p = 10;
    const int m = 1e9 + 9;
    vector<long long> p_pow(n);
    p_pow[0] = 1;
    for (int i = 1; i < n; i++)
        p_pow[i] = (p_pow[i-1] * p) % m;

    vector<long long> h(n + 1, 0);
    for (int i = 0; i < n; i++)
        h[i+1] = (h[i] + (s[i] - '0' + 1) * p_pow[i]) % m;

    int cnt = 0;
    for (int l = 1; l <= n; l++) {
        set<long long> hs;
        for (int i = 0; i <= n - l; i++) {
          long long cur_h = (h[i + l] + m - h[i]) % m;
          cout << h[i+l] << " " << h[i] << endl;
          cout << "cur_h " << cur_h << endl; 
            cur_h = (cur_h * p_pow[n-i-1]) % m;
            cout << "__cur_h "<< cur_h << endl;
            hs.insert(cur_h);

     // cout << i + l << " " << i << " n-i-1 = " << n-i-1 <<
     // " value = " << p_pow[n-i-1] << endl;

        } 
        cout << "--------------------------------" << endl;
        cnt += hs.size();
    }
    return cnt;
}

ll hs[3][100020],power[3][100020];
set<pair<ll,ll> > onecat_hash(string &str)
{
    ll sz = str.size(),base = 31,m = 1e9 + 9,n = 1e9 + 7;
    hs[0][0] = hs[1][0] = 0,power[0][sz] = power[1][sz] = 1;

    for(int i = 1;i<=sz;i++)
    {
        hs[0][i] = (hs[0][i-1]*base+(str[i-1]-'a'+1))%m;
        hs[1][i] = (hs[1][i-1]*base+(str[i-1]-'a'+1))%n;
        power[0][sz-i] = (power[0][sz-i+1] * base)%m;
        power[1][sz-i] = (power[1][sz-i+1] * base)%n;
      
    }
    set <pair<ll,ll>> unq_hs;

    ll first,second;
    for(int i = 1;i<=sz;i++)
    {
        first = (hs[0][sz] -  (hs[0][i] * power[0][i])%m + (hs[0][i-1] * power[0][i] + m)%m + m ) % m;
        second = (hs[1][sz] -  (hs[1][i] * power[1][i])%n + (hs[1][i-1] * power[1][i] + n)%n + n ) % n;
       
        unq_hs.insert({first,second});
    }
    return unq_hs;
}


ll solve()
{
    ll n,m,sum = 0;
    cin >> n >> m;
    set<pair<ll,ll> > add;
    std::map<pair<ll,ll>, ll> stor;
    std::vector<str> strstor;
    while(n--)
    {
        string str;
        cin >> str;
        v.pb(str);
        
        add = onecat_hash(str);

        for(auto it : add)
        {
            if(stor.find({it.first,it.second}) !=stor.end())
            {
                sum += stor[{it.first,it.second}];
                stor[{it.first,it.second}]++;
            }
            else stor[{it.first,it.second}] = 1;
        }
    }

    return sum;
}



void solve2()
{
    const int maxn = 1e5+5,m = 1e9+7,base = 31;
   
    ll n,len;
    cin >> n >> len;
     unordered_map< ull , ull > strhs;
      ull hs[len+5],power[len+5],cnt = 0;
    FOR(st,0,n)
    {

        string str;
        cin >> str;

        power[1] = 1,hs[0] = 0;
        str =  '#' + str;
        for(int i = 2; i <= len ;i++)
        {
            power[i] = (power[i-1]*base);
        }

        for(int i = 1 ; i <= len; i++)
        {

            hs[i] = (str[i] - 'a'+1)*power[i] + hs[i-1];
        }
        strhs[hs[len]]++;


        // for(int i = 1; i <= len;i++)
        // {
        //     cout << hs[i] << endl;
        // }

        ull prefix,newhash;
        for(int i = 1;i <= len; i++)
        {
            prefix = (hs[len] - hs[i]);
            for(char ch = 'a';ch <= 'z';ch++)
            {
                if(ch != str[i])
                {
                   newhash = ((prefix + (ch - 'a' + 1)*power[i] + hs[i-1]));
                    if(strhs.find(newhash) != strhs.end())
                      cnt += strhs[newhash];
                }
            }
        }

    }

       cout << cnt << endl;
}



int main(){

  #ifdef PARTHO
       freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
       freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
       int start_time = clock();
  #endif

    solve2();
  
   
  #ifdef PARTHO
       int end_time = clock();
       printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
  #endif
  return 0;
}


