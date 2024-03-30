#include<bits/stdc++.h>
using namespace std;



std::vector<int> v[10200];
void input(int n,int m)
{
    for(int i  = 0;i<=n;i++)
    {
         v[i].erase(v[i].begin(),v[i].begin()+v[i].size());
    }
    for(int i = 0;i<m;i++)
    {
        int u,value;
        scanf("%d%d",&u,&value);
        v[u].push_back(value);
        v[value].push_back(u);
    }


}

int level[100000];
bool visit[100000];
queue<int> process;
void bfs(int s)
{
    memset(visit,0,sizeof(visit));
    memset(level,0,sizeof(level));
    while(!process.empty()) 
        process.pop();
    process.push(s);
    visit[s] = 1;
    level[s] = 0;
    

    while(!process.empty())
    {
        int value = process.front();
       //cout << value <<endl;
        process.pop();
        for(int i = 0;i<v[value].size();i++)
        {
           
            if( !visit[v[value][i]])
            {
                process.push(v[value][i]);
                visit[v[value][i]] = 1;
                level[v[value][i]] = level[value]+1;
            }
           

        }
    }
 

}

int main()
{
 


    int q;

    cin >> q;
    while(q--)
    {
        int n,m;
        scanf("%d%d",&n,&m);

         input(n,m);
         int s;

         cin >> s;
         bfs(s);

        for(int i = 1;i<=n;i++)
        {

        if(i!=s)
        {
            if( visit[i] )
                cout << level[i]*6 << " ";
            else cout << "-1 ";
        }


        }
        cout << endl;
    }
   






    return 0;
}
