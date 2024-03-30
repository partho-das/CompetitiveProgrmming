#include<bits/stdc++.h>
using namespace std;

int n = 8;
bool arr[10][10];
bool column[10];
bool    row[10];
int print[1000][10];
int order[1000];
int output[10];
int Case = 0;

bool isValid(int x,int y){
    if(row[x] || column[y]) return 0;
    for(int i = x,j = y; i >= 0 && j >= 0; --i,--j) if(arr[i][j]) return 0;
    for(int i = x,j = y; i <  n && j <  n; ++i,++j) if(arr[i][j]) return 0;
    for(int i = x,j = y; i >= 0 && j <  n; --i,++j) if(arr[i][j]) return 0;
    for(int i = x,j = y; i <  n && j >= 0; ++i,--j) if(arr[i][j]) return 0;
    return 1;
}

void cpy(){
   for(int i = 0;i<8;i++) print[Case][i] = output[i];
   Case++;
}

void solve(){
    for(int i = 0;i<Case;i++){ 
        printf("%2d      ",i+1);
        for(int j = 0;j<n-1;j++) printf("%d ", print[order[i]][j]+1);
        printf("%d\n",print[order[i]][n-1]+1);
    }
}
void BT(int r,int c, int cnt){
    if(cnt >= n) return cpy();
    if(c >= 8){
        c = 0;r++;
        if(r >= 8) return;
    }
    
    if(isValid(r,c)){
        row[r] = column[c] = arr[r][c] = 1;
        output[c] = r;
        BT(r,c+1,cnt+1);
        row[r] = column[c] = arr[r][c] = 0;
    }
    BT(r,c+1,cnt); 
}

bool cmp(const int &a,const int &b)
{   int i = 0;
    while(print[a][i]==print[b][i])
        i++;
        if(print[a][i]<print[b][i] && i < 8)
            return 1;
        else return 0;
}

int main()
{
    #ifdef PARTHO
        freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
        freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
        int start_time = clock();
    #endif
    int test;
    scanf("%d",&test);

    while(test--)
    {
        int x,y;
        Case = 0;
        cin >> x >> y;
        --x,--y;
        row[x] = column[y] = arr[x][y] = 1;
        output[y] = x;
        BT(0,0,1);
        row[x] = column[y] = arr[x][y] = 0;

        for(int i = 0;i<Case;i++)
            order[i] = i;
       sort(order,order+Case,cmp);
        //solve();
    printf("SOLN       COLUMN\n");
    printf(" #      1 2 3 4 5 6 7 8\n\n");
       solve();
       if(test)
        puts("");
   }
       
    
    #ifdef PARTHO
        int end_time = clock();
        printf("Time = %f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif

    return 0;
}
