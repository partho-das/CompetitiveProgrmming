#include <bits/stdc++.h>
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

/// Typedef
typedef long double ld;
typedef long long ll;
typedef unsigned long ul;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pld;
typedef vector< pii > vii;

#define pb                  push_back
#define ppb                 pop_back
#define MP                  make_pair
#define ff                  first
#define ss                  second
#define sf                  scanf
#define pf                  printf
#define loop(i, y)          for(int i=0; i<int(y); i++)
#define FOR(i, x, y)        for(int i=int(x); i<int(y); i++)
#define ROF(i, x, y)        for(int i=int(x-1); i>=int(y); i--)
#define tr(it, container)   for(auto it = container.begin(); it != container.end(); it++)
#define Binary(x,b)         std::bitset< b >( x ).to_string()
#define fastIO              ios::sync_with_stdio(false);    cin.tie(nullptr);   cout.tie(nullptr)
#define ran(a, b)           ((((rand() << 15) ^ rand()) % ((b) - (a) + 1)) + (a))
#define CLR(x, y)           memset(x, y, sizeof(x))
#define Read(x)             freopen(x,"r",stdin)
#define Write(x)            freopen(x,"w",stdout)
#define sc(n)               sf("%d",&n)
#define sc2(a,b)            sf("%d%d",&a,&b)
#define sc3(a,b,c)          sf("%d%d%d",&a,&b,&c)
#define sc4(a,b,c,d)        sf("%d%d%d%d",&a,&b,&c,&d)
#define scll(n)             sf("%lld",&n)
#define scll2(a,b)          sf("%lld%lld",&a,&b)
#define scll3(a,b,c)        sf("%lld%lld%lld",&a,&b,&c)
#define scll4(a,b,c,d)      sf("%lld%lld%lld%lld",&a,&b,&c,&d)
#define bitCheck(N,in)      ((bool)(N&(1<<(in))))
#define bitOff(N,in)        (N&(~(1LL<<(in))))
#define bitOn(N,in)         (N|(1LL<<(in)))
#define bitFlip(a,k)        (a^(1LL<<(k)))
#define bitCount(a)         __builtin_popcount(a)
#define bitCountLL(a)       __builtin_popcountll(a)
#define bitRightMost(a)     __builtin_ctzll(a)
#define bitLeftMost(a)      (63-__builtin_clzll(a))
#define SQR(x)              ((x)*(x))
#define mxEq(a,b)           (a = max(a,b))
#define all(c)              c.begin(), c.end()
#define unq(v)              sort(all(v)), (v).resize(unique(all(v)) - v.begin())
#define common(a,b)         sort(all(a)), sort(all(b)), a.erase(set_intersection(all(a),all(b),a.begin()),a.end())
#define uncommon(a,b)       sort(all(a)), sort(all(b)), a.erase(set_symmetric_difference(all(a),all(b),a.begin()),a.end())

// uniform random generator -->
// uniform_int_distribution<int> dist(0, 1);
// default_random_engine gen;

// *X.find_by_order(k) //returns the kth largest element.(0-based)
// X.order_of_key(val) //returns the no. of values less than val
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; // C++98
// template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T> inline T bigMod(T p,T e,T M){ ll ret = 1; for(; e > 0; e >>= 1){ if(e & 1) ret = (ret * p) % M; p = (p * p) % M; } return (T) ret;}
template <class T> inline T modInverse(T a,T M){return bigMod(a,M-2,M);}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T lcm(T a,T b) {a=abs(a);b=abs(b); return (a/gcd(a,b))*b;}
template <class T> inline string int2String(T a){ostringstream str; str<<a; return str.str();}
const int dr[] = { 0,  1,  0, -1,        -1,  1,  1, -1,     -2, -2,  2,  2, -1, -1,  1,  1};
const int dc[] = { 1,  0, -1,  0,         1,  1, -1, -1,     -1,  1, -1,  1, -2,  2, -2,  2};


/// Constants
#define MAX                 2250000000000
#define MOD                 1000000007
//#define base                1000000007
#define eps                 1e-9
#define INF                 LLONG_MAX
#define inf                 2000000000
#define PI                  (2.0*acos(0.0))  // 3.1415926535897932
#define Log(b,x)            (log(x)/log(b))


/// Debug
#define dbg(x)              cout << #x << " = " << x << endl
#define out2(a,b)           cout<<a<<" "<<b<<endl
#define out3(a,b,c)         cout<<a<<" "<<b<<" "<<c<<endl
#define out4(a,b,c,d)       cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl
#define out5(a,b,c,d,e)     cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<endl
void fileIO()
{
	#ifndef ONLINE_JUDGE
        Read("//home//pranto//Desktop//input.txt");
        Write("//home//pranto//Desktop//output.txt");
    #else
      // Read("immetric.in");
      // Write("immetric.out");
    #endif
}

