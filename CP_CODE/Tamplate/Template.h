

//?Number

template<class T> T bigMod(T base, T p, T MOD) {
    if(!p)
        return 1;
    if(p&1)
        return bigMod(base,p-1,MOD)*base%MOD;
    else {
        T h = bigMod(base, p>>1, MOD);
        return h*h%MOD;
    }
}

int gcd(int a, int b) { ///greatest common divisor
    if(!a)
        return b;
    return gcd(b%a,a);
}


const int MOD = 1e9+7;

int expo(int b,int p) {
    //cout << p<<" ";
    if(p == 0)
        return 1;
    else {
        if(p&1)
            return (b*expo(b,p-1))%MOD;
        else {
            int temp = expo(b,p/2)%MOD;
            return (temp*temp)%MOD;
        }
    }
}


bool ckbit(int n,int pos) {
    return (n&1<<pos);
}

void bin(int n) {
    for(int i = (log2(n)); i>=0; i--) {
        cout <<ckbit(n,i);
    }
}

int setbeat(int n,int pos) {
    return (n|1<<pos);
}


// Seive
bool arr[1000000];
vector<int> prime;

void genarete(int n) {
    prime.push_back(2);
    for(int i = 3; i*i<=n; i+=2)
        if(!arr[i])
            for(int j = i*i; j<=n; j+=i<<1)
                arr[j] = 1;

    for(int i = 3; i<=n; i+=2)
        if(!arr[i])
            prime.push_back(i);
}
std::vector<int> primediv[100000];
void dv(int n) {
    for(int i = 0; i<prime.size(); i++) {
        for(int j = prime[i]*2; j<=n ; j+=prime[i]) {
            primediv[j].push_back(prime[i]);
            // printf("2\n");
        }

    }

}


#include <bits/stdc++.h>
using namespace std;

/// prime sieve
bool isPrime[1000010];

void primeSieve(int n) {
    memset(isPrime,0,sizeof(isPrime));
    for(int i=2; i<=n; i++) {
        if(!isPrime[i]) {
            for(int j=i+i; j<=n; j+=i) {
                isPrime[j] = 1;
            }
        }
    }
    for(int i=2; i<=n; i++) {
        if(!isPrime[i])
            printf("%d ",i);
    }
    puts(""); /// this line prints a new line,nothing fancy!
    return;
}

/// divisor sieve
vector<int>divisors[1000010];
void divSieve(int n) {
    for(int i=1; i<=n; i++) {
        for(int j=i; j<=n; j+=i) {
            divisors[j].push_back(i);
        }
    }
    for(int i=1; i<=n; i++) {
        printf("%d : ",i);
        for(auto it : divisors[i]) {
            printf("%d ",it);
        }
        puts("");
    }
    return;
}

/// sum of divisor sieve
int sod[1000010];
void sodSieve(int n) {
    for(int i=1; i<=n; i++) {
        for(int j=i; j<=n; j+=i) {
            sod[j]+=i;
        }
    }
    for(int i=1; i<=n; i++) {
        printf("%d : %d\n",i,sod[i]);
    }
    puts("");
    return;
}
int main() {
    //primeSieve(100);
    //divSieve(20);
    sodSieve(1000000);
    return 0;
}

//NCR

#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long

ll nCr[5000][5000];

ll f(int n,int r) {
    if(n==r or r==0)
        return 1;
    if(nCr[n][r]!=-1)
        return nCr[n][r]%MOD; // this line indicates that we have already calculated the value of f(n,r). So no need to calculate again.
    return nCr[n][r] = (f(n-1,r-1)%MOD+f(n-1,r)%MOD)%MOD;
}

int main() {
    memset(nCr,-1,sizeof(nCr)); //
    cout << f(5,2) << "\n";
    return 0;
}


#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define MOD 1000000007
#define MAX 200005

/// Euler phi
/// 2 3 5 7 11 13 17 19 23
int eulerPhi(int n) { /// O(nlogn)
    int cnt = 0;
    for(int i=1; i<=n; i++) { /// O(n)
        if(__gcd(i,n) == 1)
            cnt++; /// O(logn)
    }
    return cnt;
}
/// given a number from 1 to N. 1<=N<=10^6
/// calculate, phi(N) = n*multiplication(1-(1/pi))
/// 2 3 5 7 11 13 17 19 23
int eulerPhie(int n) { ///o(sqrt(n/logn))
    int value = n;
    /// value = n((p1-1)/p1) * ((p2-1)/p2)

    for(int i=2; i*i<=n; i++) { /// i = 2,3,5,7,11,...,N O(sqrt(n)) --> O(sqrt(n/logn))
        if(n%i==0) {
            value/=i;
            value*=(i-1);
            while(n%i==0) {
                n=n/i;
            }
        }
    }
    if(n>1) {
        value/=n;
        value*=(n-1);
    }
    return value;
}

