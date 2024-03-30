namespace topological_Sort {
	#define notVisited 0
	#define temporary 1
	#define permanent 2
    const int maxn = 1e5+5;
    int N, v[maxn], mark[maxn], idx;
    vector<int> g[maxn];
 
    bool dfs(int pos){
    	if(mark[pos] == permanent) return true;
    	if(mark[pos] == temporary) return false; // Cycle
        mark[pos] = temporary;
        for(auto &nxt : g[pos]) if(!dfs(nxt)) return false;
        mark[pos] = permanent;
        v[--idx] = pos;
        return true;
    }
    bool Sort(){
        idx = N;
        memset(mark,notVisited,sizeof(mark));
        FOR(i,0,N) sort(g[i].rbegin(),g[i].rend());
        for(int i = N-1; i >= 0; i--) if(!dfs(i)) return false;
        return true;
    }
}
namespace topSort =  topological_Sort; 
using namespace topSort;