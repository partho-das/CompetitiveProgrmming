#include<bits/stdc++.h>
using namespace std;

#define ll long long
int n,rl,cnt = 0;


std::vector<int> graph[100020];
void input()
{
    int u,v;
    for(int i = 1;i<n;i++)
    {
        cin >> u >> v;
        graph[v].push_back(u);
        graph[u].push_back(v);
    }

    // for(int i = 1;i<n;i++)
    // {
    //     cout << i << ": ";
    //     for(int j = 0;j<graph[i].size();j++)
    //         cout << graph[i][j] <<" ";
    //         cout << endl; 
    // }
}

bool visit[100020];
int level[100020];

void bfs()
{
    queue<int> process;
    process.push(1);
    level[1] = 1;
    visit[1] = 1;

    while(!process.empty())
    {
        int par = process.front();
        process.pop();
        for(int i = 0;i<graph[par].size();i++)
        {
            int now = graph[par][i];
            if(!visit[now])
            {
                process.push(now);
                visit[now]= 1;
                level[now] = level[par]+1;
                if(level[now]==rl)
                {

                    cnt++;
                }
                else if(level[now]>rl)
                    return;
            }
        }
    }
}


int main()
{
    #ifdef PARTHO
        freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
        freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
        int start_time = clock();
    #endif

        
        cin >> n;
        input();
        cin >> rl;

        bfs();
        cout << cnt << endl;       
        
    #ifdef PARTHO
        int end_time = clock();
        printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif

    return 0;
}