int ev[1000050];
bool isP[1000050];
///euler totient

void sieve(int n) {
    /// init
    for(int i=1; i<=n; i++) {
        ev[i] = i;
        isP[i] = 0;
    }
    /// sieve
    for(int i=2; i<=n; i++) {
        if(isP[i]==0) { ///isP[2]=0
            ev[i] = i-1; /// ev[2] = 2-1
            for(int j=i+i; j<=n; j+=i) {
                isP[j] = 1;
                ev[j]/=i;
                ev[j]*=(i-1);
            }
        }
    }
}

int main() {
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    sieve(1000005);
    int t,num;
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&num);
        printf("%d\n",ev[num]);
    }
    return 0;
}

// Graph
//BFS
#include<bits/stdc++.h>
using namespace std;

std::vector<int> ve[10000];
void input(int n,int e) {
    for(int i  = 0; i<=n; i++) {
        ve[i].erase(ve[i].begin(),ve[i].begin()+ve[i].size());
    }

    for(int i = 0; i<e; i++) {
        int u,v;
        scanf("%d%d",&u,&v);
        // cout << u << v;
        ve[u].push_back(v);
        ve[v].push_back(u);
    }


    //puts("Printing all ");

    // for(int i = 1;i<=n;i++)
    // {

    //     for(int j = 0;j<ve[i].size();j++)
    //     {
    //         cout << ve[i][j] << " ";
    //     }
    //  puts("");
    // }

}
int level[10000];
int visit[10000];

void bfs(int s) {


    queue<int> process;

    memset(level,0,sizeof level);
    memset(visit,0,sizeof visit);

    while(!process.empty())
        process.pop();

    level[s] = 0;
    visit[s] = 1;
    process.push(s);

    while(!process.empty()) {
        int val = process.front();
        process.pop();
        // cout << val<< endl;

        for(int i = 0; i<ve[val].size(); i++) {
            int pos = ve[val][i];



            if(!visit[pos]) {
                //cout<< pos << " ";
                visit[pos] = 1;
                process.push(pos);
                level[pos] = level[val]+1;
                //cout << level[pos];
            }
        }
        // puts("");
    }


}



int main() {

    int q;

    cin >> q;
    while(q--) {
        int n,e,s;

        cin >> n >> e;

        input(n,e);
        cin >> s;
        bfs(s);


        for(int i = 1; i<=n; i++) {

            if(visit[i]) {
                if(i!=s)
                    cout << level[i]*6<<" ";

            } else
                cout << "-1 ";

        }
        puts("");
//
    }




    return 0;
}

#include<iostream>
#include <queue>
#include <utility>
#include <string.h>
using namespace std;

char str[110][110];
int n,m;
void input() {

    // cout << n << w;
    for (int i = 0; i < n; ++i) {
        cin >> str[i];
        getchar();
    }
    // for (int i = 0; i < n; ++i) {
    //     for(int j = 0; j<m; j++)
    //         cout << str[i][j];
    //     puts("");
    // }
}




int dirx[] = {0,0,+1,-1,    -1,+1,-1,+1};
int diry[] = {+1,-1,0,0,    +1,+1,-1,-1};
int visit[110][110];
int level[110][110];
int mainlevel = 0;
int bfs(int sx,int sy) {



    queue <pair <int, int >> process;

    level[sx][sy] = mainlevel+1;
    mainlevel++;
    visit[sx][sy] = 1;
    process.push(make_pair(sx,sy));

    while(!process.empty()) {
        pair <int, int> now;

        now = process.front();
        process.pop();

        for(int i = 0; i<8; i++) {
            int x,y;
            x = now.first+dirx[i];
            y = now.second+diry[i];


            if(x>=0&&x<n && y>=0&&y<m && !visit[x][y] && str[x][y] == '@') {
                visit[x][y] = 1;
                level[x][y] = level[sx][sy];
                process.push(make_pair(x,y));
            }
        }

    }





    return 0;

}



int main() {



    // freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
    // freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);



    int q;


    for(int k = 1; 1; k++) {
        memset(level, 0, sizeof level);
        memset(visit, 0, sizeof visit);
        cin >> n >> m;
        //cout << m << n;
        if(n==m && m == 0)
            break;
        getchar();

        input();

        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(!visit[i][j] && str[i][j] == '@')
                    bfs(i,j);
            }
        }

        cout << mainlevel << endl;
        mainlevel = 0;




    }




    return 0;
}
