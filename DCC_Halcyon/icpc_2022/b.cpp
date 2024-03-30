#include <bits/stdc++.h>

#define endl '\n'
#define F first
#define S second
#define pb push_back

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

template<typename T>
void scan(vector<T> &v) {for (T &x : v) cin >> x;};

const int N = 1e7 + 2;
int spf[N + 5];
int a[500005], b[500005];

void gen() {
    for (int i = 0; i < N; ++i) {
        spf[i] = i;
    }

    for (int i = 2; i < N; i += 2) {
        spf[i] = 2;
    }

    for (ll i = 3; 1LL * i * i <= 1LL * N; i += 2) {
        if (spf[i] == i) {
            for (ll j = i + i; j <= N; j += i) {
                spf[j] = min((long long)spf[j], i);
            }
        }
    }
}

vector<int> factorize(int n) {
    vector<int> facts;
    while (n != 1) {
        facts.pb(spf[n]);
        n /= spf[n];
    }
    return facts;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

     #ifdef PARTHO
        freopen("/home/partho/Desktop/CODEFORCES/IO/input.txt","r",stdin);
        freopen("/home/partho/Desktop/CODEFORCES/IO/output.txt","w",stdout);
        int start_time = clock();
    #endif

    gen();

    int t;
    cin >> t;

    for (int tc = 1; tc <= t; ++tc) {
        cout << "Case " << tc << ": ";

        int n;
        cin >> n;

        set<int> stA;

        int gcd = 0;

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            
            gcd = __gcd(gcd, a[i]);
            
            for (int const &x : factorize(a[i])) {
                stA.insert(x);
            }
        }

        bool alice = true;
        for (int i = 0; i < n; ++i) {
            cin >> b[i];

            for (int const &x : factorize(b[i])) {
                if (!stA.count(x)) {
                    alice = false;
                }
            }
        }

        cout << (alice ? "Yes " : "No ");

        bool bob = true, big = 0, small = 0;
        for (int i = 0; i < n; ++i) {
            if(b[i] > a[i]) small = 1;
            else if(b[i] < a[i]) big = 1;
        }
        ll temp = 1;
        if(small && big) bob = false;
        else if(small){ 
            for(int i = 0; i < n; i++){
                if( ( b[i] % a[i] != 0 ) || (b[i] / a[i] != b[0] / a[0]) ) bob = false;
            }
            temp = b[0] / a[0];
                if(bob) {
                    for (int const &x : factorize(temp)) {
                        if (gcd % x) {
                            bob = false;
                            break;
                        }
                    }
                }
        }
        else if(big){
            for(int i = 0; i < n; i++){
                if( ( a[i] % b[i] != 0 ) || (a[i] / b[i] != a[0] / b[0]) ) bob = false;
            }

            temp = a[0] / b[0];
            if(gcd % temp) bob = false;
        }

        if(bob) {
            for (int const &x : factorize(temp)) {
                if (gcd % x) {
                    bob = false;
                    break;
                }
            }
        }


        cout << (bob ? "Yes" : "No") << endl;
    }


      #ifdef PARTHO
        int end_time = clock();
        printf("Time = %.4f\n",(end_time-start_time+0.0)/CLOCKS_PER_SEC);
    #endif

    return 0;
}