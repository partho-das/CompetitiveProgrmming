#include<bits/stdc++.h>
using namespace std;


namespace Segment_Tree {
    #define Lidx    (pos<<1)
    #define Ridx    Lidx+1
    #define Left    Lidx,L,mid
    #define Right   Ridx,mid+1,R
    #define State   pos,L,R

    const int maxn = 1e5+5;
    ll tree[maxn*4], lazy[maxn*4], data[maxn];

    void push_down(int pos, int L, int R){
        tree[pos] += (R-L+1)*lazy[pos];
        if(L != R) lazy[Lidx] += lazy[pos], lazy[Ridx] += lazy[pos];    
        lazy[pos] = 0;
    }

    void Build(int pos, int L, int R){
        lazy[pos] = 0;
        if(L == R){
            tree[pos] = 0;
            return;
        }
        int mid = (L+R)>>1;
        Build(Left);
        Build(Right);
        tree[pos] = tree[Lidx] + tree[Ridx];
    }

    void Update(int pos, int L, int R, int l, int r, int value){
        if(lazy[pos]) push_down(State);
        if(r < L || R < l) return;
        if(l<= L && R <=r){
            lazy[pos] = value;
            push_down(State);
            return;
        }
        int mid = (L+R)>>1;
        Update(Left, l,r,value);
        Update(Right,l,r,value);
        tree[pos] = tree[Lidx] + tree[Ridx];
    }

    ll Query(int pos, int L, int R, int l, int r){
        if(lazy[pos]) push_down(State);
        if(r < L || R < l) return 0;
        if(l<= L && R <=r) return tree[pos];

        int mid = (L+R)>>1;
        return Query(Left, l,r) + Query(Right, l,r);
    }

}
using namespace Segment_Tree;


/// 2D Segment Tree
#define MAX 1003

int t[4*MAX][4*MAX];

void build_y ( int vx, int lx, int rx, int vy, int ly, int ry ) {
    if ( ly == ry )
    if ( lx == rx ) t [ vx ] [ vy ] = a [ lx ] [ ly ] ;
    else t [ vx ] [ vy ] = t [ vx * 2 ] [ vy ] + t [ vx * 2 + 1 ] [ vy ] ;
    else {
        int my = ( ly + ry ) / 2 ;
        build_y ( vx, lx, rx, vy * 2 , ly, my ) ;
        build_y ( vx, lx, rx, vy * 2 + 1 , my + 1 , ry ) ;
        t [ vx ] [ vy ] = t [ vx ] [ vy * 2 ] + t [ vx ] [ vy * 2 + 1 ] ;
    }
}

void build_x ( int vx, int lx, int rx ) {
    if ( lx ! = rx ) {
        int mx = ( lx + rx ) / 2 ;
        build_x ( vx * 2 , lx, mx ) ;
        build_x ( vx * 2 + 1 , mx + 1 , rx ) ;
    }
    build_y ( vx, lx, rx, 1 , 0 , m - 1 ) ;
} 

int sum_y ( int vx, int vy, int tly, int try_, int ly, int ry ) {
    if ( ly > ry ) return 0 ;
    if ( ly == tly && try_ == ry ) return t [ vx ] [ vy ] ;
    int tmy = ( tly + try_ ) / 2 ;
    return  sum_y ( vx, vy * 2 , tly, tmy, ly, min ( ry,tmy ) )
        +   sum_y ( vx, vy * 2 + 1 , tmy + 1 , try_, max ( ly,tmy + 1 ) , ry ) ;
}

int sum_x ( int vx, int tlx, int trx, int lx, int rx, int ly, int ry ) {
    if ( lx > rx ) return 0 ;
    if ( lx == tlx && trx == rx ) return sum_y ( vx, 1 , 0 , m - 1 , ly, ry ) ;
    int tmx = ( tlx + trx ) / 2 ;
    return  sum_x ( vx * 2 , tlx, tmx, lx, min ( rx,tmx ) , ly, ry )
        +   sum_x ( vx * 2 + 1 , tmx + 1 , trx, max ( lx,tmx + 1 ) , rx, ly, ry ) ;
}

void update_y ( int vx, int lx, int rx, int vy, int ly, int ry, int x, int y, int new_val ) {
    if ( ly == ry ) {
        if ( lx == rx ) t [ vx ] [ vy ] = new_val ;
        else t [ vx ] [ vy ] = t [ vx * 2 ] [ vy ] + t [ vx * 2 + 1 ] [ vy ] ;
    }
    else {
        int my = ( ly + ry ) / 2 ;
        if ( y <= my ) update_y ( vx, lx, rx, vy * 2 , ly, my, x, y, new_val ) ;
        else update_y ( vx, lx, rx, vy * 2 + 1 , my + 1 , ry, x, y, new_val ) ;
        t [ vx ] [ vy ] = t [ vx ] [ vy * 2 ] + t [ vx ] [ vy * 2 + 1 ] ;
    }
}

void update_x ( int vx, int lx, int rx, int x, int y, int new_val ) {
    if ( lx ! = rx ) {
        int mx = ( lx + rx ) / 2 ;
        if ( x <= mx ) update_x ( vx * 2 , lx, mx, x, y, new_val ) ;
        else update_x ( vx * 2 + 1 , mx + 1 , rx, x, y, new_val ) ;
    }
    update_y ( vx, lx, rx, 1 , 0 , m - 1 , x, y, new_val ) ;
} 

int main(){

    return 0;
}
