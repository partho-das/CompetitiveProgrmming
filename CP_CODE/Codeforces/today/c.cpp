#include <bits/stdc++.h>
using namespace std;
 int take[100];

int n = 6;

int bt(int pos)
{
    if(pos>=n)
    {
        for(int i = 0;i<n;i++)
        {
            if(i==n/2)
                cout << endl;
            cout <<take[i];
        }
        cout << endl << endl;
        return 0;
    }

    take[pos] = 0;
    bt(pos+1);
    take[pos] = 1;
    bt(pos+1);


}

int main(){

    #ifdef PARTHO
        freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
        freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
        int start_time = clock();
    #endif
       
        
        bt(0);

    #ifdef PARTHO
        int end_time = clock();
        printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif
    return 0;
}
