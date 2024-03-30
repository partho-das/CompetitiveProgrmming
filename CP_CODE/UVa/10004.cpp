#include<bits/stdc++.h>
using namespace std;

#define ll long long

std::vector <int> eage[220];
int input(int e,int n)
{
	int u,v;
	for(int i = 0;i<e;i++)
	{
		cin >> u >> v;

		eage[u].push_back(v);
		eage[v].push_back(u);
	}
	// for(int i = 0;i<n;i++)
	// {
	// 	cout << i <<" : ";
	// 	for(auto it : eage[i])
	// 	cout <<  it << " ";
	// 	cout << endl;
	// }

	return u;
}

int visit[300];
bool bfs(int source)
{
	queue<int> process;
	
	process.push(source);
	visit[source] = 1;
	while(!process.empty())
	{
		int now = process.front();
		process.pop();
		for(int i = 0;i<eage[now].size();i++)
		{
			int x = eage[now][i];
			if(visit[now] == 1)
			{
				if(visit[x] == 0)
				{
					visit[x] = 2;
					process.push(x);
				}
				else if(visit[x] == 1)
					return 0;
			}
			else if(visit[now] == 2)
			{
				if(visit[x] == 0)
				{
					visit[x] = 1;
					process.push(x);
				}
				else if(visit[x] == 2)
					return 0;
			}
		}
	}

	return 1;

}



int main()
{
	#ifdef PARTHO
		freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
    	freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
    	int start_time = clock();
    #endif

   
   	int n,l;

   	while(1)
   	{
   		cin >> n;
   		if(n==0)
   			break;
	   	for(int i = 0;i<n;i++)
			eage[i].clear();
   		memset(visit,0,sizeof visit);
   		int e;
   		cin >> e;
   		int  source = input(e,n);
   		if(bfs(source))
   		puts("BICOLORABLE.");
   		else
   			puts("NOT BICOLORABLE.");
   		


   	}
    	
    	
	#ifdef PARTHO
		int end_time = clock();
		printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif

	return 0;
}
