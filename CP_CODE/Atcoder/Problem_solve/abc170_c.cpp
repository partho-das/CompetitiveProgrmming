#include <bits/stdc++.h>
using namespace std;


#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

const int inf = 1e9;

int is_find[200];
int main()
{
FastIO
int value, x, n;

cin >> x >> n;
for(int i = 0; i < n; i++) 
{
	cin >> value;
	is_find[ value ] = 1;
}

int ans = -1, mn = inf;
for(int i = 0; i <= 101; i++)
{
	if(is_find[i] == 0){

		if(mn > abs(i - x)){
			mn = abs(i - x);
			ans = i;
		}
	}
}

cout << ans << endl;


    return 0;
}
///Before submit=>
///    *check for integer overflow,array bounds
///    *check for n=1
