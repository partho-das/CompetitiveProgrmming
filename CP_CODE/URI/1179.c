#include<stdio.h>

int main()
{
    int n,i,ce = 0,ev = 0,ov = 0,even[15],odd[15],j,k = 0;

    for(i = 0;i<15;i++ ){
        scanf("%d",&n);
        ce++;

        n&1 ? (odd[ov++] = n) : (even[ev++] = n);

        if(ev == 5){
            for(j = 0;j<ev;j++) printf("par[%d] = %d\n",j,even[j]);
            ev = 0;
        }
        else if(ov == 5){
            for(j = 0;j<ov;j++) printf("impar[%d] = %d\n",j,odd[j]);
            ov = 0;
        }
    }

    for(j=0;j<ov;j++) printf("impar[%d] = %d\n",j,odd[j]);
    for(k=0;k<ev;k++) printf("par[%d] = %d\n",k,even[k]);

    return 0;
}
