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
#define TEST(test)  for(int x = 1; x <= test; x++)
//____________________________________________________________________________________________________________________________________

ll calculate(int c,int s)
{
	double di = s/(double)c;

	if(di<=0) return s;
	ll sum = 0;
	while(c)
	{
		int sec = s/c;
		sum+= (sec*sec);
		s-=sec;
		c--;
	}

	return sum;
}
int main(){

   #ifdef PARTHO
       freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
       freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
       int start_time = clock();
   #endif


       int n;

       cin >> n;
       while(n--)
       {
       		int c,s;
       		cin >> c >> s;
       		ll sum  = calculate(c,s);

       		cout << sum << endl;

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
