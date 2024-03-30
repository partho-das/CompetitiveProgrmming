//https://algo.codemarshal.org/problems/55184554742a2fff09a42faa
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
        
    
    long long cx,cy,r,sx,sy;
    int t;
    cin >> t;
    for(int i = 1 ; i <= t; ++i)
    {
        cin >> cx >> cy >> r >> sx >> sy;
        printf("Case %d: ",i);
        if( (cx-sx)*(cx-sx)+(cy-sy)*(cy-sy) > r*r)
            cout << "no" << endl;
        else cout << "yes" << endl;

    }
    
    #ifdef PARTHO
        int end_time = clock();
        printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif

    return 0;
}
