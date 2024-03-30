#include<bits/stdc++.h>
using namespace std;

char str[50][50];
int n,w;
void input() {
    for (int i = 0; i < n; ++i) {
        for(int j = 0; j<w; j++)
            str[i][j] = getchar();
        getchar();
    }
    // for (int i = 0; i < n; ++i) {
    //     for(int j = 0; j<w; j++)
    //         cout << str[i][j];
    //     puts("");
    // }
}




int dirx[] = {0,0,+1,-1};
int diry[] = {+1,-1,0,0};
int visit[100][100];

int bfs(int sx,int sy) {
    int cnt = 0;


    queue<pair<int, int>> process;

    memset(visit,0,sizeof visit);
    process.push(make_pair(sx,sy));
    while(!process.empty()) {
        pair <int, int >now ;
        now = process.front();
        process.pop();
        for(int i = 0; i<4; i++) {
            int x = now.first+dirx[i], y = now.second+diry[i];
            if(x>=0 && x<n && y>=0 && y<w && !visit[x][y] && str[x][y]=='.') {
                visit[x][y] = 1;
                process.push(make_pair(x,y));
                cnt++;
            }

        }

    }

    return cnt;

}



int main() {
  

    int q;

    cin >> q;
    for(int k = 1;k<=q;k++)
    {
        cin >> w >> n;
        getchar();

        input();

        for (int i = 0; i < n; ++i) {
            for(int j = 0; j<w; j++)
            {

                if(str[i][j]=='@')
                {
                 int value = bfs(i,j);
                 printf("Case %d: ",k);
                 cout << value+1 << endl;
                }
            }
        }




    }




    return 0;
}