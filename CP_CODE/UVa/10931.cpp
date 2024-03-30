#include<bits/stdc++.h>

using namespace std;
long long n;
int main()
{
     

    while(1)
    {
        cin >> n;
        if(n==0)
            break;
        int dig = log2(n)+1,cnt = 0;
        printf("The parity of ");
        for(int i = dig-1;i>=0;i--)
        {


            bool ck = n&1<<i;
            if(ck)
                cnt++;
                 cout << ck;
        }
       printf(" is %d (mod 2).\n",cnt );
    }

 
    

    
    return 0;
}