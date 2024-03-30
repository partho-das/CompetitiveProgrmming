#include<bits/stdc++.h>
using namespace std;
struct point
{
    int x;
    int y;
};
const int MAXN = 10e3;
char graph[MAXN][MAXN];
int n;
bool visited[MAXN][MAXN];
int dirx[] = {1,0,-1,0};
int diry[] = {0,1,0,-1};

//queue<point> Q;
queue <point> Q;
point nxt,sorce,dest;
bool valid(point p)
{
    if(  0<=p.x && n>p.x && 0<=p.y && n>p.y)
        return true;
    else
        return false;
}
bool bfs()
{
    Q.push(sorce);
    visited[sorce.x][sorce.y] = 1;
    while(!Q.empty())
    {
        point current = Q.front(); Q.pop();
        if(current.x== dest.x && current.y == dest.y)
            return true;
        for(int i = 0;i<4;i++)
        {
            nxt.x = current.x+dirx[i];
            nxt.y = current.y+diry[i];
            if(valid(nxt) && !(visited[nxt.x][nxt.y]) && graph[nxt.x][nxt.y] == 'o')
            {
                visited[nxt.x][nxt.y] = 1;
                Q.push(nxt);
            }
        }
    }
    return false;


}

int main()
{


   scanf("%d%*c",&n);
    for(int j = 0;j<n;j++)
        scanf("%s",graph[j]);
    scanf("%d%d",&sorce.x,&sorce.y);
    scanf("%d%d",&dest.x,&dest.y);

    sorce.x--,sorce.y--,dest.x--,dest.y--;

   puts(bfs() ?  "Yes" : "Shuvo will remain single this year too :(");

    return 0;
}
