#include <stdio.h>
#include<string.h>

int main()
{
    char arr[100], cnt= 1;


    while(1){
        scanf("%s%*c",arr);

        if(arr[0]=='*')
            break;
        if(!(strcmp(arr,"Hajj")))
            printf("Case %d: Hajj-e-Akbar\n",cnt++);

        else if(!(strcmp(arr,"Umrah")))
            printf("Case %d: Hajj-e-Asghar\n",cnt++);


    }

    return 0;
}
