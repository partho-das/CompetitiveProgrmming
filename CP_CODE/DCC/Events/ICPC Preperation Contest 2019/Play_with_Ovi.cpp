#include<bits/stdc++.h>
using namespace std;

#define ll long long




int main()
{
    #ifdef PARTHO
        freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
        freopen("C:\\Users\\parth\\Desktop\\coutput.txt","w",stdout);
        int start_time = clock();
    #endif

   
        unsigned long long n,value;


        while(cin >> n)
        {
            n = (n+1)/2;
            value = n*n;
            value = value<<1;
            unsigned long long sum = value-1;
            sum+= (value-3);
            sum+= (value-5);
            if(n==1)
                sum = 1;
            cout << sum << endl;
        }



    
  #ifdef PARTHO
        int end_time = clock();
        printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif

    return 0;
}
