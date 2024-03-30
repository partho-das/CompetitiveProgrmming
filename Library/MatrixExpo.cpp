#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

#define sf                  scanf
#define pf                  printf
#define FOR(i, x, y)        for(int i=int(x); i<int(y); i++)
#define CLR(x, y)           memset(x, y, sizeof(x))
#define sc(n)               sf("%d",&n)
#define sc2(a,b)            sf("%d%d",&a,&b)
#define sc3(a,b,c)          sf("%d%d%d",&a,&b,&c)
#define bitCheck(N,in)      ((bool)(N&(1<<(in))))

#define mType  int
#define matrix vector<vector<mType>>

int mod;
inline matrix Identity_Matrix(const int row, const int col){
    matrix I(row,vector<mType>(col,0));
    for(int i = 0; i < row; i++) I[i][i] = 1;
    return I;
}
inline matrix operator *(const matrix &a, const matrix &b){
    int ra = a.size(), ca = a[0].size();
    int rb = b.size(), cb = b[0].size();
    if(ca != rb) return Identity_Matrix(ra,cb);

    __int128 sum;
    matrix res(ra,vector<mType>(cb));
    for(int i = 0; i < ra; i++){
        for(int j = 0; j < cb; j++){
            sum = 0;
            for(int k = 0; k < ca; k++) sum += 1LL*a[i][k]*b[k][j];
            res[i][j] = sum%mod;
        }
    }
    return res;
}
inline matrix operator +(const matrix &a, const matrix &b){
    int ra = a.size(), ca = a[0].size();
    int rb = b.size(), cb = b[0].size();
    if(ra != rb || ca != cb) return Identity_Matrix(ra,rb);

    matrix res(ra,vector<mType>(ca));
    for(int i = 0; i < ra; i++){
        for(int j = 0; j < ca; j++){
            res[i][j] = a[i][j]+b[i][j];
        }
    }
    return res;
}
matrix operator ^(const matrix &base, const long long power){
    if(power == 0) return Identity_Matrix(base.size(),base.size());
    if(power == 1) return base;
    matrix full = base^(power>>1); // half
    full = full*full; // full = half*half
    if(power&1) full = full*base; // if(power is odd)
    return full;
}

int a1,b1,c1,a2,b2,c2,f0,f1,f2,g0,g1,g2;
matrix baseFunction, M[32],I; // I = Identity Matrix

inline void preCalculate(){
    baseFunction = {
        {f2,f1,f0,g2,g1,g0}
    };
    M[0] = {
        {a1, 1, 0,  0, 0, 0},
        {b1, 0, 1,  0, 0, 0},
        { 0, 0, 0, c2, 0, 0},
        { 0, 0, 0, a2, 1, 0},
        { 0, 0, 0, b2, 0, 1},
        {c1, 0, 0,  0, 0, 0}
    };
    FOR(i,1,32) M[i] = M[i-1]*M[i-1];
}
inline void Print(int n){
    if(n < 3){
        pf("%d %d\n", baseFunction[0][2-n]%mod, baseFunction[0][5-n]%mod);
        return;
    }
    n -= 2;
    matrix FG = I;
    FOR(i,0,32) if(bitCheck(n,i)) FG = FG*M[i];

    FG = baseFunction*FG;
    
    pf("%d %d\n", FG[0][0], FG[0][3]);
}

int main(){
    I = Identity_Matrix(6,6);

    int n,q,t,cs = 0; sc(t);
    while(t--){
        sc3(a1,b1,c1);
        sc3(a2,b2,c2);
        sc3(f0,f1,f2);
        sc3(g0,g1,g2);
        sc2(mod,q);
        pf("Case %d:\n", ++cs);
        preCalculate();
        
        while(q--) sc(n), Print(n);
    }
    return 0;
}
