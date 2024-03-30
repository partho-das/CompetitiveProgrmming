#include<bits/stdc++.h>
using namespace std;

char str[200][200];
int n,m;
void input()
{
    for(int i = 0;i<n;i++)
    {
        cin>>str[i];
    }


}


int dirx[] = {0,0,-1,1,     -1,1,-1,1};
int diry[] = {-1,1,0,0,     1,-1,-1,1};
int level[200][200];


void fill(int sx,int sy)
{
    level[sx][sy] = 0;

    for(int i = 0;i<8;i++)
    {
        int x,y;
        x = sx+dirx[i];
        y = sy+diry[i];

        if(x>=0 && y>=0 && x<n && y<m)
            level[x][y]++;
    }

}



int main()
{
   
    int f = 1,ck = 0;
    while(1)
    {

          cin >> n >> m;
          if(n==0 && m==0)
            break;
        else {
            if(ck)
                puts("");
            ck = 1;
        }
        memset(level,0,sizeof level);
            input();

            for(int i = 0;i<n;i++)
            {
                for(int j = 0;j<m;j++)

                {
                    if(str[i][j]=='*')
                    {
                        fill(i,j);
                    }
                }
            }

            printf("Field #%d:\n",f++);
            for(int i = 0;i<n;i++)
            {
                for(int j = 0;j<m;j++)

                {
                    if(str[i][j]=='*')
                    {
                        cout<<str[i][j];
                    }
                    else
                    {
                        cout<< level[i][j];
                    }
                }
                cout << endl;
            }

    }


  
        
    return 0;
}