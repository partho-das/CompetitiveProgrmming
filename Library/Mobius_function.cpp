
const int maxn = 1e7+3;
char mu[maxn];
void mobius(){
    int i,j;
    mu[1] = 1;
    for(i = 1; i < maxn; i++){
        if(mu[i]){
            for(j = i+i; j < maxn; j += i){
                mu[j] -= mu[i];
            }
        }
    }
}
