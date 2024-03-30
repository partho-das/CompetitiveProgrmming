#include<bits/stdc++.h>
using namespace std;

#define ll long long
int arr[100][5];
int taken[12];
int k = 0;
int n = 1,mx = -1;
long long cnt  = 0;
void comb(int pos,int indx)
{
    //cout << k << endl;
    if(k>=9)
    {
           mx = max(pos,mx);
           return;
    }
    if(indx>=n)
        return;
    //cout << k << endl;
    
        int a =  arr[indx][0],b = arr[indx][1],c = arr[indx][2];
        
        if(!taken[a] && !taken[b] && !taken[c])
        { cnt++;
           //cout << a << " " << b << " " << c << endl;
            taken[a] = taken[b] = taken[c] = 1;
            k+=3;
            comb(arr[indx][3]+pos,indx+1);
            taken[a] = taken[b] = taken[c] = 0;
            k-=3;
        }
        comb(pos,indx+1);
}

int main()
{
    #ifdef PARTHO
        freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
        freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
        int start_time = clock();
    #endif
        int Case = 1;

        while(1)
        {

            cin >> n;
            if(n==0)
                break;
           mx = -1;
            int a,b,c,s;
            for(int i = 0;i<n;i++)
            {
                cin >> a >> b >> c >> s;
                arr[i][0] = a;
                arr[i][1] = b;
                arr[i][2] = c;
                arr[i][3] = s;
            }
            comb(0,0);
            printf("Case %d: ",Case++);
            cout << mx << endl;
            
        }
        cout << cnt << endl;
        
    


    
    #ifdef PARTHO
        int end_time = clock();
        printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif

    return 0;
}
