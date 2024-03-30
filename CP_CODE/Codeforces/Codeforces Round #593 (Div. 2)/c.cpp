#include <bits/stdc++.h>
using namespace std;
 
int main(){

    #ifdef PARTHO
        freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
        freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
        int start_time = clock();
    #endif
        int n,arr[400][400];
        cin >> n;

        int sqr = n*n;
        int x = 1,ck = 0;
        for(int i = 1;i<=n;i++)
        {
            if(ck==0)
            {
                for(int j = 1;j<=n;j++)
                {
                    arr[i][j] = x++;
                }
                ck = 1;
            }
            else 
            {
                for(int j = n;j>=1;j--)
                {
                    arr[i][j] = x++;
                }
                ck = 0;
            }
        }


         for(int i = 1;i<=n;i++)
        {
            for(int j = 1;j<=n;j++)
                cout << arr[j][i] << " ";
           cout << endl;
        }

    #ifdef PARTHO
        int end_time = clock();
        printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif
    return 0;
}
