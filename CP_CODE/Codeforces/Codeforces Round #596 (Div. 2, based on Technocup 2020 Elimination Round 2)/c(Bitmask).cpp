#include<algorithm>
#include<cmath>
#include<cstdio.>
using namespace std;

/* Formaing Quiz teams. the sulution for uva 10911 above */

int N,target;

double dist [20][20],memo[1 << 16] ; // 1<<16 = 2^16; note that max n = 8;

double matching(int bitmask){
                                    // we initialize 'memo' with -1 in the main function
    if(memo[bitmask] > -0.5)        // this state has been computed before
        return memo[bitmask];       // simply lookup the memo table
    if(bitmask == target)           // all sutdents are alrady matched 
        return memo[bitmask] = 0;   // the cost is 0
    double ans = 2000000000.0;      // initilize with a learge v alue;
    int p1,p2;
    for(p1 = 0 ; p1 < 2*N ; p1++)
        if(! (bitmask & (1 << p1)))
            break;                  // find the first the bit that is off 
    for(p2 = p1+1;p2< 2* N ;p2++)   // then try to match p1
        if(! (bitmask & (1 << p2))) // with another bit p2 that is also off
        ans = min(ans,dist[p1][p2] + matching( bitmask | (1 << p1 ) | (1 << p2)));
            // pick the minimum;

     return memo[bitmask] = ans;  // store result in a memo table and return
 }

 int main()
 {

     #ifdef PARTHO
       freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
       freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
       // int start_time = clock();
   #endif

    int i,j,caseNo = 1,x[20],y[20];

    while(scanf("%d",&N),N){                // yes, we can do this :) 

        for(i = 0;i < 2* N;i++)
            scanf("%*s%d%d",&x[i],&y[i]);   // %*s skips names

        for(i = 0;i < 2*N - 1; i++)         // buid pairwise distandce table
            for(j = i+1;j< 2 * N; j++)      // have you used 'hypot; before?
                dist[i][j] = dist[j][i] = hypot(x[i] - x[j], y[i]  - y[j] );

                // use DP to solve mi weighted perfect matching on small general graph
            for(i = 0;i < (1 << 16); i++) memo[i] = -1.0;  // set -1 to all cells 
                target = (1 << 2*N ) - 1;
            printf("Case %d: %.2lf\n",caseNo++,matching(0));

 } } // return 0;