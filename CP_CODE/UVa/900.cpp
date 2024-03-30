#include<bits/stdc++.h>

using namespace std;
const long long MOD = 1e9+7;

int main()
{


    long long n,str = 1,sec= 2,arr[100],i = 1;

    while(1)
    {
        if(i==51)
            break;
       
        arr[i++] = str;// cout << arr[i-1] << endl;

       int value = str+sec;
       str = sec;
       sec = value;
       //cout << << endl;
    }


    while(1)
    {
        cin >> n;
        if(n==0)
            break;

        cout << arr[n] << endl;
    }

    


  

    return 0;
}