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

class temperature
{
	float celcius, fahrenheit;

public:

	void input()
	{

		printf("Enter the temperature in fahrenheit: ");
		sc("%f", &fahrenheit);
	}

	float convert_fahrenheit_to_celcius()
	{
		return (fahrenheit - 32) * (5 / 9.0);
	}

	void output()
	{
		celcius = convert_fahrenheit_to_celcius();
		printf("%f Fahrenhit is equal to %f Celsius\n", fahrenheit, celcius);
	}

};

void fahrenheit_to_celcius()
{
	temperature t1;
	t1.input();
	t1.output();

	return;
}


class circle
{
	float radius, area, circumference;

public:

	void input()
	{
		printf("Enter the radius of that circle: ");
		sc("%f", &radius);
		return;
	}

	float claculate_area()
	{
		return  PI * radius * radius;
	}
	float claculate_circumference()
	{
		return  2 * PI * radius;
	}

	void output()
	{
		area = claculate_area();
		circumference = claculate_circumference();
		printf("Area = %f\n", area);
		printf("circumference = %f\n", circumference);
		return;
	}
};

void calculate_area_and_circumference()
{
	circle c1;

	c1.input();

	c1.output();
}


class swap_two
{
    int a, b;

public:
    void input()
    {
        printf("Enter two number : ");
        sc2(a, b);
    }
    void swap_function()
    {
        int temp = a;
        a = b;
        b = temp;
        return;
    }

    void output()
    {
        swap_function();
        printf("a = %d b = %d\n", a, b);
        return;
    }
};


void swap_two_number()
{
    swap_two s1;

    s1.input();
    s1.output();


}
int main()
{
#ifdef PARTHO
    freopen("/home/partho/Desktop/IO/input.txt","r",stdin);
    freopen("/home/partho/Desktop/IO/output.txt","w",stdout);
    int start_time = clock();
#endif
//FastIO;
//fahrenheit_to_celcius
fahrenheit_to_celcius();

//calculate_area_and_circumference
calculate_area_and_circumference();


//swap two number
swap_two_number();


#ifdef PARTHO
    int end_time = clock();
    printf("Time = %.4f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
#endif

    return 0;
}
///Before submit=>
///    *check for integer overflow,array bounds
///    *check for n=1
