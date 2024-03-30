#include<bits/stdc++.h>
using namespace std;

#define ll long long

const ll maxn = 1e3+7, MOD = 1e9+7;

int expo(int b,int p) {
    if(p == 0)
        return 1;
    else {
        if(p&1)
            return (b*expo(b,p-1))%MOD;
        else {
           int temp = expo(b,p/2)%MOD;
            return (temp*temp)%MOD;
        }
    }
}

int okr[maxn];
int okc[maxn];
bool arr[maxn][maxn];

int main()
{
    #ifdef PARTHO
        freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
        freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
       int start_time = clock();
    #endif
        
      int n,m;

       cin >> n >> m;

       for(int i = 0;i<n;i++)
       {
           int value;
            cin >> value;
            for(int j = 0;j<value;j++)
            {
                arr[i][j] = 1;
            }
       }

       for(int i = 0;i<m;i++)
       {
           int value;
            cin >> value;
            for(int j = 0;j<value;j++)
            {
                arr[j][i] = 1;
            }
       }
      int cnt = 0;

       for(int i = 0;i<n;i++)
       {
            for(int j = 0;j<m;j++)
            {
               cout << arr[i][j] << " ";
                if(arr[i][j] == 0)
                {

                    //cout << okr[i] << " "<< okc[j] << endl;
                    if(okr[i] && okc[j])
                    {

                        cnt++;
                    }
                    okr[i] = 1;
                    okc[j] = 1;
                }

            }
           cout << endl;
       }

      // cout << cnt << endl;

       int contain = expo(2,cnt)%MOD;
        if(!cnt) contain = 0;
       cout << contain << endl;
        
        // for(int i = 1;i<1000000;i++)
        // {
        //     contain = expo(2,i) ;
        //     cout << contain%MOD - 1 << endl;

        // }

    
    #ifdef PARTHO
       int end_time = clock();
        printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif

    return 0;
}
