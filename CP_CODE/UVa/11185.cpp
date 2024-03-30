#include<bits/stdc++.h>
using namespace std;

#define ll long long




int main()
{
    #ifdef PARTHO
        freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
        freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
        int start_time = clock();
    #endif

        int n = 1;
        int arr[1000];
        while(1)
        {
            int x = 0;
            cin >> n;
            if(n <= -1)
                return 0;
            if(n==0)
                cout << 0;
            while(n)
            {
                arr[x++] = n%3;
                n/=3;     
            }

            for(int i = x-1;i>= 0;i--)
                cout << arr[i];
                cout << endl;

        }


        
       
    
    #ifdef PARTHO
        int end_time = clock();
        printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif

    return 0;
}
