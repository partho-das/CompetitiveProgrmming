#include <bits/stdc++.h>
using namespace std;

//macros
#define PI  2*acos(0.0)
#define ll  long long
#define pf  printf
#define sc  scanf
#define ff  first
#define ss  second
#define mp  make_pair
#define pb  push_back
#define vi  std::vector<int>
#define pi  pair<int , int>
#define vll vector<long long>
#define pll pair<long long , long long>
#define FOR(i,n)    for(int i = 0; i < n; i++)
#define TEST(test)  for(int c = 1; c <= test; c++)
//________________________________________________________________________________________________________________


string gen(int n,int k)
{
    string str;
    int cnt  = 0;
    while(k>1) cnt+=2,str+= "()",k--;
    str+="(";
    for(int i = cnt+2;i<n;i+=2) str+="()";
    str+=")";
    return str;
}

pair<int ,int > cal(int i,int n,string &str,char ch)
{
  int a = i;
  for( i = i;i<n;i++){
    if(str[i] == ch){
       for(int x = a,j = i;x<j;x++,j--){
          swap(str[j],str[x]); 
       }
       return {a+1,i+1};
    }
  }
  return {a+1,a+1};

}
int main(){

   #ifdef PARTHO
       freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
       freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
       int start_time = clock();
   #endif
      
      int test;
      cin >> test;
      while(test--)
      {
        int n,k;
        cin >> n >> k;
        string str,gstr = gen(n,k);
        cin >> str;
        std::vector<pair <int,int> > v;
        for(int i = 0;i<n;i++){
            if(str[i]!=gstr[i]) {
              v.pb(cal(i,n,str,gstr[i]));
            }
        }
        cout << v.size() << endl;
        for(auto it : v)
          cout << it.ff << " " << it.ss << endl;

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
