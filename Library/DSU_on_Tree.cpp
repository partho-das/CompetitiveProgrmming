

const int maxn = 1e6+8; // maximum number of element
std::vector<int>  g[maxn]; // Adjacency list
char ch[maxn]; // color of the ith node
int sz[maxn]; // size of the ith subtree
int bigChild[maxn]; // index if the ith nodes bigchild/heavychild
int lev[maxn]; // level of the ith node
void getSize(int v, int p, int lv){ // pre-calculates the values of sz, bigChild and lev
    sz[v] = 1, bigChild[v] = -1, lev[v] = lv;
    int mx = -1;
    for(auto u : g[v]) 
        if(u != p){
            getSize(u,v,lv+1);
            sz[v] += sz[u];
            if(mx < sz[u]) mx = sz[u], bigChild[v] = u;
        }
}
vector< pair<int,int> > qry[maxn]; // queries for the ith node
bool big[maxn]; // flag to if ith node is currently a bigChild or not
bool ans[maxn]; // // answer for the ith query
int cnt[26][maxn]; // cnt[i][j] = count of color i at jth level
void add(int v, int p, int x){ // adds x to the all nodes of the subtree v
    cnt[ ch[v]-'a' ][ lev[v] ] += x;
    for(auto u : g[v]) 
        if(u != p && !big[u]) // don't calculate for bigChild as we kept the changes made by this child
            add(u,v,x);
}
void dfs(int v, int p, int keep){ // calculates answer for the node v
    for(auto u : g[v])// 1st calculate for all child except bigChild and don't keep the changes
        if(u != p && u != bigChild[v]) dfs(u,v,0);
    if(bigChild[v] != -1)
        dfs(bigChild[v],v,1), big[ bigChild[v] ] = 1;// calculate for the bigChild and keep the changes
    
    add(v,p,1); // add value 1 to all nodes of the subtree v

    for(auto d : qry[v]){ // value addition/update is node, now calulate the answer for this node
        int odd = 0, even = 0;
        for(int i = 0; i < 26; i++)  cnt[i][d.first]&1 ? odd++ : even++;
        ans[d.second] = (odd <= 1); // store the answer
    }
    if(bigChild[v] != -1) big[ bigChild[v] ] = 0;
    if(keep == 0) add(v,p,-1); // as keep = 0 remove the changes made by this node
}
