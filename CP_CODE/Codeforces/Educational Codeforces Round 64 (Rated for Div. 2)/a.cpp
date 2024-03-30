#include<stdio.h>
int main(){
	freopen("C:\\Users\\parth\\Desktop\\input.txt","r",stdin);
    freopen("C:\\Users\\parth\\Desktop\\output.txt","w",stdout);
    int T,i,N,res;
    scanf("%d",&T);
    for(i=1;i<=T;i++){
        scanf("%d",&N);
        res=N+1;
        printf("%d\n",res);
    }
    return 0;

}