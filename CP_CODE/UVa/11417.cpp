#include<bits/stdc++.h>
using namespace std;

#define ll long long


int GCD(int a, int b)
{
    if(a<=0)
        return b;
    return GCD(b%a,a);
}


int main()
{
    #ifdef PARTHO
        freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
        freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
        int start_time = clock();
    #endif


    int n = 5;
   while(n)
   {
        cin >> n;
        if(n==0)
        return 0;    
        long long g = 0;
        for(int i = 1;i<n;i++)
        {
            for(int j = i+1 ;j<=n ;j++)
            {
                g+=GCD(i,j);
            }
        }
        cout << g << endl;
   }

     
       
    
    // #ifdef PARTHO
    //     int end_time = clock();
    //     printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    // #endif

    return 0;
}
