#include <bits/stdc++.h>
using namespace std;
std::vector<int> graph[200020];
int arr[200020],pos[200020],n;
void build(int *arr)
{
    for(int i = 1;i<=n;i++)
    {
        int now = arr[i];
        int go = pos[now];
        graph[now].push_back(go);
    }

    for(int i = 1;i<=n;i++)
    {
        cout << "i = " << i << " : ";
        for(auto it : graph[i])
            cout << it << " ";
        cout << endl;
    }

}
int level[200020];
bool visit[200020];
bool bfs(int ss,int des)
{
    queue<int> process;
    process.push(ss);
    while(!process.empty())
    {
        
        int now = process.front();
        process.pop();
        for(int i = 0;i<graph[now].size();i++)
        {
            int go = graph[now][i];
            level[go] = level[now]+1;
            if(!visit[go])
            {
                process.push(go);
                visit[go] = 1;
            }
        }
    }
    return 0;
}
int main(){

    #ifdef PARTHO
        freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
        freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
        int start_time = clock();
    #endif
       
        int q;

        cin >> q;
        while(q--)
        {
            
            memset(visit,0,sizeof visit);
            memset(level,0,sizeof level);
            
            cin >> n;

            for(int i = 1;i<= n;i++) 
                {
                    scanf("%d",&arr[i]);
                    pos[arr[i]] = i;
                    graph[i].clear();
                }
                build(arr);
                cout << "POS  = ";
                for(int i = 1;i<=n;i++)
                    cout << pos[i] << " ";
                cout << endl;

                for(int i  = 0;i<n;i++)
                {
                    if(!visit[arr[i]])
                        bfs(arr[i],arr[i]);
                }
                for(int i = 0;i<n;i++)
                    cout << level[arr[i]] << " ";
                cout << endl;
        }



    #ifdef PARTHO
        int end_time = clock();
        printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif
    return 0;
}
