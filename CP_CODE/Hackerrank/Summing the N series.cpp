#include<bits/stdc++.h>

using namespace std;
const long long MOD = 1e9+7;

int main()
{


    int t;

    long long n;

    cin >> t;

    while(t--)
    {
        cin >> n;

        n = ((n%MOD)*(n%MOD))%MOD;

        cout << n << endl; 
    }


    


  

    return 0;
}