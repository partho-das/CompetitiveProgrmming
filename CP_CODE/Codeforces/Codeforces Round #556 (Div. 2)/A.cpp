#include<bits/stdc++.h>
using namespace std;

int n;
char str[100][100];

void input()
{
    for(int i = 0;i<n;i++)
    {
        cin >> str[i];
    }
}

int visit[100][100];

int dirx[] = {0,0,+1,-1};
int diry[] = {-1,+1,0,0};
void bfs(int sx,int sy)
{


        int value = 4;

        for(int i = 0;i<4;i++)
        {
            int x,y;

            x = sx+dirx[i];
            y = sy+diry[i];

            if(x>=0 && y >= 0 && y<n && x<n && str[x][y]=='.' && visit[x][y] == 0)
            {
                value--;
            }



        }
        if(!value)
            {
                visit[sx][sy] = 1;
                for(int i = 0;i<4;i++)
                {
                    int x,y;
                        x = sx+dirx[i];
                        y = sy+diry[i];
                        visit[x][y] = 1;
                }

            }


}
int main()
{

    cin >> n;
    input();
    memset(visit,0,sizeof visit);


    for(int i = 0;i<n;i++)
    {

        for(int j = 0;j<n;j++)
        {

            if(!visit[i][j] && str[i][j]=='.')
            {
               // cout << i << j;
                bfs(i,j);
            }


        }
    }
    int value = n*n;
    for(int i = 0;i<n;i++)
    {

        for(int j = 0;j<n;j++)
        {

            if(str[i][j] == '#')
                value--;
            else
            {
                if(visit[i][j] == 1)
                    value--;
            }
            //cout << visit[i][j];

        }
       // cout << endl;
    }
    if(!value)
        printf("YES\n");
    else printf("NO\n");




	return 0;
}
