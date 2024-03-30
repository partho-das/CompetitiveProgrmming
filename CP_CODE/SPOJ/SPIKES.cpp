#include<bits/stdc++.h>
using namespace std;

const int dirx[] = {  0, 0, 1, -1 };
const int diry[] = { -1, 1, 0,  0 };

int n,m,GC,sx,sy;
char str[40][41];
void input(){       
    for(int i = 0;i<n;i++){
        scanf("%s", str[i]);
        for(int j = 0; j < m ; j++) 
            if(str[i][j] == 'x') sx = i, sy = j;
    }
}
bool visit[40][41];
bool valid(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < m && str[x][y] != '#';
}
bool BTDFS(int sx,int sy,int cost){
    if(str[sx][sy]=='@') return (cost << 1) <= GC;
    for(int i = 0;i<4;i++){
        int x = dirx[i]+sx, y = diry[i] + sy;
        if(valid(x,y) && !visit[x][y]){
            visit[x][y] = 1;
            if(BTDFS(x, y, cost + (str[x][y] == 's'))) return 1;
            visit[x][y] = 0;
        }
    } 
    return 0;
}
int main()
{   
    #ifdef PARTHO
        freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
        freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
        int start_time = clock();
    #endif

    scanf("%d%d%d", &n, &m, &GC);
    input(); 
    visit[sx][sy] = 1;
    puts( BTDFS(sx,sy,0) ? "SUCCESS" : "IMPOSSIBLE");
    
    #ifdef PARTHO
        int end_time = clock();
        printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif
    return 0;
}