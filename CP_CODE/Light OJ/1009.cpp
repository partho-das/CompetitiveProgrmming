#include<bits/stdc++.h>

using namespace std;

std::vector<int> v[20200];
int mx= 0;
void input(int n)
{

	// 	for(int i = 1;i<=mx;i++)
	// {
	// 	for(int j = 0;j<v[i].size(); j++)
	// 	{
	// 		cout << v[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }


	for(int i = 0;i<n;i++)
	{
		int u,va;
		scanf("%d%d",&u,&va);
		v[u].push_back(va);
		v[va].push_back(u);
		u = max(u,va);
		mx = max(u,mx);
	

	}

	// for(int i = 1;i<=mx;i++)
	// {
	// 	for(int j = 0;j<v[i].size(); j++)
	// 	{
	// 		cout << v[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
}

int visit[20200];

int bfs(int s)
{
	int vc = 0,lc = 0;

	queue <int> process;

	process.push(s);
	visit[s] = 2;
	lc++;

	while(!process.empty())
	{
		int value = process.front();
		process.pop();
		//cout << value << endl;

		for(int i = 0;i<v[value].size(); i++)
		{
			int now = v[value][i];
			
				//cout << now<<endl;
			if( !visit[now] )
			{
				//cout << visit[now] ;
				if(visit[value] == 2)
				{
					visit[now] = 3;
					vc++;
				}
				else 
				{
					visit[now] = 2;
					lc++;
				}

				process.push(now);

				//cout << visit[now]<< " " << lc << " " << vc<< endl;
			}
		}
	}
	return max(vc,lc);


}

int main()
{
	

    int test;

    scanf("%d",&test);
    for(int t = 1 ; t<=test;t++)
    {
    	
	    int n;

	    scanf("%d",&n);
	    input(n);
	    memset(visit, 0, sizeof visit);
	    int value = 0;
	    for(int i = 1;i<=mx;i++)
		{
			if(!visit[i] && v[i].size())
			{
				value+=bfs(i);
				
			}
		}
		printf("Case %d: %d\n",t,value);

			for(int i  = 0;i<=mx;i++)
    		{
         		v[i].erase(v[i].begin(),v[i].begin()+v[i].size());
    		}

    }
  

    return 0;

}