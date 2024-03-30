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

namespace Geo{
	inline double Deg_to_Rad(double deg){ return deg*(PI/180.0);}
	inline double Rad_to_Deg(double rad){ return rad*(180.0/PI);}
	struct point {
		ll x,y;
		point(){ x = y = 0;}
		point(ll _x, ll _y){ x = _x, y = _y;}

		inline bool operator == (const point &a) const { return x == a.x && y == a.y;}
		inline bool operator <  (const point &a) const { return x == a.x ? y < a.y : x < a.x;}
		inline bool operator >  (const point &a) const { return x == a.x ? y > a.y : x > a.x;}
		inline long long dist(const point &a){ return SQR(x-a.x) + SQR(y-a.y);}
	};
	struct point_d {
		long double x,y;
		point_d(){x = y = 0.0;}
		point_d(long double _x, long double _y){ x = _x, y = _y;}

		inline bool operator == (const point_d &a) const { return fabs(x - a.x) < eps && fabs(y - a.y) < eps;}
		inline bool operator <  (const point_d &a) const { return fabs(x - a.x) < eps ? (y + eps) < a.y : (x + eps) < a.x;}
		inline bool operator >  (const point_d &a) const { return fabs(x - a.x) < eps ? (y - eps) > a.y : (x - eps) > a.x;}
		inline long double dist(const point_d &a){ return hypot(x - a.x, y - a.y);}
		inline point_d rotate(double deg){ long double rad = Deg_to_Rad(deg); return point_d(x*cos(rad) - y*sin(rad), x*sin(rad) + y*cos(rad));}
	};
	point _start;
	inline point operator + (point a, point b) { return point(a.x+b.x,a.y+b.y);}
	inline point operator - (point a, point b) { return point(a.x-b.x,a.y-b.y);}
	inline point_d operator + (point_d a, point_d b) { return point_d(a.x+b.x,a.y+b.y);}
	inline point_d operator - (point_d a, point_d b) { return point_d(a.x-b.x,a.y-b.y);}
	inline bool ClockSort(const point &a, const point &b){ return (_start.x-a.x)*(_start.y-b.y) < (_start.x-b.x)*(_start.y-a.y);}
	inline int Turn(point s, point e, point m){ ll res = 0; res += e.x*m.y - e.y*m.x - s.x*m.y + s.y*m.x + s.x*e.y - s.y*e.x; return res ? (res > 0 ? +1 : -1 ): 0;}
	inline bool onSegment(point s, point e, point m){return Turn(s,e,m) ? 0 : min(s.x,e.x) <= m.x && m.x <= max(s.x,e.x) && min(s.y,e.y) <= m.y && m.y <= max(s.y,e.y);}
	inline bool intersect(point a, point b, point c, point d){
		int t1 = Turn(a,b,c), t2 = Turn(a,b,d);
		int t3 = Turn(c,d,a), t4 = Turn(c,d,b);	
		if(((t1 < 0 && t2 > 0) || (t1 > 0 && t2 < 0)) && ((t3 < 0 && t4 > 0) || (t3 > 0 && t4 < 0))) return 1;
		if((!t1 && onSegment(a,b,c)) || (!t2 && onSegment(a,b,d)) || (!t3 && onSegment(c,d,a)) || (!t4 && onSegment(c,d,b))) return 1;
		return 0;
	}
	inline bool pointInsideConvexHall(vector<point> &v, point p, bool strictlyIside = 0){ // points are sorted in anticlockwise order
        int lo = 1,hi = v.size()-1, mid;
        while(lo < hi){ 
            if((lo+1) == hi) break;
            mid = (lo+hi) >> 1; 
            if(Turn(v[0],v[mid],p) >= 0) lo = mid;
            else                         hi = mid;
        }
        return (Turn(v[0], v[lo], p)>=0) && (Turn(v[lo], v[hi], p) >= strictlyIside) && (Turn(v[hi], v[0], p)>=0);
    }
    inline point_d lineLineIntersection(point_d A, point_d B, point_d C, point_d D) { 
		long double a1 = B.y - A.y; 
		long double b1 = A.x - B.x; 
		long double c1 = a1*(A.x) + b1*(A.y);  // Line AB represented as a1x + b1y = c1 

		long double a2 = D.y - C.y; 
		long double b2 = C.x - D.x; 
		long double c2 = a2*(C.x)+ b2*(C.y);   // Line CD represented as a2x + b2y = c2 

		long double determinant = a1*b2 - a2*b1; 

		if (determinant == 0) return point_d(FLT_MAX, FLT_MAX);  //The lines are parallel.
		else{ 
			long double x = (b2*c1 - b1*c2)/determinant; 
			long double y = (a1*c2 - a2*c1)/determinant; 
			return point_d(x, y); 
		} 
	} 
	point_d _startld;
	inline bool cmpld(const point_d &a, const point_d &b){	return (_startld.x-a.x)*(_startld.y-b.y) <= (_startld.x-b.x)*(_startld.y-a.y);}
	inline long double polygonArea(vector<point_d> p){
			_startld = p[0];
			sort(p.begin(),p.end(),cmpld);
			p.push_back(p[0]);
			int n = p.size()-1;
			long double sum = 0;
			FOR(i,0,n) sum += p[i].x*p[i+1].y - p[i].y*p[i+1].x;
			return fabs(sum*.5);
	}
	template <class T> inline T get4th(T a, T b, T c){ // ABCD and find D
		return T(a.x+c.x-b.x,a.y+c.y-b.y);
	}
	inline point_d CenterCircumcircle3(point_d a, point_d b, point_d c){ // point a,b,c is on the circumference of the circle 
		ld k1 = a.x*a.x - b.x*b.x + a.y*a.y - b.y*b.y;
		ld k2 = a.x*a.x - c.x*c.x + a.y*a.y - c.y*c.y;
		ld k3 = a.x*c.y + b.x*a.y + c.x*b.y - a.x*b.y - b.x*c.y - c.x*a.y;
		ld x = (k2*(a.y-b.y) - k1*(a.y-c.y))/(2*k3);
		ld y = (k1*(a.x-c.x) - k2*(a.x-b.x))/(2*k3);
		return point_d(x,y);
	}
}
inline pair<ld,ld> findRoot(ld a1, ld b1, ld c1, ld a2, ld b2, ld c2){
	ld determinant = a1*b2 - a2*b1; 
	if (determinant == 0) return MP(FLT_MAX, FLT_MAX);  //The lines are parallel.
	else{ 
		ld x = (b2*c1 - b1*c2)/determinant; 
		ld y = (a1*c2 - a2*c1)/determinant; 
		return MP(x, y); 
	}
}
using namespace Geo;
void out(point a){	out2(a.x,a.y);}
class EquationToRoot {
public:
	struct equation{
		long double a,b,c,d; // ax + by + cz = d
		inline void set(long double _a, long double _b, long double _c, long double _d){
			a = _a, b = _b, c = _c, d = _d;
		}
	}eq[3];
	double x,y,z;
	inline void cal_Root3D(){
		long double a1 = eq[0].a, b1 = eq[0].b, c1 = eq[0].c, d1 = eq[0].d;
		long double a2 = eq[1].a, b2 = eq[1].b, c2 = eq[1].c, d2 = eq[1].d;
		long double a3 = eq[2].a, b3 = eq[2].b, c3 = eq[2].c, d3 = eq[2].d;

		long double det, det1, det2, det3;

		det = a1*(b2*c3-b3*c2) - b1*(a2*c3-a3*c2) + c1*(a2*b3-a3*b2);
		det1= d1*(b2*c3-b3*c2) - b1*(d2*c3-d3*c2) + c1*(d2*b3-d3*b2);
		det2= a1*(d2*c3-d3*c2) - d1*(a2*c3-a3*c2) + c1*(a2*d3-a3*d2);
		det3= a1*(b2*d3-b3*d2) - b1*(a2*d3-a3*d2) + d1*(a2*b3-a3*b2);

		x = det1/det;
		y = det2/det;
		z = det3/det;
	}
};

int main()
{
	//fastIO;
    fileIO();  int start_s=clock();

    point_d a(-6,5), b(-3,-4), c(2,1);

    point_d center = CenterCircumcircle3(a,b,c);	out3(center.x,center.y,center.dist(a));

    //int end_s=clock();	
    //printf("\nTime :: %.2lf\n", (double)(end_s-start_s)/CLOCKS_PER_SEC);
	return 0;
}