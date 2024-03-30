#include <bits/stdc++.h>
using namespace std;
 
int main(){

    #ifdef PARTHO
        freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
        freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
        int start_time = clock();
    #endif
       
        int test;

        cin >> test;


        while(test--)
        {
            long long n,m,odd = 0,even = 0,odd2 = 0,even2 = 0 ;

            cin >> n;
            int value;
            for(int i = 0;i<n;i++)
            {
                scanf("%d",&value);
                if(value&1)
                    odd++;
                else even++;
            }
        cin >> m;
       
            for(int i = 0;i<m;i++)
            {
                scanf("%d",&value);
                if(value&1)
                    odd2++;
                else even2++;
            }
            long long sum = odd2*odd + even2*even;

            cout << sum << endl;
        }



    #ifdef PARTHO
        int end_time = clock();
        printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif
    return 0;
}
