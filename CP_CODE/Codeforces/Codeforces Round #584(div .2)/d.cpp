#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int maxn = 2e5+7;


std::vector<int> node[200007];
queue<int> process;
int cnt = 0;
void input(int n,int k)
{
	int u,v;

	for(int  i = 0;i<k;i++)
	{
		cin >> u >> v;
		node[u].push_back(v);
		node[v].push_back(u);
	}

	process.push(u);
	taken[u] = 1;
	process.push(v);
	taken[v] = 1;
}



int taken[maxn];
void bfs()
{
	while(!process.empty())
	{
		int par = process.front();
		process.pop();

		for(int i = 0;i<process[par].size();i++)
		{
		
		}
	}
	return;
}

int main()
{
	#ifdef PARTHO
		freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
    	freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
    	int start_time = clock();
    #endif

    	int n,k;

    	cin >> n >> k;
    	input(n,k);


    	
    	
	#ifdef PARTHO
		int end_time = clock();
		printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif

	return 0;
}
