#include<bits/stdc++.h>
using namespace std;
int main()
{
	int test;

	cin >> test;
	long long n,k;
	while(test--)
    {
         long long cnt = 0;
         long long value;
        cin >> n >> k;
        if(k>n)
            cout << n << endl;
        else
        {
             while(n)
        {
            value = (float)n/k;
            //cout << " value " <<  value << endl;
            value = k*value;
            cnt += n-value;
           // cout << cnt << endl;
            n=value;
            if(n==0)
                break;
            if(n%k == 0)
            {
                 cnt++;
                n = n/k;
            }
        }
         cout << cnt << endl;
        cnt = 0;

        }




    }



	return 0;
}
