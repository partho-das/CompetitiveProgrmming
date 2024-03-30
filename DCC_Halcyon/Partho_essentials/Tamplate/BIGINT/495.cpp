
#include<bits/stdc++.h>
using namespace std;

string bigintAdd(string x, string y){
    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());

    while(x.size() < y.size()) x.push_back('0');
	while(x.size() > y.size()) y.push_back('0');
    
    x.push_back('0');
    y.push_back('0');

    string sum;
    int carry = 0;

    for(int i = 0; i < x.size(); i++){
        carry += x[i]+y[i]-2*'0';
        sum.push_back(carry%10 + '0');
        carry /= 10;
    }
    while(carry) sum.push_back(carry%10 + '0'), carry /= 10;
    while(sum.size() > 1 && sum.back() == '0') sum.pop_back();
    reverse(sum.begin(), sum.end());
    return sum;
}

bool vis[5005];
string fib[5005];
string Fib(int n){
    if(n <= 1) return string(1,'0'+n);
    if(vis[n]) return fib[n];
    vis[n] = 1;
    return fib[n] = bigintAdd(Fib(n-1), Fib(n-2));
}

int main()
{
	#ifdef PARTHO
		freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
    	freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
    	int start_time = clock();
    #endif

   	
   int n;

  

   while(scanf("%d",&n) !=EOF)
   {
        printf("The Fibonacci number for %d is ",n);
        cout << Fib(n) << endl;

   }

	#ifdef PARTHO
		int end_time = clock();
		printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif

	return 0;
}