/// Priority Queue custom compare
// std::priority_queue<int, std::vector<int>, decltype(&cmp) > pq(cmp);

bool isOperator(char ch){   
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '^' || ch == '|' || ch == '&' || ch == '!';
}    
struct st{
    int d;
    char op;
    bool isop = 0,isVar = 0,isnum = 0;
    st(char ch){
        if(isOperator(ch))      op = ch,isop = 1, isnum = isVar = 0;
        else if(ch != '(' && ch != ')') op = ch,isVar = 1, isnum = isop = 0;
        else isop = isnum = isnum = 0, op = ch;
    }
    st(int v){  d = v,  isnum = 1, isop = isVar = 0;}
    st(){
        isop = 0,isVar = 0, isnum = 0;
    }
};
std::map<int, int> value;
int Evaluate_Postfix(std::vector<st> &v){ // Evaluate vector v
	stack<int> stk;
	int a,b;
	for(int siz = v.size(), i = 0; i < siz; i++){
		if(v[i].isop){
			b = stk.top();	stk.pop();

			if(v[i].op == '!'){ // Unary ...
				stk.push(!b);
				continue;
			}

			a = stk.top();	stk.pop();	 //out3(a,v[i].op,b);

			     if(v[i].op == '+')		stk.push(a+b);
			else if(v[i].op == '-') 	stk.push(a-b);	
			else if(v[i].op == '*') 	stk.push(a*b);
			else if(v[i].op == '/') 	stk.push(a/b);
			else if(v[i].op == '&')		stk.push(a&b);
			else if(v[i].op == '|')		stk.push(a|b);
		}
		else if(v[i].isVar) stk.push(value[v[i].op]);
		else stk.push(v[i].d);
	}
	return stk.top();
}

int prec(char ch){
    if(ch == '|')               return 1;
    if(ch == '&')               return 2;
    if(ch == '+' || ch == '-')  return 3;
    if(ch == '*' || ch == '/')  return 4;
    if(ch == '!')               return 5;
}
void Infix_To_Postfix(std::vector<st> &v){
    std::vector<st> p;  
    stack<st> stk;
    stk.emplace('(');
    v.emplace_back(')');
    for(int siz = v.size(), i = 0; i < siz; i++){
        if(v[i].isnum || v[i].isVar)    p.push_back(v[i]);
        else if(v[i].op == '(')         stk.push(v[i]);
        else if(v[i].isop){
            while(stk.top().op != '('){
                if(prec(stk.top().op) >= prec(v[i].op)){
                    p.push_back(stk.top());
                    stk.pop();
                    if(stk.empty()) break;
                }
                else    break;
            }
            stk.push(v[i]);
        }
        else{
            while(stk.top().op != '('){
                p.push_back(stk.top());
                stk.pop();
                if(stk.empty()) break;
            }
            stk.pop();
        }
    }
    v = p;
}
inline void Input_Exp(string exp, std::vector<st> &v){
    char ch;
    int sum = 0, i = 0, ln = exp.length(), num = 0;
    do{
        ch = exp[i++];
       
        if(isdigit(ch)) sum = sum*10 + (ch-'0'), num = 1;
        else if(ch != ' ') {
            if(num) v.emplace_back(sum), sum = num = 0;
            v.emplace_back(ch);
        }
        else if(sum) v.emplace_back(sum), sum = num = 0;
    }
    while(i < ln);
    if(num) v.emplace_back(sum), sum = num = 0;
}
int n;

bool BT(int pos, std::vector<st> &v1, std::vector<st> &v2){
	if(pos >= n){
		int r1 = Evaluate_Postfix(v1);
		int r2 = Evaluate_Postfix(v2);	//out2(r1,r2);
		return r1 == r2;
	}
	value[var[pos]] = 0;	if(!BT(pos+1,v1,v2))	return 0;
	value[var[pos]] = 1;	if(!BT(pos+1,v1,v2))	return 0;
	return 1;
}
char buff[200];
int main()
{
	//fastIO;
	fileIO();  int start_s = clock(); 

	string exp1,exp2;

	int t,cs = 0; sc(t); 
	while(t--){
		scanf("%s",buff);	exp1 = buff;
		scanf("%s",buff);	exp2 = buff;	//out2(exp1,exp2);

		value.clear();
		var.clear();

		std::vector<st> v1,v2;
		Input_Exp(exp1,v1);
		Infix_To_Postfix(v1);

		Input_Exp(exp2,v2);
		Infix_To_Postfix(v2);

		unq(var);
		//for(auto x : var)	cout << x << " "; cout << endl;
		n = var.size();
		bool equivalent = BT(0,v1,v2);			

		printf("Case %d: %s\n", ++cs, (equivalent ? "Equivalent" : "Not Equivalent"));
	}

    //int end_s=clock();	
    //printf("\nTime :: %.2lf\n", (double)(end_s-start_s)/CLOCKS_PER_SEC);
	return 0;
}