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


        int t = 1,ox,oy;
        while(t)
        {
            cin >> t;
            if(!t)
                return 0;
            cin >> ox >> oy;

            while(t--)
            {
                int x,y;

                cin >> x >> y;
                if(ox==x || oy == y)
                {
                    cout << "divisa" << endl;
                    continue;
                }
                // x = ox;
                // y = oy;
                if(x>ox&&y>oy)
                    cout << "NE" << endl;
                else if(x>ox&&y<oy)
                    cout << "SE" << endl;
                else if(ox>x && y<oy)
                    cout << "SO" << endl;
                else if(ox>x && oy<y)
                    cout << "NO" << endl;
                
                //Or solution to transfer the given to the origin.
                //  x = x - ox;
                //  y = y - oy;
                // if(x>0&&y>0)
                //     cout << "NE" << endl;
                // else if(x>0&&y<0)
                //     cout << "SE" << endl;
                // else if(0>x && y<0)
                //     cout << "SO" << endl;
                // else if(0>x && 0<y)
                //     cout << "NO" << endl;
            }
        }
       
    
    #ifdef PARTHO
        int end_time = clock();
        printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif

    return 0;
}
