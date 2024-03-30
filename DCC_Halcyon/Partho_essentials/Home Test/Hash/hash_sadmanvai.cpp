#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define base 31
#define type 'a'
#define NUM_OF_HASH 1
#define MAX (int)1e5

ll Hash[NUM_OF_HASH][MAX];
ll power[NUM_OF_HASH][MAX];
ll MOD[] = {1000000007, 1000000009, 998244353, 1000000037,1000000021,1000000003,1000005133};
string str;
int len;

void pre()
{
	for(int i=0;i<NUM_OF_HASH;i++){
	    power[i][0] = 1;
		Hash[i][0] = str[0]-type+1;
		for(int j=1;j<=len;j++) {
			power[i][j] = (power[i][j-1]*base)%MOD[i];
			if(j != len)
			Hash[i][j] = (Hash[i][j-1]*base + str[j]-type+1)%MOD[i];
		}
	}
	return;
}

ll getHash(int i,int j,int k){
    if(!i) return Hash[k][j] % MOD[k];
    return ((Hash[k][j] - (Hash[k][i - 1] * power[k][j - i + 1]) % MOD[k]) + MOD[k] + MOD[k] + MOD[k] + MOD[k] + MOD[k]) % MOD[k];
}

ll cngHash(int pos, char ch, int len, int k){
    return (((Hash[k][pos - 1] * base + ch - type + 1) * power[k][len - pos - 1]) % MOD[k] + getHash(pos + 1, len - 1, k) ) % MOD[k];
}
ll singleHash(string &str, int k){
	ll hashv = str[0] - type + 1;

	for(int i = 1; i < str.size(); i++){
		hashv = (hashv * base + str[i] - type + 1) % MOD[k];
	}
	return hashv;
}


int main()
{

	#ifdef PARTHO
        freopen("/mnt/Stable/Dropbox/IO/input.txt","r",stdin);
        freopen("/mnt/Stable/Dropbox/IO/output.txt","w",stdout);
        int start_time = clock();
    #endif

	cin >> str;
	len = str.size();
	pre();
    cout << getHash(0,len - 1,0) << " "<< singleHash(str, 0);

    //cout << cngHash(3, 'a', len, 0) << endl;
	return 0;
}
