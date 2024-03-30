#include<bits/stdc++.h>

using namespace std;
int n,k;
int main()
{
     
    while(scanf("%d%d",&n,&k) !=EOF)
    {
        int cnt = n,mn = k;
        int va = n,now,ex;
        int re = 0;

        
        while(n>=k)
        {

            now = (n)/k;

            re = n%k;
            cnt +=now;
            now+=re;      

            n = now; 
            // cout <<cnt <<" "<< now << endl;
           
        }
        cout << cnt << endl;
    }
 
    

    
    return 0;
}