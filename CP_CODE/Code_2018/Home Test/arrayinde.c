#include<stdio.h>

int main()
{
    int n,hi,low,hi1,low1,i=0,midi,midd,key;
    scanf("%d",&n);
    int a[n];

    hi = (n/2);
    low = 0;

    hi1 = hi + 1;
    low1 = n - 1;

    while ( i<n )
    {
        scanf("%d",&a[i++]);
    }
    scanf("%d",&key);

    while ( low<=hi )
    {
        midi = (hi+low)/2;

        if( a[midi] == key )
        {
            printf("value found in inc");
            return 0;

        }
        else if( a[midi]<key)
        {
            low = midi+1;
        }
        else
            hi = midi-1;
    }

    while(low1 <= hi1 )
    {
        midd = (low1 + hi1)/2;
        if(a[midd] == key){
            printf("found in dic");
            return 0;
        }
        else if(a[midd] < key)
            low1 = midd - 1;
        else
            hi1 = midd + 1;
    }

    return 0;
}
