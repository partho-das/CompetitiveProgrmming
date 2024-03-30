#include<bits/stdc++.h>

using namespace std ;
#define MAX 100000
#define MAXLG 20

int P[MAXLG][MAX];
int cnt =1, LOGN =1,LEN;
string str ;
int lcp[MAX];
namespace SuffixArray{
    struct entry{
        int ar[2] ;
        int ind ;
    }L[MAX];
    bool com(entry a, entry b ){
        return a.ar[0]==b.ar[0]?a.ar[1]<b.ar[1]?1:0:a.ar[0]<b.ar[0]?1:0 ;
    }
    void init(void){
        memset(lcp,0,sizeof lcp);memset(P,0,sizeof P);memset(L,0,sizeof L);
        LOGN =1, cnt =1 ;
    }
    void build(void){
        for(int i   =  0 ; i< LEN ;i++ ){
            P[0][i]=str[i]-'a';
        }
        for( ; cnt>>1 < LEN ; LOGN++ , cnt<<=1 ){
            for(int i=0; i< LEN ;i++ ){
                L[i].ar[0] =P[LOGN -  1][i];
                L[i].ar[1] =i+ cnt < LEN ? P[LOGN -1 ][i+cnt]: -1 ;
                L[i].ind= i ;
            }
            sort(L, L + LEN , com);
            for(int i=0 ; i< LEN ; i++ ){
                P[LOGN][L[i].ind] = i>0 && L[i-1].ar[0]==L[i].ar[0] && L[i-1].ar[1]==L[i].ar[1]?P[LOGN][L[i-1].ind]:i ;
            }
        }
        LOGN-- ;
    }
    int FIND(int x, int y ){
        int k=LOGN , ret =  0 ;
        for(k; k>= 0 && x  < LEN && y < LEN ; k--){
            if(P[k][x] == P[k][y])
                x += 1<<k , y+= 1<<k , ret += 1<<k ;
        }
        return ret ;
    }
    void LCP(void){
        for(int i=0;i<LEN-1; i++ ){
            lcp[i]=FIND(L[i].ind,L[i+1].ind);
        }
    }
}
int main(void)
{
    cin>>str ;
    LEN = str.size() ;
    SuffixArray::build();
    for(int i=0;i < LEN ; i++ )printf("%d ", P[LOGN][i]);
    puts("") ;
    //SuffixArray::LCP();
    for(int i=0 ; i< LEN -1 ; i++ )
        printf("%d ", lcp[i]);
    puts("");
    SuffixArray::sortedLCP();
    for(int i=0 ;i< LEN - 1;i++)cout<<lcp[i]<<" ";
    puts("");
}
