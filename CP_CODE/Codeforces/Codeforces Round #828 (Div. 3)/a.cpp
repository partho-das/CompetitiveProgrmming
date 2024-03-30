
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
	  #ifdef PARTHO
        freopen("/mnt/Stable/Dropbox/IO/input.txt","r",stdin);
        freopen("/mnt/Stable/Dropbox/IO/coutput.txt","w",stdout);
        int start_time = clock();
    #endif
ll t;
cin>>t;
while(t--){
ll n;
cin>>n;
vector<ll> v(n+1);
vector<ll> s(n+1);

for(ll i=1;i<=n;i++){
	cin>>v[i];
	s[i]=s[i-1]+v[i];
}
map<ll,ll> m;
ll ans=0;
ll maxi=0;
for(ll i=n;i>0;i--){
	m[s[i]]++;
	maxi=max(maxi,m[s[i]]);
	if(v[i]==0){
		ans += maxi;
		m.clear();
		maxi=0;
	}
}
ans+=m[0];
cout<<ans<<endl;



}

}