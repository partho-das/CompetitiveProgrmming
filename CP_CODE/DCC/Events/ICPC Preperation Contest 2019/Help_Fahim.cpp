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

        int h1 = 1,m1 = 1,h2 = 1,m2 = 1,agent = 24*60;


        while(1)
        {
            cin >> h1 >> m1 >> h2 >> m2;
            if(h1==0 && m1==0 && h2==0 && m2 == 0)
                break;
            int weakup = h2*60+m2,sleep = h1*60+m1;

            int def;
            if(weakup<sleep)
                {
                    def = weakup+agent-sleep;
                }
                else
                    def = weakup-sleep;

                cout << def << endl;
        }

   
       
    
  #ifdef PARTHO
        int end_time = clock();
        printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif

    return 0;
}
