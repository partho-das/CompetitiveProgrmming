#include<bits/stdc++.h>

using namespace std;

const int MAX = 100005;

int sparse[MAX][18];
int par[MAX],L[MAX];
int node;
vector<int>v[MAX];
void build(){
    memset(sparse, -1 , sizeof sparse);

    for(int i=1;i<=node;i++){
        sparse[i][0]=par[i];
    }

    for(int j=1;1<<j <=node ;j++){
        for(int i=1;i<=node;i++){
            if(sparse[i][j-1] !=-1){
                sparse[i][j]=sparse[sparse[i][j-1]][j-1];
            }
        }
    }
}

int query(int p,int q){

//    cout<<p<<" "<<q<<": "<<endl;
    if(L[p] < L[q])swap(p,q);

    int log;
    for(log=1; 1<<log <= L[p] ;log++);
    log--;
    for(int i=log;i>=0; i-- ){
        if(L[p]- (1<<i) >= L[q]){
            p=sparse[p][i];
        }
    }
//    cout<<p<<" "<<q<<endl;
    if(p == q)return p;

    for(int i=log;i>=0; i--){
        if(sparse[p][i] !=-1 && sparse[p][i] != sparse[q][i]){
            p=sparse[p][i],q=sparse[q][i];
        }
    }
    return par[p];
}

void dfs(int curNode,int Par,int Level){

    par[curNode]=Par;
    L[curNode]=Level;

    for(int i=0;i<v[curNode].size() ;i++){
        int V=v[curNode][i];
        if(V == Par)continue;
        dfs(V,curNode,Level+1);
    }
}


int ans_me(int a,int b,int c){
    int ff=query(a,c);
    int ss=query(b,c);
    int tt=query(a,b);
    int label=max(L[ff],L[ss]);
    int ret=L[c]-label +1;
    if( L[tt] > label) ret=ret +  (L[tt] -label);
    return ret;
}

int main(void)
{
    int qry;
    scanf("%d%d",&node,&qry);
    for(int i=2;i<=node;i++){
        int x;
        scanf("%d",&x);
        v[x].push_back(i);
        v[i].push_back(x);
    }
    dfs(1,-1,1);
    build();
    for(int i=1;i<=qry;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        int ff=ans_me(a,b,c);
        int ss=ans_me(a,c,b);
        int tt=ans_me(c,b,a);
        printf("%d\n",max(ff,max(ss,tt)));
    }
    return 0;
}
