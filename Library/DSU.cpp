class UnionFind {
private:
    static const int maxn = 1e5+5;
    int n; // totall number of nodes
    int group; // totall disconnected group;
    int sz[maxn]; // size of a network
    int par[maxn]; // parent of a neode
public:
    void Init(int n){
        this->n = group = n;
        for(int i = 0; i < n; i++) par[i] = i, sz[i] = 1;
    }
    int find(int p){             return p == par[p] ? p : par[p] = find(par[p]);} // finds parent of p
    int connected(int p, int q){ return find(p) == find(q);} // checks p and q is connected or not
    int groupCnt(){              return group;} // gives number of disconnected group
    int totall(){                return n;} // gives totall number of nodes in network
    int size(int p){             return sz[ find(p) ];} // gives the size of the group of p
    void merge(int p, int q){ // merges the group of p and q
        int par1 = find(p);
        int par2 = find(q);
        if(par1 == par2) return;
        else            group--;
        if(sz[par1] > sz[par2]) par[par2] = par1, sz[par1] += sz[par2];
        else                    par[par1] = par2, sz[par2] += sz[par1];
    }
}uf;
const int maxn = 3e5+5, K = 3e5; // shift
class UnionFind {
private:
    int n; // totall number of nodes
    int szX[maxn*2]; // size of a network
    int szY[maxn*2]; // size of a network
    int par[maxn*2]; // parent of a neode
    int value[maxn*80];
    int *address[maxn*80]; // need for undo/rollback operation
    int timer;
public:
    void Init(int n){
        timer = 0;
        this->n = n;
        for(int i = 0; i < n; i++) par[i] = i, par[i+K] = i+K, szX[i] = szY[i+K] = 1;
    }
    int find(int p){ return p == par[p] ? p : find(par[p]);} // finds parent of p
    void change(int &from, int to){
        address[timer] = &from;
        value[timer] = from;
        from = to;
        timer++;
    }
    void rollback(){
        timer--;
        *address[timer] = value[timer];
    }
    int currState(){ return timer;}
    void merge(int p, int q){ // merges the group of p and q
        int x = find(p);
        int y = find(q);
        if(x == y) return;

        if(szX[x]+szY[x] < szX[y]+szY[y]) swap(x,y);

        ans -= 1LL*szX[x]*szY[x];
        ans -= 1LL*szX[y]*szY[y];

        change(par[y], x);
        change(szX[x], szX[x]+szX[y]);
        change(szY[x], szY[x]+szY[y]);

        ans += 1LL*szX[x]*szY[x];
    }
}uf;

