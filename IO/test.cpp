#include<bits/stdc++.h>

using namespace std;

int main(){

	int n;

	n = 5;
	std::vector<int> v;
	while(n--){
		v.push_back(n);
	}
	for(auto it : v){
		cout << it << endl;
	}
	return 0;
}