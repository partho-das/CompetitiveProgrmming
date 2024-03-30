namespace PRIME {
	//const int Base[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
	const int Base[] = {2,7,61};

	bool Suspect(ull b, ull t, ull u, ull n){
		if(n == b) return 1;
		ll prev = bigMod(b,u,n), curr; 
		while(t--){
			curr = (prev*prev)%n;	
			if(curr == 1 && prev != 1 && prev != n-1) return 0;
			prev = curr;
		}
		return prev == 1;
	}
	bool isPrime(ll t, ll u, ll n){ // Using Miller–Rabin
		for(int b : Base) if(!Suspect(b,t,u,n)) return 0;
		return 1;
	}
	bool isPrime(ll n){
		ll u = n-1;
		int t = 0;	
		while(!(u&1)) t++,u >>= 1;
		return isPrime(t,u,n);
	}
}
