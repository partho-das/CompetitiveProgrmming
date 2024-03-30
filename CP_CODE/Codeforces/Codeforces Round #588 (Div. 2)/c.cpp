#include<bits/stdc++.h>
using namespace std;

#define ll long long
int visit[10000];
std::vector<int> graph[1000];
int dis[1000];
int given[10];
pair< int ,int > fre[10];
int input(int n,int e)
{
    for(int i = 0;i<e;i++)
    {
        int x,y;
        cin >> x >> y;
        fre[x].first++;
        fre[x].second = x;
        fre[y].first++;
        fre[y].second = y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    for(int i = 1;i<=n;i++)
    {
        cout << i << " : ";
        for(auto it : graph[i])
        {
            cout << it << " "; 
        }
        cout << endl;
    }

    return 0;
}
int first = 1,second = 1;
int left = 21;
int bfs(int s)
{
    

    queue<int> q;
    
    q.push(s);
    given[s] = 1;
    visit[s] = 1;
    left--;
    while(!q.empty())
    {
        int now;

        now = q.front();
        q.pop();
      

        for(int i = 0;i<graph[now].size();i++)
        {
            int ex = graph[now][i];
            if(!visit[ex])
            {
                if(!given[ex] && given[ex] == second) given[ex] = second++;
                {
                    
                }
                visit[ex] = 1;
                q.push(ex);
                dis[ex] = dis[now]+6;
            }
            
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

        int n,e;
        cin >> n >>e;
        input(n,e);
        sort(fre+1,fre+n+1);
        for(int i = 1;i<=n;i++)
            cout << fre[i].first << " "<< fre[i].second << endl;
        bfs(fre[n].second);


  #ifdef PARTHO
        int end_time = clock();
        printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif

    return 0;
}
