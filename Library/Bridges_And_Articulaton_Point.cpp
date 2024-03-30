// ==============  Bridges Finding  ====================
const int maxn = 1e5+5;
vector<int> g[maxn]; // adjacency list
int N; // Number of nodes in the graph
bool visited[maxn];
int Time; // current time of dfs
int discoverTime[maxn]; // first discovering time of node i
int min_discoverTime[maxn]; // minimum first discovering Time of the nodes of the descendants of node i in the dfs tree
vector<pair<int,int>> bridge; // List of bridge Edges

void dfs(int node, int parent = -1){
    visited[node] = 1;
    discoverTime[node] = min_discoverTime[node] = Time++; // all discovering Time is unique
    for(auto &next : g[node]) if(next != parent){
        if(visited[next]){ // This is a back Edge. If descendants of node "next" is connected to ancestor of current node, then 
            min_discoverTime[node] = min(min_discoverTime[node], discoverTime[next]); // discoverTime[next] <= discoverTime[node];
        }
        else{
            dfs(next,node); 
            min_discoverTime[node] = min(min_discoverTime[node], min_discoverTime[next]); 
            if(discoverTime[node] < min_discoverTime[next]){ // if min_discoverTime[node] < discoverTime[next] then definitely descendants of
                bridge.emplace_back(min(node,next),max(node,next)); // "next" is not connected to ancestor of current node in the dfs tree
            }
        }
    }
}
void Find_Bridge(){
    Time = 0;
    bridge.clear();
    memset(visited, 0, sizeof(visited));
    memset(discoverTime, -1, sizeof(discoverTime));
    memset(min_discoverTime, -1, sizeof(min_discoverTime));
    for(int i = 0; i < N; i++){
        if(!visited[i]){
            dfs(i);
        }
    }
}

// ===================== Articulation Point Finding ========================
const int maxn = 1e5+5;
vector<int> g[maxn]; // adjacency list
int N; // Number of nodes in the graph
bool visited[maxn];
int Time; // current time of dfs
int discoverTime[maxn]; // first discovering time of node i
int min_discoverTime[maxn]; // minimum first discovering Time of the nodes of the descendants of node i in the dfs tree
vector<int> cutPoint; // List of Articulation Points

void dfs(int node, int parent = -1){
    visited[node] = 1;
    discoverTime[node] = min_discoverTime[node] = Time++; // all discovering Time is unique
    int child = 0;
    bool isCutPoint = false;
    for(auto &next : g[node]) if(next != parent){
        if(visited[next]){ // This is a back Edge. If descendants of node "next" is connected to ancestor of current node, then 
            min_discoverTime[node] = min(min_discoverTime[node], discoverTime[next]); // discoverTime[next] <= discoverTime[node];
        }
        else{
            dfs(next,node); 
            min_discoverTime[node] = min(min_discoverTime[node], min_discoverTime[next]); 
            if(discoverTime[node] <= min_discoverTime[next] && ~parent){ // if min_discoverTime[node] < discoverTime[next] then definitely descendants of
                isCutPoint = true; // "next" is not connected to ancestor of current node in the dfs tree
            }
            child++;
        }
    }
    if(isCutPoint || (parent == -1 && child > 1)){ // if current node is root and it has more than one child in dfs tree
        cutPoint.push_back(node); // then it is also a an articulation point
    }
}
void Find_cutPoint(){
    Time = 0;
    cutPoint.clear();
    memset(visited, 0, sizeof(visited));
    memset(discoverTime, -1, sizeof(discoverTime));
    memset(min_discoverTime, -1, sizeof(min_discoverTime));
    for(int i = 0; i < N; i++){
        if(!visited[i]){
            dfs(i);
        }
    }
    for(auto p : cutPoint) cout << p << " "; cout << endl;
}