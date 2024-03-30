
template<size_t T> constexpr auto fib(){
    if constexpr(T<=1) return 1;
    else return (fib<T-1>()+fib<T-2>())%MOD;
}

template<size_t L> constexpr vi Init(){
    vi v;
    FOR(i,0,L) v.pb(i+1);
    return v;
}
const vi a = Init<500>();

template<size_t T> constexpr auto cal(){
    int a = 1, b = 1, f;
    FOR(i,0,T+1) f = (a+b)%MOD, a = b, b = f;    
    return f;
}
const int f = cal<900000000>();  
