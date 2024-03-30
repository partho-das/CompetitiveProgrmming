template<typename T> inline T Extended_Euclid(T a, T b, T &x, T &y){
    T r2 = a, r1 = b;
    T X[2] = {1,0};
    T Y[2] = {0,1};
    T r,q;
    do{
        q = r2/r1, r = r2-r1*q; 
        X[0] = X[0]-X[1]*q;     swap(X[0],X[1]); 
        Y[0] = Y[0]-Y[1]*q;     swap(Y[0],Y[1]); 
        r2 = r;                 swap(r1,r2);
    }
    while(r);
    x = X[0], y = Y[0];
    return r2;
}
template<typename T> inline bool Linear_Diophantine(T A, T B, T C, T &x, T &y){
    if(!A && !B){ x = 1, y = 1; return !C;}
    if(!A){ x = 1, y = C/B;     return C%B==0;}
    if(!B){ x = C/A, y = 1;     return C%A==0;}

    T g = __gcd(A,B);   if(C%g) return 0;

    T a = A/g, b = B/g, c = C/g;
    if(g < 0) a *= -1, b *= -1, c *= -1;
    
    Extended_Euclid(a,b,x,y);
    x *= c, y *= c; // (x1,y1) = (x+kb/g,y-ka/g);
    
    return 1;
}
template<typename T> inline T CountInRange(T a, T b, T c, T x1, T x2, T y1, T y2){
    T x,y;
    if(a < 0) swap(x1,x2), a = -a, x1 = -x1, x2 = -x2;
    if(b < 0) swap(y1,y2), b = -b, y1 = -y1, y2 = -y2;

    bool have_solution = Linear_Diophantine(a,b,c,x,y);
    
    T cnt = 0;
    if(have_solution){
        if(!a && !b) cnt = (!c)*(x2-x1+1)*(y2-y1+1);
        else if(!a)  cnt = (c%b==0 && y1 <= c/b && c/b <= y2)*(x2-x1+1);
        else if(!b)  cnt = (c%a==0 && x1 <= c/a && c/a <= x2)*(y2-y1+1);
        else
        {
            T g = __gcd(a,b);
            double ga = a/g, gb = b/g; 
            double lx = (x1-x)/gb, hx = (x2-x)/gb; 
            double ly = (y-y2)/ga, hy = (y-y1)/ga;  
            T h = min(floor(hx),floor(hy));
            T l = max(ceil(lx),ceil(ly));        

            if(l <= h) cnt = h-l+1;
        }
    }
    return cnt;
}
template<typename T> inline pair<T,T> Chinese_Reminder_Theorem(const vector<T> &m, const vector<T> &r, bool coprime = 0){ // coprime = 1 if mods are pariwise coprime
    int n = m.size();
    T r1 = r[0], m1 = m[0],m2,r2,p,q,mod,g = 1;
    for(int i = 1; i < n; i++){
        m2 = m[i], r2 = r[i];
        if(!coprime){
            g = __gcd(m1,m2);
            if(r1%g != r2%g) return {-1,-1};
        }
        Extended_Euclid(m1/g,m2/g,p,q);
        mod = m1/g*m2; // LCM(m1,m2);
        r1 = ((__int128)r1*(m2/g)%mod*q%mod + (__int128)r2*(m1/g)%mod*p%mod)%mod; // Becarefull about overflow, in case use __int128
        m1 = mod;
    }
    return {(r1+m1)%m1, m1};
}