#include<bits/stdc++.h>
using namespace std;

#define ll long long


int dirx[] = {-1,-1, 1,1, 0,0,-1,1};
int diry[] = {-1, 1,-1,1 ,1,-1,0,0};

int n,m;
bool valied(int i,int j)
{
    return (i < n  && i >= 0 && j < m && j >= 0);
}

int main()
{
    #ifdef PARTHO
        freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
        freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
        int start_time = clock();
    #endif

      
       char fild[300][300];
       int arr[300][300],Case = 0;


       while(1)
       {
        memset(arr,0,sizeof arr);
        cin >> n >> m;
        if(n==0 && m==0)
            break;
        if(Case)
            printf("\n");
        printf("Field #%d:\n",++Case );
        for(int i = 0;i<n;i++)
        {
            cin >> fild[i];
        }
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(fild[i][j] == '*')
                {

                    for(int k = 0;k<8;k++)
                    {    
                        int x = dirx[k]+i,y = diry[k]+j;
                        if(valied(x,y))
                        {
                            //cout << "hi";
                            arr[x][y]++;
                        }
                    }
                }
            }
        }


        for(int i = 0;i<n;i++)
        {   
            for(int j = 0;j<m;j++)
            {   if(fild[i][j] == '.')
                cout << arr[i][j];
                else cout << fild[i][j];
            }
            cout << endl;
        }

       }
        
    #ifdef PARTHO
        int end_time = clock();
        printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif

    return 0;
}
